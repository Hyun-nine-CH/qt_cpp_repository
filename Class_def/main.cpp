#include <iostream>

using namespace std;

class name {
public:
    void Structure();
};

void name::Structure() {
    cout<<"이름 구조"<<endl;
}

//int main() { // 인자를 안 받겠다 싶으면 비어있는 공간으로 두는 게 좋음
int main(void) {
    name Name;
    Name.Structure();
    return 0;
}
