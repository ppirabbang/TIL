#include <iostream>

using namespace std;

class Landload{
  public:
      void IamLandload(){cout << "건물주입니다." << endl;}
};

class Tenant{
  public:
      void IamTenant(){cout << "세입자입니다." << endl;}
};

class Nation : public Landload, public Tenant{
  public:
      void who(){
        cout << "저는";

        if(is_landload == true){
          IamLandload();
        }
        else{
          IamTenant();
        }
      }
  public:
      bool is_landload;
};

int main(){
  Nation nation;
  nation.is_landload = true;
  nation.who();

  return 0;
}