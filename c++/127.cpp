#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T> //typename 이랑 같은 의미
class TemplateData{
  public:
      void Add(T arg) {data_.push_back(arg);} //vector 에 삽입
      int Size() {data_.size();}
      void Print(){
        for(int i=0, size=data_.size();i<size;i++){ 
          cout << "data_ : " << data_.at(i) << endl; //vector 에 있는 것들 출력
        }
      }

  private:
      vector<T> data_;
};

int main(){
  TemplateData<int> data_int;
  data_int.Add(1);
  data_int.Add(2);
  data_int.Print();

  TemplateData<string> data_string;
  data_string.Add("Hello");
  data_string.Add("world");
  data_string.Add("!!");
  data_string.Print();

  return 0;
}