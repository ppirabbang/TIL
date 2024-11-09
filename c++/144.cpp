#include <iostream>

using namespace std;

constexpr int GetNumber1(){ // constexpr 형태로 정수를 리턴
  return 2;
}
// 진짜 딱 이 수를 필요로 하는 곳에 사용, 타입에 상관없이
constexpr int Getnumber2(int x,int y){
  return x+y;
}

int main(){
  int array1[GetNumber1()]; //진짜 숫자 2를 리턴하니까 arr[2]; 랑 같음
  int array2[Getnumber2(1,2)];

  cout << sizeof(array1) << ", " << sizeof(array2) << endl;

  return 0;
}