#include <iostream>

int data=10; // 전역 변수
void Func() {...}
namespace X {
int data=20;
void Func(){...}
}

int main()
{
    using namespace X;
    int data=30; // 지역 변수
    cout<<"data=" <<data<<"\n";
    cout<<"data=" <<X::data<<"\n";
    cout<<"data=" <<::data<<"\n";

    X::Func();
    return 0;
}
