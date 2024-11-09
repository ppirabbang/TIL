#include <iostream>

using namespace std;

static class Calculator{ // 데이터를 저장하지 않고 결과만 알고 싶을 떄 static 사용
  public:
      int Plus(const int x, const int y) const{
        return x+y;
      }
} calc;

int main(){
  cout << "1 + 2 = " << calc.Plus(1,2) << endl;

  return 0;
}