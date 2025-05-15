#include <iostream>
#include "ConTest.h"
using namespace std;

CON1::CON1() {
    cout<<"***CON1의 생성자***"<<endl;
}

CON1::~CON1() {
    cout<<"***CON1의 소멸자***"<<endl;
}

CON2::CON2() {
    cout<<"***CON2의 생성자***"<<endl;
}

CON2::~CON2() {
    cout<<"***CON2의 소멸자***"<<endl;
}

int main() {
    CON2 *p_TEST = new CON2;

    delete p_TEST;

    return 0;
}
