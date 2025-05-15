
#ifndef CONTEST_H
#define CONTEST_H

#include <iostream>

using namespace std;

class CON1 {
public:
    CON1(const int c);
    ~CON1(){};
protected:
    int c;
};

CON1::CON1(const int c) {
    this->c=c;
    cout<<"*** CON1의생성자***"<<endl;
    cout<<"c="<<c<<endl;
}

#endif // CONTEST_H
