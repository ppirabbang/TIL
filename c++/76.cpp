#include <iostream>

using namespace std;

void Func1(bool *is_on){ //포인터의 크기로 넘어옴
  cout << "Call by address : " << sizeof(is_on) << endl;
}

void Func2(bool &is_on){ // 주소를 인자로 받으면 호출하는데서 그냥 넘겨줘도 포인터로 받아옴, 이는 변수의 크기와 동일
  cout << "call by reference : " << sizeof(is_on) << endl;
}

int main(){
  bool is_tmp = true;

  Func1(&is_tmp);
  Func2(is_tmp);

  return 0;
}