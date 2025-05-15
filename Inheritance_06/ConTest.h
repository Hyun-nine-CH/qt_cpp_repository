
#ifndef CONTEST_H
#define CONTEST_H

#include <iostream>

using namespace std;

class CON1 {
public:
    CON1(int c);
    ~CON1(){};
protected:
    int c;
};

class CON2 {
public:
    CON2(const int a);
    ~CON2(){};
protected:
    int a;
};

CON1::CON1(const int c) {
    this->c=c;
    cout<<"*** CON1의생성자***"<<endl;
    cout<<"c="<<c<<endl;
}

CON2::CON2() : CON1(300) {
    cout<<"***CON2의생성자***"<<endl;
    cout<<"c="<<c<<endl;
}

#endif // CONTEST_H
