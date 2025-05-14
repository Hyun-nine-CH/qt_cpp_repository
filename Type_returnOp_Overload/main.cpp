#include <iostream>

using namespace std;

class Number {
private:
    int num;
public:
    Number(int n=0) : num(n) {
        cout<<"Number(int n=0)"<<endl;
    }
    Number& operator=(const Number& ref) {
        cout<<"operator=()"<<endl;
        num=ref.num;
        return *this;
    }
/*
    Number& operator+(int n) {
        cout<<"operator+()"<<endl;
        num+=n;
        return *this;
    }
*/
    operator int() { // <- int는 함수이름으로 못씀 하지만 이렇게 쓰면 형 변환 연산자 기능이 됨
        cout<<"int()"<<endl;
        return num; // 현 변환도 반환 타입이 없다.
    }

    void ShowNumber() {
        cout<<num<<endl;
    }
};

int main(void) {
    Number num1;
    num1=30;

    Number num2=num1+20;
    num2.ShowNumber();

//    int n = num2;
    cout<<"type cast : "<<num2<<endl; // (묵시적 형변환) // 객체는 consolout 못씀

    return 0;
}

// 복사 생성자 출력과정 만들어 보기 (복사 생성자 코드는 입력되지 않아서 호출이 되지 않았다.)
