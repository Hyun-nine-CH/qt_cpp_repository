#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int result;

    cout<<"a/b 수행합니다. a,b를 입력하세요."<<endl;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;

    if(b==0) {
        cout<<"0으로는 나눌 수 없습니다."<<endl;
    }else{
        result=a/b;
        cout<<"a/b의 결과는"<<result<<"입니다"<<endl;
    } // 예외 처리

//    result=a/b;
//    cout<<"a/b의 결과는"<<result<<"입니다"<<endl;

    return 0;
}
