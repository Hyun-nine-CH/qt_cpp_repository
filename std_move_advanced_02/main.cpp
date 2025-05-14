#include <iostream>
#include <string>

using namespace std;

class MyClass {
public:
    MyClass() {}
    MyClass(string str, int a) : m_str(str), m_ptr(new int(a)) {}
    ~MyClass() {
        cout<<"~MyClass()"<<endl;
        if(m_ptr != nullptr)
            delete m_ptr;
    }
    void print() {
        cout<<"String: "<<m_str<<endl;
        if(m_ptr != nullptr)
            cout<<"Ptr: "<<*m_ptr<<endl<<endl;
        else
            cout<<"Ptr: "<<endl<<endl;
    }
    MyClass& operator=(MyClass& other) {
        cout<<"operater=(MyClass& other)"<<endl;
        m_str=other.m_str;
        m_ptr=new int(*other.m_ptr);
        return *this;
    }
#if 0
    MyClass& operator=(MyClass&& other)=defalult;
#else
    MyClass& operator=(MyClass&& other) {
        cout<<"operator=(MyClass&& other)"<<endl;
        m_str=std::move(other.m_str);
        m_ptr=std::move(other.m_ptr);
        other.m_ptr=nullptr;
        return *this;
    }
#endif
private:
    string m_str="ABC";
    int* m_ptr=nullptr;
};
int main() {
    MyClass A("aaa",10);
    MyClass B;
    MyClass C;

    B = A;
    C = move(A);

    A.print();
    B.print();
    C.print();

    return 0;
}
