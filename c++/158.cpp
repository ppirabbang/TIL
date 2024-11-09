#include <iostream>
#include <list>

using namespace std;

int main(){
  list<int> data1;
  list<int> data2{3, 4, 5};

  data1.push_back(2);
  data1.push_back(7);

  data1.merge(data2); // data1 에 data2를 연결
  // 특징 1. 오름차순으로 자동 정렬
  // 특징 2. 인자로 사용되는 컨테이너가 merge 이후 데이터가 삭제
  // --> data2는 빈 컨테이너가 됨.

  cout << "== List Merge ==" << endl;
  for(list<int>::iterator it = data1.begin(); it != data1.end(); ++it){
    cout << ' ' << *it;
  }
  cout << endl;

  data2 = {3,4,5};
  data1.splice(data1.begin(), data2);
  // data1의 시작 위치에 data2를 삽입

  cout << "==List Splice ==" << endl;
  for(auto it = data1.begin(); it!= data1.end(); ++it){
    cout << ' ' << *it;
  }

  return 0;
}