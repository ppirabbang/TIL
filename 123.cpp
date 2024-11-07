#include <iostream>

using namespace std;

enum TmpEnum {};
enum class TmpEnumClass : int {};

int main(){
  cout << boolalpha; //콘솔에 출력될 결과를 boolean 으로 설정

  cout << "== is_integetal ==" << endl;
  cout << is_integral<TmpEnum>::value << endl;
  cout << is_integral<TmpEnumClass>::value << endl;
  cout << is_integral<signed int>::value << endl;
  cout << is_integral<unsigned int>::value << endl;
  cout << is_integral<double>::value << endl;
  cout << is_integral<bool>::value << endl;

  cout << "== is_enum ==" << endl;
  cout << is_enum<TmpEnum>::value << endl;
  cout << is_enum<TmpEnumClass>::value << endl;
  cout << is_enum<int>::value << endl;

  cout << "== is_signed ==" << endl;
  cout << is_signed<TmpEnum>::value << endl;
  cout << is_signed<signed int>::value << endl;
  cout << is_signed<unsigned int>::value << endl;

  cout << "== is_unsigned ==" << endl;
  cout << is_unsigned<TmpEnumClass>::value << endl;
  cout << is_unsigned<int>::value << endl;
  cout << is_unsigned<unsigned int>::value << endl;

  return 0;
}