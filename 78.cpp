#include <iostream>

using namespace std;

int main(){
  int number1 = 10;
  int number2 = 20;

  int const *ptr1;
  ptr1 = &number1;
  //ptr1 = number1; 가리키는 대상을 바꿀 수는 있으나 대상의 값을 바꿀 수는 없다
  ptr1 = &number2;

  int *const ptr2 = &number1;
  *ptr2 = number2;
  //*ptr2 = &number2; 가리키는 대상을 바꿀 수 없다

  return 0;
}