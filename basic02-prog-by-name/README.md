# basic02-pass-by-name
## Using libxdp and libbpf
libbpf API는 기본 시스템 호출 래퍼(libbpf bpf/bpf.h 에 정의됨 )를 제공할 뿐만 아니라, 이 API는 해당 객체 와 이를 처리하는 함수(include bpf/libbpf.h 에 정의됨 )도 제공합니다.
libbpf 객체:
  - struct bpf_object
  - struct bpf_program
  - struct bpf_map
이러한 구조체는 libbpf 내부에서 사용되며, 불특정 객체와 상호 작용하려면 API 함수를 사용해야 합니다

libxdp API는 xdp/libxdp.h 에 정의된 XDP 프로그램을 사용하기 위한 객체와 함수는 물론 AF_XDP 소켓을 사용하기 위한 객체와 함수도 제공
libxdp 객체에 해당하는 C 구조체:
  - struct xdp_program
  - struct xdp_multiprog
  - struct xsk_umem
  - struct xsk_socket

## Creating an XDP program
xdp_loader.c 파일에 있는 xdp_program__create() 함수는 xdp_program object를 생성하는데 사용되며, 이 경우 ELF 파일에서 프로그램을 로딩한다.
구조체 xdp_program_pots의 filename 과 progname을 사용하여 ELF 파일에서 생성하기 원하는 XDP 프로그램을 명시한다.
```
DECLARE_LIBBPF_OPTS(bpf_object_open_opts, opts);
DECLARE_LIBXDP_OPTS(xdp_program_opts, xdp_opts,
        .open_filename = cfg->filename,
        .prog_name = cfg->progname,
        .opts = &opts);
```
ELF 파일에서 XDP 프로그램이 생성되면, ELF 파일의 BPF 프로그램과 맵 전체에 접근할 수 있는 참조를 유지한다.
XDP 프로그램에서 bpf_object를 얻기 위해 함수 xdp_program__bpf_obj(prog)을 사용한다.

# Assignment

## Assignment 1: Setting up your test lab
As this lesson involves loading and selecting an XDP program that simply drops all packets (via action XDP_DROP), you will need to load it on a real interface to observe what is happening. To do this, we establish a test lab environment. In the testenv/ directory you will find a script testenv.sh that helps you setup a test lab based on veth devices and network namespaces.

E.g. run the script like:
```
$ sudo ../testenv/testenv.sh setup --name veth-basic02
Setting up new environment 'veth-basic02'
Setup environment 'veth-basic02' with peer ip fc00:dead:cafe:1::2.
```
This results in the creation of an (outer) interface named: veth-basic02. You can test that the environment network is operational by pinging the peer IPv6 address fc00:dead:cafe:1::2 (as seen in the script output).

The assignment is to manually load the compiled xdp program in the ELF OBJ file xdp_prog_kern.o, using the xdp_loader program in this directory. Observe the available options you can give the xdp_loader via --help. Try to select the program named xdp_drop_func via --progname, and observe via ping that packets gets dropped.

Here are some example commands:
```
sudo ./xdp_loader --help
sudo ./xdp_loader --dev veth-basic02
sudo ./xdp_loader --dev veth-basic02 --unload-all
sudo ./xdp_loader --dev veth-basic02 --progname xdp_drop_func
sudo ./xdp_loader --dev veth-basic02 --progname xdp_pass_func
```
A note about: The test environment and veth packets directions
When you load an XDP program on the interface visible on your host machine, it will operate on all packets arriving to that interface. And since packets that are sent from one interface in a veth pair will arrive at the other end, the packets that your XDP program will see are the ones sent from within the network namespace (netns). This means that when you are testing, you should do the ping from within the network namespace that were created by the script.

You can “enter” the namespace manually (via sudo ip netns exec veth-basic02
  /bin/bash) or via the script like:
```
$ sudo ../testenv/testenv.sh enter --name veth-basic02
# ping fc00:dead:cafe:1::1
```
To make this ping connectivity test easier, the script also has a ping command that pings from within the netns:
```
$ sudo ../testenv/testenv.sh ping --name veth-basic02
```
You should note that, the cool thing about using netns as a testlab is that we can still “enter” the netns even-when XDP is dropping all packets.

## Assignment 2: Add xdp_abort program
Add a new program section “xdp_abort” in xdp_prog_kern.c that uses (returns) the XDP action XDP_ABORTED (and compile via make). 
Load this new program, e.g. similar to above:

sudo ./xdp_loader --dev veth-basic02 --unload-all
sudo ./xdp_loader --dev veth-basic02 --progname xdp_abort_func

과제 2는 xdp_prog_kern.c 에 
```
SEC("xdp")
int  xdp_pass_func(struct xdp_md *ctx)
{
	return XDP_PASS;
}
```
와 같이 
SEC("xdp");
int xdp_abort_func(struct xdp_md *ctx)
{
  return XDP_ABORT;
}
로 수정해서 해당 옵션 수행해주면 된다. 그러면 패킷을 버리는 것과 기능은 같지만 패킷을 추적할 수 있다.
