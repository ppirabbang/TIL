#include <iostream>
#include <string>

using namespace std;

int main(){
  pair<string, int> data("백제 근초고왕", 13);

  cout << data.first << " " << data.second << "대왕" << endl;
//pair는 정확히 2개만 담을 수 있음, 첫번째 원소는 first 로 접근, 두 번째는 second 로 접근
  return 0;
}