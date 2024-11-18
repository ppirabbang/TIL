#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    bool paper[100][100] = {0};
    int sum = 0;
    int n;
    cin>>n;
    while(n--){
      int x,y;
      cin >> x >> y;
      for(int i=y; i< y+10; i++){
          for(int j = x; j< x+10; j++){
            if(paper[i][j]){
              continue;
            }
            else{
              paper[i][j] = 1;
              sum++;
            }
          }
      }
    }
    cout << sum;
    return 0;
}

//배열을 꼭 int 나 char 같은 것만 생각하지 말고 다양한 배열을 생각하기. 어렵게 생각하지 말고 쉽게 생각.