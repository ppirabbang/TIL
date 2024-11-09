#include <iostream>

using namespace std;

int main(){
  int number1 = 100;
  int number2 = 6;

  if(number1 < number2){
    cout << "number2가 더 큽니다." << endl;
  }
  else if (number1> number2){
    cout << "number1이 더 큽니다." << endl;
  }
  else{
    cout << "number1 과 number2는 같습니다." << endl;
  }

  if(number2 < 7){ // 이런 if 문은 지양함, pc 가 증가하여 성능이 떨어짐. 알고리즘 사용해야 else if 한번 초과해서 사용 안하는거
    if(number2 > 3){
      if (number2 == 4){
        cout << "number2는 4입니다" << endl;
      }
      else if (number2 == 5){
        cout << "number2는 5입니다" << endl;
      }
      else{
        cout << "number2는 6입니다" << endl;
      }
    }
    else{
      if(number2 == 3){
        cout << "number2는 3입니다" << endl;
      }
      else if (number2 == 2){
        cout << "number는 2입니다" << endl;
      }
      else{
        cout << "number2는 1 이하 입니다" << endl;
      }
    }
  }
  return 0;
}