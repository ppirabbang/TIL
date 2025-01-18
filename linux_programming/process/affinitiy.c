#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sched.h>
#include <sys/types.h>

static void print_cpuset(cpu_set_t *mask){
  for(int i = 0; i<4; i++){
    if(CPU_ISSET(i, mask)){
      printf("CPU%d",i);
    }
    printf("\n");
  }
}

int main(int argc, char **argv){
  int cur_cpu;
  cpu_set_t mask;

  if(sched_getaffinity(getpid(), sizeof(cpu_set_t), *mask)){
    perror("sched_getaffinity()\n");
    /*perror는 errno의 값을 기반으로 오류를 출력하므로, 오류 발생 직후 호출해야 정확한 정보를 제공합니다.*/
    return -1;
  }

  print_cpuset(&mask);

  cur_cpu = sched_getcpu();
  printf("run on CPU%d\n",cur_cpu);

  CPU_ZERO(&mask); // mask를 clear
  CPU_SET(cur_cpu ^ 1, &mask); // 서로 동작하는 cpu를 바꿈

  if(sched_setaffinity(getpid(), sizeof(cpu_set_t), &mask)){
    perror("sched_setaffinity(\n)");
    return -1;
  }

  sleep(2);

  cur_cpu = sched_getcpu();
  printf("now, run on CPU%d\n",cur_cpu);

  return 0;
}