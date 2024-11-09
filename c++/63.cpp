#include <iostream>
#include <string>

using namespace std;

int main(){
  string str1 = "10";
  string str2 = "2.456";
  string str3 = "456 문자열";

  int num1 = stoi(str1); //문자열 10을 정수형
  int num2 = stoi(str2); //소수점은 버려짐
  int num3 = stoi(str3); //문자열은 버려지고 출력됨

  cout << num1 << ", " << num2 << ", " << num3 << endl;

  return 0;
}