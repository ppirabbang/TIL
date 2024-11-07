#include <iostream>

using namespace std;

enum Status{ //상수 집합을 선언
  normal = 0,
  abnormal,
  disconnect = 100,
  close
}; // 열거형 enum 의 현재 값을 close 선언합니다.
// 각 요소는 이전 요소의 값보다 자동으로 1이 커져서 normal 이 0 이라면 abnoraml 은 1입니다.
// disconnect 값이 100 이기 때문에 close 는 101을 갖습니다.

int main(){
  Status number = close;

  if(number == Status::normal){
      cout << "Status : normal" << endl;
  }
  else if (number == abnormal){
      cout << "Status : abnormal" << endl;
  }
  else if (number == 101){
    cout << "Status : disconnect" << endl;
  }
  else{
    cout << "Status : close" << endl;
  }

  return 0;
}