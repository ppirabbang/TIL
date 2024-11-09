#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
  int N;
  int result = 0;
  stack<int> st;
  cin >> N;
  while(N--){
      string message;
      cin>>message;
      // 1. push
      if(message == "push"){
          int a;
          cin>>a;
          st.push(a);
      }
      
      // 2. push
      if(message == "pop"){
        if(st.size()==0){
          cout << -1 << endl;
        }
        else{
          result = st.top();
          cout << result << endl;
          st.pop();
        }
      }

      // 3. size
      if(message == "size"){
        cout << st.size() << endl;
      }

      // 4. empty
      if(message == "empty"){
        if(st.empty()){
          cout << 1 << endl;
        }
        else{
          cout << 0 << endl;
        }
      }

      // 5. top
      if(message == "top"){
        if(st.empty()){
          cout << -1 << endl;
        }
        else{
          result = st.top();
          cout << result << endl;
        }
      }
  }
}