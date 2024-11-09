#include <iostream>
#include <list>

using namespace std;
// list 는 vector 와 기본 구조가 다르기 때문에 at, operator 같은 랜덤 엑세스를 지원하지 않음. list는 이중 구조 리스트로 구현되었으며 삽입, 삭제가 빠르다는 장점이 있음, 그래서 특정 원소에 접근 하려면 반복자를 선언해야함.
void Print(const list<int> &data){
  cout << "== Print ==" << endl;

  for (auto iter = data.begin(); iter != data.end(); ++iter){
    cout << *iter << ", ";
  }

  cout << endl;
}

int main(){
  list<int> data1({1,2,3,2});
  data1.push_back(3);
  data1.sort();

  Print(data1);

  data1.unique(); // 중복 데이터를 삭제, 맨 처음 데이터만 남김

  Print(data1);

  list<int> data2 = {4,5,6};
  data2.merge(data1); // data1 이후에 data2가 합쳐짐.

  Print(data2);

  return 0;
}