#include <iostream>
#include <cstdio>
using namespace std;

class Myostream {
public:
    void operator<< (char* str) {
        printf("%s", str);
    }
    void operator<< (char str) {
        printf("%c", str);
    }
    void operator<< (int num) {
        printf("%d", num);
    }
    void operator<< (double e) {
        printf("%g", e);
    }
    void operator<< (Myostream& (*fp)(Myostream &ostm)) {
        fp(*this);
    }
};

Myostream& endl(Myostream &ostm) {
    ostm<<'\n';
    fflush(stdout);
    return ostm;
}
Myostream mycout;
int main(void) {

    mycout<<"Simple String";
    mycout<<endl;
    mycout<<3.14;
    mycout<<endl;
    mycout<<123;
    endl(mycout);
    return 0;
}
