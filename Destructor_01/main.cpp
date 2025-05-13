#include <iostream>

using namespace std;

class Person {
private:
    char* name;
    int age;
public:
    Person(char *myname, int myage) {
        int len=strlen(myname)+1;
        name=new char[len];
        strcpy(name, myname);
        age=myage;
    }
    void ShowPersonInfo() const {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
    ~Person() {
        delete []name;
        cout<<"called destructor!"<<endl;
    }
};

// main
