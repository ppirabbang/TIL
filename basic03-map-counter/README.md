# basic03-map-counter
## Defining a map
BPF 맵은 아래와 같은 특별한 SEC(".maps")으로 xdp_prog_kern.c 에 있는 글로벌 구조체를 선언하면서 만들어진다.
```
struct {
	__uint(type, BPF_MAP_TYPE_ARRAY);
	__type(key, __u32);
	__type(value, struct datarec);
	__uint(max_entries, XDP_ACTION_MAX);
} xdp_stats_map SEC(".maps");
```
BPF 맵은 일반적인 키/값 저장소이며, 주어진 맵의 타입과 최대 허용 항목 수 max_entries를 가진다.
여기서는 맵이 생성될 때 max_entries 배열 원소들이 할당받는 간단한 BPF_MAPTYPE_ARRAY에 집중한다.
BPF 맵은 커널 쪽 BPF program 과 user space 양쪽에서 모두 접근 가능하다. 

## libbpf map ELF reloaction
주목할 점은 모든 작업이 bpf 시스템 호출을 통해 이루어진다는 것.
이는 user space program이 bpf 시스템 호출을 여러 번 사용하여 BPF 맵과 프로그램을 각각 생성해야 한다는 의미.

1. 모든 BPF 맵을 로드하고 각 맵에 대한 FD를 저장.
2. 그 다음 ELF relocation table을 사용하여 BPF 프로그램이 특정 맵을 참조하는 모든 위치를 식별
3. 이 참조들은 재작성 되어, BPF 바이트코드 명령이 각 맵에 맞는 FD를 사용하도록 수정

이 작업은 BPF 프로그램 자체가 커널에 로드되기 전에 이루어져야 한다. --> libbpf 라이브러리가 자동으로 처리

## bpf_object to bpf_map
libbpf API는 객체와 이러한 객체들과 함께 작동하는 함수들을 가지고 있다. struct bpf_object는 ELF 객체 자체를 나타낸다.
로드 프로그램(xdp_load_and_stats.c)에 find_map_fd() 라는 함수가 있다.
이 함수는 주어진 이름으로 bpf_map 객체를 찾기 위해 라이브러리 함수 bpf_object__find_map_by_name()을 사용.
bpf_map을 찾은 후, bpf_map__fd()를 통해 맵 파일 디스크립터를 얻는다.
bpf_object__find_map_fd_by_name() 이 두 단계를 하나로 묶은 것.

## Reading map values from user space
맵의 내용은 사용자 공간에서 bpf_map_lookup_elem() 함수를 통해 읽힌다. 
이 함수는 맵 파일 디스크립터를 사용하는 간다한 시스템 콜 래퍼
시스템 콜은 키를 조회하고 값을 사용자가 제공한 값 포인터가 가리키는 메모리 영역에 저장합니다. 호출하는 사용자 공간 프로그램은 반환된 값이 맵에 포함된 데이터 타입을 저장할 수 있을 만큼 충분한 메모리를 할당해야 합니다. 
우리 예제에서는 사용자 공간이 맵 FD를 통해 bpf_map_info 구조체로 정보를 얻는 방법을 보여주며, 이는 시스템 콜 래퍼bpf_obj_get_info_by_fd()를 사용합니다.

예를 들어, xdp_load_and_stats 프로그램은 주기적으로 xdp_stats_map 값을 읽어 통계를 생성합니다.

