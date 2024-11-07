#include <iostream>
#include <ctime>

using namespace std;

int main(){
  time_t now = time(NULL); //날짜와 시간을 얻을 수 있는 변수
  tm* ptm = localtime(&now);

  char buffer[64];
  strftime(buffer, 64, "예제 만드는 지금은 %Y년 %m년 %d일, %H시 %M분 %S초입니다.(%p)\n", ptm); //3번째 인자의 문자열을 2번째 인자의 크기만큼 1번째 배열에 할당
  
  cout << buffer;

  return 0;
}