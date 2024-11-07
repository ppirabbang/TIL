#include <iostream>
#include <sstream>

using namespace std;

int main(){
  stringstream ss;

  double number1 = 0.0;

  ss << "1.2,2.6,-3.8!4.7=8.9";

  cout << "== string to double ==" << endl;
  while (!ss.eof()){
    ss >> number1;
    ss.ignore(); //처음 데이터를 읽고 다시 처음으로 돌아가 데이터를 읽기 때문에 호출해줘야

    cout << number1 << ", ";
  }

  ss.clear();
  ss.str("");
  ss << "1," << "2" << 3 << " " << 4;

  int number2 = 0;

  cout << endl << "== string to int ==" << endl;
  while(!ss.eof()){
    ss >> number2;
    ss.ignore();
    
    cout << number2 << ", "; 
  }
  return 0;
}