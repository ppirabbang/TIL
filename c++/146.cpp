#include <iostream>
#include <tuple>
#include <string>

using namespace std;

int main(){
  typedef tuple<string, int, double> Data;

  Data data1("문자열", 10, 1.2);
  auto data2 = make_tuple("문자열" , 10, 1.2); // 여러 자료형을 담을 수 있다

  cout << get<0>(data1) << ", " << get<1>(data1) << ", " << get<2>(data1) << endl;
//튜플에 담겨 있는 데이터는 get 을 이용해 가져올 수 있음.
//get 뒤에는 <> 를 이용해 인덱스 번호를 넣고, () 안에는 실제 튜플 객체 이름을 기입.

  return 0;
}