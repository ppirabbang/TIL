#include <iostream>
#include <fstream>

using namespace std;

int main(){
  ifstream read;

  read.open("093.txt", ifstream::in); // 열기

  char line = read.get();

  while (read.eof() == false){
    cout << line;

    line = read.get();
  }

  cout << endl;

  read.close();

  return 0;
}