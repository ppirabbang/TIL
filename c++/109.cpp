#include <iostream>
#include <vector>

using namespace std;

class TempClass{
  public :
      TempClass(){
        cout << "생성자 호출" << endl;
      };

      ~TempClass(){
        cout << "소멸자 호출" << endl;
      }
};

int main(){
  TempClass *temp_class = new TempClass();

  delete temp_class;
  temp_class = nullptr; // 명시적으로 new 로 힙 할당 했으니까 명시적으로 delete 로 해제하고 널포인터를 가리키게 해야됨. 외울것.

  return 0;
}