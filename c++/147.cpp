#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main(){
  typedef tuple<string, int , double> Data;

  Data data1("문자열", 10, 1.2);

  string my_str = "";
  int my_int = 0;

  tie(my_str, my_int, ignore) = data1;
  //tie 함수를 선언, my_str 에는 튜플의 첫번쨰 데이터인 string "문자열" , my_int 에는 두 번째 인자인 int 10 이 저장

  cout << my_str << ", " << my_int << endl;

  return 0;
}