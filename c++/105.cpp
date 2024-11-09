#include <iostream>
#include <string>

using namespace std;

class KingInfo{
  public:
      KingInfo(){
        name_ = "조선 예종 이황";
      };

      string GetName() const{
        return name_;
      }
  private:
      string name_;

};

int main(){
  KingInfo king_info; // 여기서 객체 생성을 할 때 KingInfo() 내용으로 초기화

  cout << king_info.GetName() << endl;

  return 0;
}