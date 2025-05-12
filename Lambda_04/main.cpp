#include <iostream>

using namespace std;

class Chulsoo {
public:
    int count;
};

int main() {
    Chulsoo chulsoo;
    chulsoo.count=1;
    // 반환형을 char로 지정한 람다 함수
    cout<<[=](int steakWeight)mutable->char{cout<<"eatLambda():: 철수는 " \
        <<chulsoo.count++<<"번째"<<steakWeight<<"g 짜리 스테이크를 먹는다"<<endl; return steakWeight;}(67)<<endl;

    // 변환형을 int로 지정한 람다 함수
    cout<<[=](int steakWeight)mutable->int{cout<<"eatLambda():: 철수는 " \
             <<chulsoo.count++<<"번째"<<steakWeight<<"g 짜리 스테이크를 먹는다"<<endl; return steakWeight;}(67)<<endl;

    // 반환형을 지정하지 않았지만, steakWeight를 반환하므로 int
    cout<<[=](int steakWeight)mutable{cout<<"eatLambda():: 철수는 " \
             <<chulsoo.count++<<"번째"<<steakWeight<<"g 짜리 스테이크를 먹는다"<<endl; return steakWeight;}(67)<<endl;
}
