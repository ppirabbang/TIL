#include <iostream>
#include <map>
#include <String>

using namespace std;

void Print(const map<int, string> &data){
  cout << "== Print ==" << endl;
  
  for(auto iter = data.begin(); iter != data.end(); ++iter){
    cout << iter->first << " : " << iter->second << ", ";
  } //first 는 key, second 는 value

  cout << endl;
}

int main(){
  map<int, string> data;
  data.insert({0, "첫 번째"});
  data.insert({1, "두 번째"});

  Print(data);

  auto ret = data.insert({1, "세 번쨰"}); //map 에서 키는 중복될 수 없음, insert는 pair 를 리턴, pair 는 서로 다른 두 타입의 값을 관리
  // insert 가 정상적으로 수행되면 마지막 요소를 가리키지만 실패하면 이미 존재하는 key 값의 위치를 반환 

  if(ret.second == true){
    cout << "== 데이터 추가 성공 ==" << endl;
  }
  else{
    cout << "== 데이터 추가 실패 ==" << endl;
  }

  data.at(0) = "수정1";

  Print(data);

  return 0;
}