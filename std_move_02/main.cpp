#include <iostream>
#include <string>

using namespace std;

class MyClass {
public:
    MyClass() {}
    MyClass(string str) : m_str(str) {}
    void print() {
        cout<<m_str<<endl;
    }
private:
    string m_str;
};

int main() {
    MyClass A("aaa");
    MyClass B;
    MyClass C;

    B = A;
    C = move(A);

    A.print();
    B.print();
    C.print();

    return 0;
}
