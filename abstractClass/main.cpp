#include <iostream>
#include <string>
using namespace std;

class AbstractClass {
public:
    virtual string SampleFunction()=0;
};

class TestClass : public AbstractClass {
public:
    string SampleFunction() {
        return "SampleFunction";
    }
};

int main()
{
//    AbstractClass obj1; // <- 추상 클래스는 객체 생성 불가
    TestClass obj1;
    cout <<obj1.SampleFunction()<< endl;
    return 0;
}
