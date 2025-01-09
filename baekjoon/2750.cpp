/* 배열을 이용한 이중 for 문 : 시간 복잡도 O(n^2)
#include <iostream>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int N;
  cin >> N;
  int arr[N]={0};
  for(int i=0; i<N; i++){
    cin >> arr[i];
  }

  for(int i = 0; i < N-1; i++){
    for(int j = i+1; j < N; j++){
      if(arr[i]>arr[j]){
        int temp = 0;
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }

  for(int i=0;i<N;i++){
    cout << arr[i] << endl;
  }
}
*/

/* vector 를 이용한 버블 정렬 - 두 개씩 비교해서 제일 작은 것을 앞으로 보내기
#include <iostream>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  int temp = 0;
  cin >> n;
  vector<int> arr(n);
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  for(int i=0; i< n-1; i++){
    for(int j=0; j< n - i -1; j++){
      if(arr[j]>arr[j+1]){
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  for(int i=0; i<n; i++){
    cout << arr[i] << endl;
  }
}*/