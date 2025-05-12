# Assignment 
## Assignment 1 바이트 카운터 추가
BPF 맵은 값 레코드에 사용된 데이터 구조에 대한 정보를 알지 못하며, 단지 크기만 안다.
따라서 사용자 공간과 커널 쪽 BPF 프로그램 양쪽에서 값의 내용과 구조를 동기화 해야 한다.
여기서 사용된 데이터 구조는 sizeof(struct datarec)으로 알 수 있으며, 이는struct datarec가 사용됨을 나타냄.

struct datarec는 common_kern_user.h 에서 다음과 같이 정의
```
/* 맵에 저장되는 데이터 레코드 */
struct datarec{
  __u64 rx_packets;
  __u64 rx_bytes; /*바이트 카운터 추가*/
};
```
## Assignment 1.1 BPF 프로그램 업데이트
커널 쪽 BPF 프로그램인 xdp_prog_kern.c를 업데이트 하는 것임.
패킷의 길이를 알아내려면 BPF 프로그램이 커널에 의해 호출 될 때 전달받는 컨텍스트 변수 *ctx를 알아야 한다.
이 변수는 struct xdp_md 타입이다.
struct xdp_md는 모든 멤버가 __u32 타입으로 정의되어 있지만, 프로그램이 커널에 로드될 때 커널이 이 데이터 구조에 대한 접근을 struct xdp_buff 와 struct xdp_rxq_info로 재매핑한다.
struct xdp_md는 다음과 같다.
```
struct xdp_md {
	// (참고: __u32는 실제 타입이 아님)
	__u32 data;
	__u32 data_end;
	__u32 data_meta;
	/* 아래는 struct xdp_rxq_info를 통해 접근 */
	__u32 ingress_ifindex; /* rxq->dev->ifindex */
	__u32 rx_queue_index;  /* rxq->queue_index */
};
```
컴파일러는 이를 모르니까 필드를 사용하기 전에 void 포인터로 타입 변환을 해야함.
```
void *data_end = (void *)(long)ctx->data_end;
void *data     = (void *)(long)ctx->data;
```

다음은 각 패킷의 바이트 수를 계산하는 것. data_end에서 data를 빼서 패킷 길이를 계산하고 datarec 멤버를 업데이트 해야 한다.
```
__u64 bytes = data_end - data; /* 패킷 길이 계산 */
lock_xadd(&rec->rx_bytes, bytes);
```

## Assignment 1.2 사용자 공간 프로그램 업데이트
- map_collect() : rx_bytes도 수집하도록 수정.
    rec->total.rx_bytes = value.rx_bytes; 추가
    전달받은 datarec 의 값을 전역 datarec에 저장하는 느낌.
- stats-print() : rx_bytes도 출력하도록 수정.
    bytes = rec->total.rx_bytes - prev->total.rx_bytes
    print 문 추가

## Assignment 2 다른 XDP 액션 통계 처리
```
struct stats_record{
  struct record stats[XDP_ACTION_MAX]; /* 여기를 1이 아닌 최대로 저장하도록 수정*/
};
```
stats_print 함수에 for(__u32 key = 0; key < XDP_ACTION_MAX; key++) 추가하고 [1] 로 되어 있는 것 [key]로 수정.
stats_collect도 for문 추가하고 &stats_rec->stats[key] 로 수정

## Assignment 3 CPU별 통계
지금까지 통계 카운터를 증가 시키기 위해 원자적 연산을 사용했지만 메모리 배리어를 삽입하므로 비용이 크다.
이를 피하기 위해 CPU별 저장소에 저장하는 다른 배열 타입을 사용 가능.
구현을 위해 xdp_prog_kern.c 에서 맵 타입을 BPF_MAP_TYPE_PERCPU_ARRAY로 변경.
bpf_obj_get_info_by_fd()를 통해 맵 fd의 정보를 조회

다음 단계는 CPU별 값을 가져와 합산하는 함수를 작성하는 것입니다. xdp_load_and_stats.c에서 이를 구현하세요. 다음 코드를 복사하여 붙여넣고, map_collect() 함수의 스위치-케이스 문에서 호출할 수 있습니다
```
/* BPF_MAP_TYPE_PERCPU_ARRAY */
void map_get_value_percpu_array(int fd, __u32 key, struct datarec *value)
{
	/* CPU별 맵의 경우, 사용자 공간은 가능한 모든 CPU에 대한 값을 가져옴 */
	unsigned int nr_cpus = libbpf_num_possible_cpus();
	struct datarec values[nr_cpus];
	__u64 sum_bytes = 0;
	__u64 sum_pkts = 0;
	int i;

	if ((bpf_map_lookup_elem(fd, &key, values)) != 0) {
		fprintf(stderr,
			"ERR: bpf_map_lookup_elem failed key:0x%X\n", key);
		return;
	}

	/* 각 CPU의 값을 합산 */
	for (i = 0; i < nr_cpus; i++) {
		sum_pkts  += values[i].rx_packets;
		sum_bytes += values[i].rx_bytes;
	}
	value->rx_packets = sum_pkts;
	value->rx_bytes   = sum_bytes;
}
```
