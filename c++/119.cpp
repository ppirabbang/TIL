#include <iostream>
#include <string>

using namespace std;

class Ondal{
  public:
      friend void GetYear(Ondal ondal){
        cout << "이단성 전투 연도 : " << ondal.year_ << endl;
      }

      void SetYear(int year){year_ = year;}

  private:
      int year_;
};

int main(){
  Ondal ondal;
  ondal.SetYear(590); //외부에서 접근이 원래는 불가능

  GetYear(ondal);

  return 0;
}