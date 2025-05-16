#include <iostream>

using namespace std;

template<typename T, typename R>
R MaxValue(const T num1, const R num2) {
    if(num1>num2)
        return num1;
    else
        return num2;
}
int main() {
    cout<<"정수 비교 결과:"<<MaxValue(3, 5)<<endl;
    cout<<"배정도 비교 결과:"<<MaxValue(9.1, 3.6)<<endl;
    return 0;
}
