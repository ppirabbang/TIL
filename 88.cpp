#include <iostream>
#include <string>

using namespace std;

struct Princess{
  string name;
  string father;
  string birthday = "알 수 없음";
}Goryeo[2];

int main(){
  Princess jungmyung1;
  jungmyung1.name = "정명공주";
  jungmyung1.father = "조선 선조";
  jungmyung1.birthday = "1603년 6월 27일";

  Goryeo[0].name = "선정왕후";
  Goryeo[0].father = "고려 성종";
  Goryeo[1].name = "효정공주";
  Goryeo[1].father = "고려 현종";

  cout << " == 조선 공주 ==" << endl;
  cout << jungmyung1.name << endl;
  cout << jungmyung1.father << endl;
  cout << jungmyung1.birthday << endl;
  cout << " == 고려 공주 ==" << endl;
  cout << Goryeo[0].name << endl;
  cout << Goryeo[0].father << endl;
  cout << Goryeo[0].birthday << endl;
  cout << Goryeo[1].name << endl;
  cout << Goryeo[1].father << endl;
  cout << Goryeo[1].birthday << endl;

  return 0;
}