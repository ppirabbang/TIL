#include <iostream>
#include <ctime>

using namespace std;

int main(){
  time_t start = time(NULL);
  time_t finish = time(NULL);

  int pass_int = 1;

  time(&start); // 이 시점에 start 에 시간 할당

  for(int i=1; i<100000; i++){
    for(int j=1; j<100000; j++){
      pass_int += 1;
    }
  }
  
  time(&finish);

  cout << "1을 100억 번 더하는 시간 : " << difftime(finish,start) << "초\n"; //끝난 시간에서 시작 시간을 뺀 값

  return 0;
}