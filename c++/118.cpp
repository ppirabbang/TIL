#include <iostream>
#include <string>

using namespace std;

class GoodKing;
class BadKing;

class Info{
  friend class GoodKing; //freind 선언을 했기에 GoodKing 이 achieve 설정 가능

  public:
      Info(){};

  private:
      string achieve;
};

class GoodKing : Info{ // friend 선언이 없으면 private 는 접근 불가능
  public:
      GoodKing(){ achieve = "백제 중흥 군주 근초고왕";};
      void Display(){
        cout << achieve << endl;
      }
};

class BadKing : public Info{
  public:
      BadKing(){};
      void Display(){
        //cout << achieve << endl; 에러 상속을 해도 private 접근 권한은 없음
      }
};

int main(){
  GoodKing king1;
  king1.Display();

  BadKing king2;
  king2.Display();

  return 0;
}