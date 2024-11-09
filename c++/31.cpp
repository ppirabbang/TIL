#include <iostream>

using namespace std;

class Temp{
  int no;
  bool is_on;
};

int main(){
  cout << "char 크기 : " << sizeof('p') << endl;
  cout << "int 크기 : " << sizeof(10) << endl;
  cout << "double 크기 : " << sizeof(10.0) << endl;
  cout << "클래스 크기 : " << sizeof(Temp) << endl;
  // 시스템 버스는 4 바이트 단위로 움직이기 때문에 5바이트인 클래스가 8바이트로 찍히는 것. 두번 왔다 갔다 해야 되기 때문에
  return 0;
}