#include <iostream>
#include <tuple>

using namespace std;

struct TupleExam{
  TupleExam(tuple<int, string>){
    cout << "Tuple로 인자 전달" << endl;
  }

  TupleExam(int n, string s){
    cout << "piecewis_construct로 인자 전달" << endl;
  }
};

int main(){
  tuple<int, string> data(1,"str");

  pair<TupleExam, TupleExam> data1(data,data); //튜플로 인자를 넘기니까 튜플 인자로 선언된 생성자 실행
  pair<TupleExam, TupleExam> data2(piecewise_construct, data, data); // 똑같이 튜플을 넘기는데 piecewise_construct 를 선언했으니까 튜플로 넘기는게 아니라 튜플 구성 요소인 int, string 로 인자를 전달함. 즉 밑에 생성자 실행
  pair<TupleExam, TupleExam> data3(make_tuple(2,"str"), make_tuple(2, "str"));
  pair<TupleExam, TupleExam> data4(piecewise_construct, make_tuple(2, "str"), make_tuple(2,"str"));
 // 여기도 int 랑 string 을 넘기니까 밑에가 실행.
  return 0;
}