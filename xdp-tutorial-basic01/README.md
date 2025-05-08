# XDP TUTORIAL Basic 01
# compile code and loading and the XDP hook is main

## Loking into the BPF-ELF object
### llvm-object -S xdp_pass_kern.o

## almost in README.org but i tried Loaing via iproute2 ip, i did sapzil here. 
## i updated pahole, change pahole path, reset CmakeList.txt. All failed.
## also tried github.com/xdp-project/xdp-tutorial/issues/38 but failed.

## so Loading using xdp-loader.
## Loading using xdp-loader
### sudo xdp-loader load -m skb lo xdp_pass_kern.o

### sudo xdp-loader status lo

## Unloading
### sudo ip link set dev lo xdegeneric off



