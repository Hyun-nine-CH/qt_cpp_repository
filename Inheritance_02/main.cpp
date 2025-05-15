#include <iostream>

using namespace std;

class Person {
private:
    int age;
    char name[50];
public:
    Person(int myage, char* myname) : age(myage) {
        strcpy(name, myname);
    }
    void WhatYourName() const {
        cout<<"My name is "<<name<<endl;
    }
    void HowOldAreYou() const {
        cout<<"I'm "<<age<<" yours old"<<endl;
    }
};

class UnivStudent : public Person {
private:
    char major[50];
public:
    UnivStudent(char* myname, int myage, char* mymajor) : Person(myage, myname) {
        strcpy(major, mymajor);
    }
    void WhoAreYou() const {
        WhatYourName();
        HowOldAreYou();
        cout<<"My major is "<<major<<endl<<endl;
    }
};

int main() {

    Person person1(24, "James");
    person1.WhatYourName();
    person1.HowOldAreYou();

    UnivStudent person2("Tomas",31,"economic");
    person2.WhoAreYou();
    return 0;
}
