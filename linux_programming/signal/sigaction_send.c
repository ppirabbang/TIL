#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

/*argv[0] : sigactuon_send
  argv[1] : pid
  argv[2] : payload
*/

int main(int argc, char **argv){
  pid_t pid;
  int payload;
  union sigval value;

  if(argc != 3){
    printf("Usage : %s PID PAYLOAD", argv[0]);
    return -1;
  }

  pid = atoi(argv[1]); //pid 의 원형은 int pid_t 임.
  value.sival_int = atoi(argv[2]); // 페이로드를 전송하기 위해 저장하는 과정

  sigqueue(pid, SIGUSR1, value);
  return 0;
}