#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  const string file_name = "096.txt";

  ofstream file_out;
  file_out.open(file_name, ifstream::out); //쓰기 모드

  file_out << "고구려 유리왕과 황조가" << endl;
  file_out << "사랑의 아픔을 승화한 시" << endl; // 원하는 내용

  file_out.close();

  ifstream file_in;
  file_in.open(file_name, ifstream::in);

  string line;

  while (getline(file_in, line)){
    cout << line << endl;
  }

  file_in.close();
}