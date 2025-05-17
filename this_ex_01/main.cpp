#include <iostream>

using namespace std;

class X{
protected:
    int m_data;
public:
    bool IsEquivalent(const X& object);
    bool IsSame(const X& object);
    void Set(int data) { // 추가
        m_data = data;
    }
};

bool X::IsEquivalent(const X& object) {
    return (m_data==object.m_data);
}

bool X::IsSame(const X& object) {
    return (this==&object);
}

int main() {
    X obj1;
    obj1.Set(100); // 가동

    X obj2 = obj1;
    if(obj1.IsSame(obj2))
        cout<<"obj1과 obj2는 동일한 객체입니다.\n";
    else
        cout<<"obj1과 obj2는 서로 다른 객체입니다.\n";

    X& obj3=obj1;
    if(obj1.IsSame(obj3))
        cout<<"obj1과 obj3는 동일한 객체입니다.\n";
    else
        cout<<"obj1과 obj3는 서로 다른 객체입니다.\n";
    return 0;
}
