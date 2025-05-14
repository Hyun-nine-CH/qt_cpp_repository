/*
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
*/

// 레퍼런스는 별명을 붙여줌(이름을 붙여줌) 이동되지 않음, 소유권만 넘겨줌

// 포인터는 주소값을 복사 가능하지만

#include <iostream>

using namespace std;

void print(int &x)
{
    cout << "&x : " << x << endl;
}

void print(const int &x)
{
    cout << "const &x : " << x << endl;
}

void print(int &&x)
{
    cout << "&&x : " << x << endl;
}

int main(void)
{
    int a;
    a = 10;
    int &x1 = a;
    const int &x2 = 10;
    int &&x3 = 10;
    int &&x4 = std::move(a);

    print(x1);    // 1
    print(x2);    // 2
    print(x3);    // 1
    print(x4);    // 1
    print(std::move(x4));    // 3
    print(3);     // 3

    return 0;
}

/*
void print(int &x){
    cout << " printf(int &x):" << endl;
}

void print(const int &x){ <- l-value
    cout << " printf(const int &x):"<<endl;
}

void print(int &&x){ <- r-value
    cout << " printf(int &&x):"<<endl;
}

void print(int x){ <- 연산자 오버로딩 자체가 안됨 // 동시 호출이 안됨 (l과 r value 문제가 아니다.)
    cout << " printf(int x):"<<endl;
}
*/
