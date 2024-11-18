#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> data({10,20,30,40});

  cout << "== for, iterator ==" << endl;

  for(auto i = data.begin(); i !=  data.end(); ++i){
    cout << *i << ", ";
  }

  cout << endl << "== range based for loop ==" << endl;
  
  //begin, end 함수를 보유한 데이터 타입의 시작과 끝을 모두 순회하며, 해당 값을 auto i 에 할당. 자료형과 컨테이너는 : 를 이용해 구분.
  for(const auto i : data){
    cout << i << ", ";
  }

  cout << endl << "== range based for loop ==" << endl;

  for(auto &i : data){
    cout << i + 2 << ", ";
  }

  cout << endl;

  return 0;
}