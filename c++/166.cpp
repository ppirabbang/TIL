#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int number = 4;

  vector<int> data{4,1,3,5,2,3,1,7};

  vector<int>::iterator result1 = find_if(data.begin(), data.end(), [number](int i){
    return i > number;
  });
  // 내부 순회하니까 iterator 선언. find_if는 특정 조건에 만족하는 값을 반환하는 함수. 인자로 시작, 끝, 람다 함수가 전달 되는데 number는 변수 4. i 는 iterator 가 순회하는 data 의 값.

  cout << "4보다 큰 첫 번째 정수 : " << *result1 << endl;
  
  //auto 를 쓰면 간소화 가능
  auto result2 = count_if(data.begin(), data.end(), [number](int i){
    return i > number;
  });

  cout << "4보다 큰 정수 개수 : " << result2 << endl;

  return 0;
}