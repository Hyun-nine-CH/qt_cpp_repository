#include <iostream>

using namespace std;

int f() {
    return 20 + 30;
}

int main()
{
    double d=1.414;
    decltype(f()) decVar1=d;
    decltype(d) decVar2=decVar1;
    decltype((d)) decVar3=decVar2;
    decVar2=3.141592;

    cout<<&decVar1<<endl;
    cout<<&decVar2<<endl;
    cout<<&decVar3<<endl;
    return 0;
}
