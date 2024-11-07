#include <iostream>
#include <string>

using namespace std;

class TmpClass{
  public:
      TmpClass() : number1(10), number2(20), name("나운 : 문자영왕 이름"){}
      void Print(){
        cout << number1 << ", " << number2 << ", " << number3 << ", " << name << endl;
      }

  private:
      int number1 = 1;
      const int number2 = 2;
      static const int number3 = 3;
      string name = "조다 : 장수왕 아들";
};

int main(){
  TmpClass tc; // 클래스 객체를 선언할 때 TmpClass() 가 생기니까 이전 값들은 무시하고 생길 때 선언한 값들로 초기화
  tc.Print();

  return 0;
}