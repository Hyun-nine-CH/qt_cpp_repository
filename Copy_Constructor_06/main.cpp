#include <iostream>

using namespace std;

class Temporary {
private:
    int num;
public:
    Temporary(int n) : num(n) {
        cout<<"create obj: "<<num<<endl;
    }
    ~Temporary() { // <- "~"소멸자 함수의 형식
        cout<<"destroy obj: "<<num<<endl;
    }
    void ShowTempInfo() {
        cout<<"My num is "<<num<<endl;
    }
};

int main(void) {
    Temporary(100);
    cout<<"********* after make!"<<endl<<endl;

    Temporary(200).ShowTempInfo();
    cout<<"************ after make!"<<endl<<endl;

    const Temporary &ref=Temporary(300);
    cout<<"********* end of main!"<<endl<<endl;
    return 0;
}
