#include <iostream>
using namespace std;

int main() {
    int a = 10;

    // 1. 일반 l-value 참조
    int &ref1 = a;             // ref1은 변수 a의 별명
    ref1 = 20;

    // 2. const 참조 (임시값에도 바인딩 가능)
    const int &ref2 = 10;      // OK: 임시값에 const 참조 가능

    // 3. r-value reference (이동을 위한 참조)
    int &&ref3 = 30;           // OK: 임시값 30을 ref3이 가짐

    cout << "a = " << a << endl;       // 20
    cout << "ref2 = " << ref2 << endl; // 10
    cout << "ref3 = " << ref3 << endl; // 30

    return 0;
}
