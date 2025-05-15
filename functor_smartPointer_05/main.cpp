#include <iostream>
#include <memory>
using namespace std;
// unique_ptr_ex

int main()
{
    unique_ptr<int> ptr01(new int(5)); // int형 unique_ptr를 선언
    auto ptr02=move(ptr01); // ptr01에서 ptr02로 소유권을 이전

    // ptr01 -> NULL ptr

    // 대입 연산자를 이용한 복사는 오류 발생
    // ex: unique_ptr<int> ptr03=ptr01;

    ptr02.reset(); // ptr02가 가리키고 있는 메모리 영역을 삭제
    ptr01.reset();
}

/*
int main(void) {
    unique_ptr<Chulsoo> chulsooSmptr1 (new Chulsoo(32));
    chulsooSmptr1->introduce();
    cout<<"unique_ptr<Chulsoo> 타입간 복사 생성자 호출 후"<<endl;
    unique_ptr<Chulsoo> chulsooSmptr2=chulsooSmptr1;
    unique_ptr<Chulsoo> chulsooSmptr2=move(chulsooSmptr1);
    chulsooSmptr1->introduce();
    chulsooSmptr2->introduce();

    return 0;
}
*/
