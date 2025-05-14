#include <iostream>
#include <string>

using namespace std;

int main() {
    string name1="allen";
    cout<<"name1: "<<name1<<endl;

    string name2=std::move(name1);
    cout<<"After, name2=std::move(name1)"<<endl;
    cout<<"-> name1: "<<name1<<endl; // <- 소유권 넘겨서 안 나옴 속도 빠름( 메모리 저장 안함 )
    cout<<"-> name2: "<<name2<<endl<<endl;

    // 값은 바로 어셈블러에 박힘, 객체는 오래 걸림

    int zipcode1=90031;
    cout<<"zipcode1:"<<zipcode1<<endl;
    int zipcode2=std::move(zipcode1);
    cout<<"->zipcode1: "<<zipcode1<<endl;
    cout<<"->zipcode2: "<<zipcode2<<endl;
    return 0;
}

