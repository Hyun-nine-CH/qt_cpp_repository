#include <iostream>
#include <memory>
using namespace std;

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
