#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int sum = 0;
  int N;
  cin>>N;

  int a = N / 5;
  int b = N % 5;
  if ( b % 3 == 0){
    sum = a + (b / 3);
    cout << sum;
    return 0;
  }

  int a = N / 3;
  int b = N % 3;
  if ( b % 5 == 0){
    sum = a + (b / 5);
    cout << sum;
    return 0;
  }

  cout << -1;
  return 0;
}