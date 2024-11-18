#include <iostream>

using namespace std;

auto func1 = []() {cout << "Lambda Function" << endl;};
auto func2 = [](int x, int y) -> bool {return x < y;};
// [] 캡처 블록 : 람다 함수에서 참조할 변수 목록
// () 파라미터 : 람다 함수에서 사용할 인자 목록
// {} 구성 소스 : 일반 함수처럼 구성
// -> bool 은 리턴 타입을 의미, 생략 가능

int main(){
  int x = 2;
  auto func3 = [=](int y){ // [=] 유효 영역의 모든 변수에 접근하여 사용할 수 있다는 의미/
    func1();
    cout << "x < y = " << func2(x,y) << endl;
  };

  func3(4);

  auto func4 = [=](int y){return x* x + y * y;};

  cout << "x * x + y * y = " << func4(5) << endl;

  return 0;
}