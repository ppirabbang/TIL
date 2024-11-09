#include <iostream>

using namespace std;

int a,b;
int arr[8] = {0,};
bool visited[8] = {0,};

void dfs(int num, int cnt){
  if(cnt == b){
    for(int i=0; i< b; i++){
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }
  for(int i=num; i<=a; i++){
    if(!visited[i]){
      visited[i] = true;
      arr[cnt] = i;
      dfs(i+1, cnt + 1);
      visited[i] = false;
    }
  }
}

int main(){
  cin >> a >> b;
  dfs(1,0);
}