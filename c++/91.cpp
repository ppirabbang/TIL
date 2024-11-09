#include <iostream>

using namespace std;

struct Data1{
  int number;
};

struct Data2{
  Data1 data1;

  int number;
}data2;

int main(){
  Data1 data1 = {}; // 내부 변수를 모두 초기화, int 는 0이 됨
  Data2 data2 {data1, 10}; //data1 이 data1 로 초기화, number 는 10 으로 초기화

  cout << "Data1 number : " << data2.data1.number << endl;
  cout << "Data2 number : " << data2.number << endl;

  return 0;
}