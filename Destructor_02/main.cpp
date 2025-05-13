#include <iostream>
#include <string>

using namespace std;

class Chulsoo {
private:
    char* name;
public:
    Chulsoo(const char* name) {
        this-> name=new char[strlen(name)+1];
        //strcpy(this->name, strlen(name)+1, name);
        strncpy(this->name, name, strlen(name)+1);
        cout<<"Chulsoo::Chulsoo(name) 생성자 완료"<<endl;
    }
    Chulsoo() {
        cout<<"Chulsoo::Chulsoo() 생성자 완료"<<endl;
    }
    void introduce();
    ~Chulsoo() {
        delete[] name;
        cout<<"Chulsoo::~Chulsoo() 소멸자 완료"<<endl;
    }
};

int main(void) {
#if 1
    const char person[]="Chulsoo";
    Chulsoo chulsoo(person);
#else
    Chulsoo chulsoo("철수");
#endif
    chulsoo.introduce();
    return 0;
}

void Chulsoo::introduce() {
    cout<<"이름: "<<name<<endl;
}
