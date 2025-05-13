#include <iostream>

using namespace std;

class SoSimple {
private:
    int num;
public:
    SoSimple(int n) : num(n) {}
    SoSimple(const SoSimple& copy) : num(copy.num) {
        cout<<"Called SoSimple(const SoSimple& copy)"<<endl;
    }
    SoSimple& AddNum(int n) {
        num+=n;
        return *this;
    }
    void ShowData() {
        cout<<"num: "<<num<<endl;
    }
};

SoSimple SimpleFuncObj(SoSimple) {
//SoSimple SimpleFuncObj(SoSimple ob) { <- unused parameter ob, return 또는 call by value 하면 복사 생성자가 생성됨
    cout<<"return 이전"<<endl;
    return 0;
}

int main(void) {
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();
    return 0;
}
