#include <iostream>
#include <list>
using namespace std;

int main() {
    // int 타입을 담을 링크드 리스트 생성
    list<int> intList;

    // 1~10까지 링크드 리스트에 넣는다.
    for(int i=0; i<10; ++i)
        intList.push_back(i);

    intList.remove(5);

    list<int>::iterator it;

    for(it=intList.begin(); it != intList.end(); it++)
        std::cout<<*it<<endl; //"\n";

    return 0;
}
