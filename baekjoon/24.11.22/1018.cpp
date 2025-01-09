#include <iostream>
#include <algorithm>
using namespace std;

string WB[8]= {
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW"
};

string BW[8] = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB"
};

string board[50];

int cntWB(int x, int y){
  int cnt = 0;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(board[x+i][y+j] != WB[i][j]){
        cnt++;
      }
    }
  }
  return cnt;
}

int cntBW(int x, int y){
  int cnt = 0;
  for(int i=0; i<8; i++){
    for(int j=0; j<8; j++){
      if(board[x+i][y+j] != BW[i][j]){
        cnt ++;
      }
    }
  }
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m;
  cin >> n >> m;
  cin.ignore();

  for(int i=0; i<n; i++){
    getline(cin,board[i]);
  }

  int minval = 65;

  for(int i=0; i+8<=n; i++){
    for(int j=0; j+8<=m; j++){
      int tmp = min(cntWB(i,j), cntBW(i,j));
      if(tmp < minval){
        minval = tmp;
      }
    }
  }
  cout << minval;
}

/*
내가 못풀었던 부분 
: 시작이 W 면 옆에만 고려해야 되나? 밑에는?
  그러면 옆에만 신경써주면 밑에는 B로 시작될텐데 그걸 8번 다?
  색종이 겹치는 넓이 구하는 것에서 얻었던 것 처럼 결국 한칸 씩 따지는 문제였다.
*/
