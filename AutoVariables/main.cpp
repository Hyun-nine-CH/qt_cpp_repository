#include <iostream>

using namespace std;

int main()
{
    int n=1234;
    double d=1.231;

    auto autoVar1=d;
    auto autoVar2=n;
    auto autoVar3=n+d;
    autoVar3=1.234;

    cout<<autoVar1<<endl;
    cout<<autoVar2<<endl;
    cout<<autoVar3<<endl;

    return 0;
}
