#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> data({1,2,3});

  // 반복자는 컨테이너의 위치를 가맄티는 것으로 포인터와 비슷
  // * : 현재 위치  ++ : 다음 위치  -- : 이전 위치 
  // ==, != 같은 위치인지 비교, = 반복자 설정
  for(vector<int>::iterator iter = data.begin();iter != data.end(); ++iter){ //. 후위 증가가 이전 객체를 참조하기 때문에 더 빠르다, 전위 증가는 새로운 객체를 만들어
    cout << *iter << ", ";
  }

  for(auto iter = data.cbegin(); iter != data.cend(); ++iter)
  //const end 의미로 반복자를 통해 값을 수정할 수 없도록 설정
  {
    cout << *iter << ", ";
  }

  for(auto iter = data.rbegin(); iter != data.rend(); ++iter)
  //반복자 시작 위치를 끝에서 부터 할 수 있는 선언,, 결과는 3 2 1
  {
    cout << *iter << ", ";
  }
 
  data.clear();

  return 0;
}