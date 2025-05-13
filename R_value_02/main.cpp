#include <iostream>

using namespace std;

void print(int &x) {
    cout<<"print(int &x)";
}
void print(const int &x) {
    cout<<"print(const int &x)"<<endl;
}
void print(int &&x) {
    cout<<"print(int &&x)"<<endl;
}
int main() {
    const int& x=3; // <- 임시 객체 아니다.
    print(x); // <- 임시 객체가 아니다.
    print(3); // <- 임시 객체이다.
    return 0;
}

// 레퍼런스는 별명을 붙여줌(이름을 붙여줌) 이동되지 않음, 소유권만 넘겨줌

// 포인터는 주소값을 복사 가능하지만
