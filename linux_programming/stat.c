#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char **argv){
  struct stat statbuf;

  if(argc < 2){
    printf("Usage : %s filename\n", argv[0]);
    /*stat filename 이라고 명령어를 입력해야 되는데 stat 만 입력했으므로 stat filenmae 형식으로 쓰라고 알려주는 구문*/
    return -1;
  }

  if(stat(argv[1], &statbuf)){
    /*filename 에 해당하는 stat의 정보를 statbuf 변수에 저장*/
    printf("stat() fail\n");
    return -1;
  }

  printf("filename : %s\n", argv[1]);
  printf("size : %ld\n", statbuf.st_size);
  /*statbuf 에 저장되어 있는 filename 의 stat의 size 를 출력*/
  
  if(S_ISDIR(statbuf.st_mode)){
    printf("it is directory\n");
  }
  else if(S_ISREG(statbuf.st_mode)){
    printf("it is regular file\n");
  }
  else{
    printf("???\n");
  }
  /*statbuf 의 파일 타입과 종류에 따라 출력하는 구문이 다르도록 설정*/

  return 0;
}