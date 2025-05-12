#include <iostream>

using namespace std;

class Chulsoo {
public:
    int count;
};

int main()
{
    Chulsoo chulsoo;
    chulsoo.count=1;
    for(int i=0; i<10; i++) {
        [=](int steakWeight)mutable{cout<<"eatLambda()::철수는"<<chulsoo.count++<<"번째"<<steakWeight<<"g짜리 스테이크를 먹는다"<<endl;}(1000);
    }
    cout<<chulsoo.count;
    return 0;
}
