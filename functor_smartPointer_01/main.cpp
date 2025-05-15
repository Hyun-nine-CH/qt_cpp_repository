#include <iostream>

using namespace std;

/*
class Point {
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}
    friend ostream& operator<<(ostream& os, const Point& pos);

    void* operator new (size_t size) {
        cout<<"operator new : "<<size<<endl;
        void* adr=new char[size];
        return adr;
    }
    void operator delete (void* adr) {
        cout<<"operator delete ()"<<endl;
        delete []adr;
    }
};
*/

class Adder {
public:
    int operator() (const int& n1, const int& n2) {
        return n1+n2;
    }
    double operator() (const double& e1, const double& e2) {
        return e1+e2;
    }
    /*
    Point operator() (const Point& pos1, const Point& pos2) {
        return pos1+pos2;
    }*/
};

int main(void) {
    Adder adder;
    cout<<adder(1,3)<<endl;
    cout<<adder(1.5,3.7)<<endl;
//    cout<<adder(Point(3,4), Point(7,9));
    return 0;
}
