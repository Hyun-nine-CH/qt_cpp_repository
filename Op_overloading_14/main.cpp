#include <iostream>

using namespace std;

class Person {
private:
    char* name;
    int age;
public:
    Person(char* myname, int myage) {
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

    Person& operator=(const Person& ref) {
        delete []name;
        int len=strlen(ref.name)+1;
        name=new char[len];
        strcpy(name, ref.name);
        age=ref.age;
        return *this;
    }
};
int main(void) {
    Person man1("Micheal Jackson", 29);
    Person man2("Adom Eve", 22);
    man2=man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}

/*
Person& operator=(const Person& ref) {
    delete []name;
    int len=strlen(ref.name)+1;
    name=new char[len];
    strcpy(name, ref.name);
    age=ref.age;
    return *this;
} 안죽도록 클래스에 넣어준다.
*/
