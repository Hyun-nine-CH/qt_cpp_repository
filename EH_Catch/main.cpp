#include <iostream>

using namespace std;

void inputName(char* name) {
    cout<<"이름을 입력하세요:";
    cin>>name;
    if(strlen(name)<=2)
        throw name;
}

int inputAge() {
    int age;
    cout<<"나이를 입력하세요:";
    cin>>age;
    if(age<1)
        throw age;
    return age;
}

int main() {
    char name[512];
    int age;

    try {
        inputName(name);
        age=inputAge();

        cout<<"저의 이름은"<<name<<"입니다."<<endl;
        cout<<"저의 나이는"<<age<<"입니다."<<endl;
    }
    catch (char*e) {
        cout<<"예외 발생, 잘못된 이름 입력:"<<e<<"\n";
    }
    catch (char*e) {
        cout<<"예외 발생, 잘못된 나이 입력:"<<e<<"\n";
    }

    return 0;
}
