#include <iostream>

using namespace std;

class Person {
public:
    virtual void write() = 0;
    void sleep() {
        cout<<"잔다"<<endl;
    }
};
class Chulsoo : public virtual Person {
public:
    Chulsoo() : Person() {

    }
};
class Younghee : public virtual Person {
public:
    Younghee():Person() {

    }
};
class Youngchul : public Chulsoo, public Younghee {
public:
    Youngchul():Chulsoo(), Younghee() {

    }
};
int main(void) {
    Youngchul youngchul;
    youngchul.write();
    youngchul.sleep();
    return 0;
}
