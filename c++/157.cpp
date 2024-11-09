#include <iostream>
#include <list>

using namespace std;

void Print(const list<int> &data){
  cout << "== Print ==" << endl;

  for(auto iter = data.begin(); iter != data.end(); ++iter){
    cout << *iter << ", ";
  }

  cout << endl;
}

bool IsOdd(int arg){
  return arg % 2 == 0 ? 0 : 1;
}

int main(){
  list<int> data1({1,2,4,2,7,10,13,14});

  data1.remove(2); // list 중 2는 모두 삭제
  data1.remove_if(IsOdd); // remove_if 로 삭제에 조건을 줄 수 있음.

  Print(data1);

  data1.reverse(); //역순으로 배치

  Print(data1);

  return 0;
}