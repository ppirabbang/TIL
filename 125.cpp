#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2>
string TmpFunc(T1 x, T2 y){
  conditional<is_same<T1,T2>::value,int,double>::type type1;
  //첫번째 인자에 true 가 할당되면 int, false 가 할당되면 double 이 type1 의 자료형이 된다.
  return typeid(type1).name();
}

int main(){
  string type = TmpFunc(1,22.3); //int 와 double 을 넘기기 때문에 conditional 에서 false 를 받아 type1 의 자료형은 double

  if(type == "double"){
    cout << "double 자료형입니다." << endl;
  }
  else{
    cout << "double 자료형이 아닙니다." << endl;
  }

  return 0;
}