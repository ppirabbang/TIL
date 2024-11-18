#include <iostream>

using namespace std;

int main(){
  int row,column = 0;
  cin >> row >> column;
  int a[row][column] = {0};
  int b[row][column] = {0};

  for(int i = 0; i < row; i ++){
    for(int j = 0; j< column;j++){
        cin >> a[i][j];
    }
  }

  for(int i = 0; i < row; i ++){
    for(int j = 0; j< column;j++){
        cin >> b[i][j];
    }
  }

  for(int i = 0; i < row; i ++){
    for(int j = 0; j< column;j++){
        cout << a[i][j] + b[i][j] << ' ';
    }
    cout << endl;
  }
}