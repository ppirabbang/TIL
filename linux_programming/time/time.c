#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/time.h>

static void print_cur_time(void){
  time_t now;
  struct tm *now_tm;

  now = time(NULL);
  printf("current : %ld ", now);

  now_tm = localtime(&now);
  if(!now_tm){
    printf("localtime() fail\n");
  }

  printf("%d/%d/%d %d-%d-%d\n", now_tm -> tm_year + 1900, 
  now_tm -> tm_mon + 1, 
  now_tm -> tm_mday,
  now_tm -> tm_hour,
  now_tm -> tm_min,
  now_tm -> tm_sec );
}

static void sigalarm_handler(int signum){
  printf("got SIGALRM\n");
  print_cur_time();
}

int main(int argc, char **argv){
  struct itimerval ival;

  signal(SIGALRM, sigalarm_handler);

  print_cur_time();

/*
struct timeval {
    time_t tv_sec;      // 초 (seconds)
    suseconds_t tv_usec; // 마이크로초 (microseconds)
};

struct itimerval{
	struct timeval it_interval; // 인터벌 타임아웃 값, 반복하고 싶은 사이클에 설정
	struct timeval it_value; //초기 타임아웃 값
};
*/
  ival.it_value.tv_sec = 5;
  ival.it_value.tv_usec = 0;
  ival.it_interval.tv_sec = 1;
  ival.it_interval.tv_usec = 0;

  if(setitimer(ITIMER_REAL, &ival, NULL) != 0){
    printf("setitimer() error\n");
    return -1;
  }
  
  while(1){
    sleep(1);
  }

  return 0;
}