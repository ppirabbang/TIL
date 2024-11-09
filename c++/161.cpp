#include <iostream>
#include <map>
#include <string>

using namespace std;

void Print(const map<int, string> &data){
  cout << "== Print ==" << endl;

  for(auto iter = data.begin(); iter != data.end(); ++iter){
    cout << iter->first << " : " << iter->second << ", ";
  }
  cout << endl;
}

int main(){
  map<int,string> data;
  data.insert({5, "test1"});
  data.insert({3, "test2"});
  data.insert({11, "test3"});

  data[3] = "test 수정"; // 키 값 3을 의미 키값을 통해 value 수정 가능

  auto result = data.find(11); //키 값 입력

  if(result != data.end()){ // 순회하므로 찾지 못하면 마지막 인자를 반환, 마지막 인자를 반환했으면 없다는 뜻
    cout << "== 검색 성공 : " << result->first << ", " <<result -> second << endl;
  }

  else{
    cout << "== 검색 실패!! ==" << endl;
  }

  data.erase(5); // 키 값 5 를 삭제

  Print(data);

  return 0;
}