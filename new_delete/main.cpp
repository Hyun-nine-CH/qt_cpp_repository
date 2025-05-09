#include <iostream>

using namespace std;

char * NumberToString(int n) {
    //char p[20];
    char *p = new char[20];
    sprintf(p, "%d", n);
    return p;
}

int main()
{
    int num;
    cout<<"정수를 입력하세요:";
    cin>>num;

    char *str = NumberToString(num);
    cout<<"문자열로 변환된 값:"<<str<<endl;
    delete [] str;

    return 0;
}
