#include <iostream>

using namespace std;
int main(){
  int a[9][9] = {0};

  for(int i =0; i<9; i++){
    for(int j=0; j<9; j++){
      cin >> a[i][j];
    }
  }
  
  int max = a[0][0];
  int b=0 ,c = 0; // 초기화는 따로따로 해주자

  for(int i =0; i<9; i++){
    for(int j=0; j<9; j++){
      if(a[i][j] > max){
        max = a[i][j];
        b = i;
        c = j;
      }
    }
  }
  cout << max << endl;
  cout << (b+1) << ' ' << (c+1);
}
