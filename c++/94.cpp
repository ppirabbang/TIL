#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
  ifstream file1;
  file1.open("093.txt", ifstream::in);

  string line;

  while(getline(file1, line)){
    cout << line << endl;
  }
  file1.close();

  return 0;
}