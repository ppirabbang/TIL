#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main(){
  tuple<int> data1(1); //4
  tuple<int, double> data2(1, 2.3); // 16
  tuple<int, double, char> data3(1, 2.3, 'a'); //24 가장 큰 데이터 타입 기준

  cout << sizeof(data1) << ", " << sizeof(data2) << ", " << sizeof(data3) << endl;

  return 0;
}