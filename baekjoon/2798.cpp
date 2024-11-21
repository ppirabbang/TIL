#include <iostream>

using namespace std;

int main(){
  int n,m;
  int max = 0;
  cin >> n >> m;
  int arr[n] = {0};
  for(int i =0; i<n; i++){
    cin >> arr[i];
  }
  for(int i=0; i<n ; i++){
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        if(m > arr[i] + arr[j] + arr[k] && max < arr[i] + arr[j] + arr[k]){
            max = arr[i] + arr[j] + arr[k];
        }
      }
    }
  }
  cout << max << endl;
}