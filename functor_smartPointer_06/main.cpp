#include <iostream>
#include <memory>
using namespace std;

// shared_ptr

int main() {
    shared_ptr<int> ptr01(new int(5));
    cout<<ptr01.use_count()<<endl;
    auto ptr02(ptr01);
    cout<<ptr01.use_count()<<endl;
    auto ptr03=ptr01;
    cout<<ptr01.use_count()<<endl;
}

// ex
/*
int main(void) {
    shared_ptr<Chulsoo> chulsooSmptr1(new Chulsoo(32));
    cout<<chulsooSmptr1.use_count()<<endl;
    chulsooSmptr1->introduce();
    cout<<"shared_ptr<Chulsoo> 타입간 복사 생성자 호출 후"<<endl;
    shared_ptr<Chulsoo> chulsooSmptr2=chulsooSmptr1;
    cout<<chulsooSmptr1.use_count()<<endl;
    chulsooSmptr1->introduce();
    chulsooSmptr2->introduce();

    return 0;
}
*/
