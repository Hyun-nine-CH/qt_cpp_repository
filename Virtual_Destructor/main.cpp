#include <iostream>

using namespace std;

class First {
public:
    void MyFunc() {
        cout<<"FirstFunc"<<endl;
    }
    virtual ~First() {
        cout<<"FirstFunc de"<<endl;
    }
};
class Second: public First {
public:
    void MyFunc() {
        cout<<"SecondFunc"<<endl;
    }
    virtual ~Second() {
        cout<<"SecondFunc de"<<endl;
    }
};
class Third: public Second {
public:
    void MyFunc() {
        cout<<"ThirdFunc"<<endl;
    }
    virtual ~Third() {
        cout<<"ThirdFunc de"<<endl;
    }
};
int main(void) {
    Third* tptr=new Third();
    Second* sptr=tptr;
    First*fptr=sptr;

    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();
    delete tptr;
    return 0;
}
