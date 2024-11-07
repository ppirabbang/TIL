#include <string>
#include <iostream>

using namespace std;

int main(){
  const string kMyJob = "developer"; // c 의 define 과 동일

  string question = "who are you : ";
  string answer = "my job is : ";

  cout << question << kMyJob << endl;
  cout << answer << kMyJob << endl;

  return 0;
}