#include <iostream>
#include <string>

using namespace std;

void Type1(string msg, int no, double value){
  cout << msg << ", 에러 번호" << no << ", 오류값 " << value << endl;
}

void Type2(int no, double value){
  cout << no << ", 오류값 " << value << endl;
}

//자료형이 정해지지 않아도 선언할 수 있도록 하는 것.
template <typename... T> //인자의 개수가 정해지지 않았다는 의미
void PrintLog(T... arg0){ //들어오는 인자를 모두
  Type1(arg0...);//Type 1로 보냄
}

int main(){
  PrintLog<string, int, double>("Warning", 100, 22.5);

  return 0;
}