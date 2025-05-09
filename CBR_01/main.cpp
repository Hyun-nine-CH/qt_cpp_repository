#include <iostream>
using namespace std;

void Swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a, b;
    cout<<"두 수를 입력하세요:";
    cin>>a>>b;
    cout<<"Swap 호출 전의 a= "<<a<<", b= "<<b<<endl;
    Swap(a, b);
    cout<<"Swap 호출 후의 a= "<<a<<", b= "<<b<<endl;
    return 0;
}

// reference에 의한 전달 과정
