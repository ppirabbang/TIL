#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

void sigterm_handler(int signum){
  printf("got sigterm\n");
}

int main(int argc, char **argv){
  sigset_t set;

  sigemptyset(&set); //set 초기화
  sigaddset(&set, SIGINT); // set에 SIGINT 추가
  sigprcomask(SIG_SETMASK, &set, NULL); // set을 block list로 등록하여 block list에 있는 명령어들은 무시하겠다.

  signal(SIGTERM, sigterm_handler); //SIGTERM 을 받으면 sigterm_handler 를 실행시켜라
  printf("start of while(1)\n");
  while(1){
    sleep(1);
  }
  return 0;
}
// 해당 프로그램은 killall -KILL or -STOP signal 로 종료해야 한다.