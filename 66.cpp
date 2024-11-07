#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  string str = "gfedcba";

  reverse(str.begin(), str.end()); // 시작 위치와 마지막 위치

  cout << str << endl;

  return 0;
}