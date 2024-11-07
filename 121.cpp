#include <iostream>

using namespace std;

class Base{
  public:
      void Display() {cout << "고려 16대왕 예종" << endl;}
};

class Derived : Base{
  public:
      void Display(){cout << "고려 17대왕 인종" << endl;}
};

int main(){
  Derived child;
  child.Display(); //오버로아딩은 부모 클래스를 자식 클래스에서 다시 정의 하는것. 오버라이딩을 하면 부모 클래스의 내용은 사라짐

  return 0;
}