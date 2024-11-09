#include <iostream>

using namespace std;

class Landload{
  public:
      void IamLandload() {cout<< "건물주입니다." << endl;}
};

class MaleMonkey{
  public:
      void Favorite() {cout << "Favorite : Female Monkey" << endl;}
};

class Nation : public Landload{
  public:
       void who(){
        cout << "안녕하세요. ";
        IamLandload();
       }
};

int main(){
  Nation nation;
  nation.who();

  return 0;
}