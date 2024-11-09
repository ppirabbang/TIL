#include <iostream> // c++ 기본 제공 라이브러리
#include <vector>   // 사용자가 만든 파일

using namespace std;

int main()
{
  vector<int> exam;
  exam.push_back(10);
  exam.push_back(20);
  exam.push_back(30);

  for (int i = 0, size = exam.size(); i < size; i++){
    cout << "벡터 값 : " << exam.at(i) << endl;
  }

  return 0;
}