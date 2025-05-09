#include <iostream>
using namespace std;

int TestFunc1(int a);
int main() {
    int b=200;
    cout<<"b= "<<b<<endl;
    TestFunc1(b);
    cout<<"b= "<<b<<endl;
    TestFunc1(999);

    return 0;
}

int TestFunc1(int a) {
    cout<<"a= "<<a<<endl;
    a=100;
    cout<<"a= "<<a<<endl;
    return 0;
}
