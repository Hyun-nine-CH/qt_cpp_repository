/*
#include <iostream>

namespace foo {
    int i = 0; // 매개변수의 초기화는 중요하다
    int j = i+2;
    int getvalue() {
        return j;
    }
}

int main()
{
    for(int i=0; i < 10; i++)
        std::cout<<"Result #"<< i <<" : "<< foo::getvalue() << std::endl;
    return 0;
}
*/

#include <iostream>

namespace foo {
int i = 0;
int getvalue() {
    i++;             // 호출될 때마다 i 증가
    return i + 2;
}
}

int main() {
    for(int i = 0; i < 10; i++)
        std::cout << "Result #" << i << " : " << foo::getvalue() << std::endl;
    return 0;
}
