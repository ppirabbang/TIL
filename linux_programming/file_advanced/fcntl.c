#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char **argv){
  int ret;
  int flag;
  char buf[128];
  memset(buf, 0, sizeof(buf));
  ret = read(STDIN_FILENO, buf, sizeof(buf));
  printf("read() [%s] - %d bytes\n", buf, ret);

  flag = fcntl(STDIN_FILENO, F_GETFL);
  if (flag == -1){
    printf("fcntl(F_GETFL) fail\n");
    return -1;
  }

  ret = fcntl(STDIN_FILENO, F_SETFL, flag | O_NONBLOCK);
  if (ret == -1){
    printf("rcntl(F_SETFL) fail\n");
    return -1;
  }

  printf("trying to read...\n");
  memset(buf, 0, sizeof(buf));
  ret = read(STDIN_FILENO, buf, sizeof(buf));
  printf("read() [%s] - %d bytes\n", buf, ret);
  if(ret == -1){
    printf("errno = %d, %s\n", errno, strerror(errno));
  }

  return 0;
}