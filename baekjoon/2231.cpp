#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  int a = 0;
  cin >> a;
  for(int i = 1; i<a; i++){
      int tmp = i;
      int sum = i;

      while (tmp != 0){
        sum += tmp%10;
        tmp /= 10;
      }
      if(sum == a){
        cout << i << endl;
        return 0;
      }
  }
  cout << 0 << endl;
  return 0;
}