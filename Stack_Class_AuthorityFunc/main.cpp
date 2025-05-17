#include <iostream>
// #include <cstring>

using namespace std;

class Stack {
private:
    int m_size;
    int m_top;
    int* m_buffer;
public:
    int GetSize();
    int GetTop();
    bool SetSize(int size);
    bool GetData(int index, int& data);

    Stack(); // ...1을 위해서는 클래스 Stack 안에 생성자 Stack을 별도로 만들어주는데 이때 공유 가능한 접근지정자를 사용하였다.
}; // 초기화를 위한 생성자가 만들어졌다면 소멸자도 만들어주는 것이 보통이다.

// 클래스 내부에 ~Stack();을 추가하고,

/* 외부에다가
Stack::~Stack() {
    delete[] m_buffer;
} 을 추가할 수 있다.
*/

Stack::Stack() { // <- 쓰레기값을 방지하기 위한 초기화가 필요하다 ...1
    m_size = 0;
    m_top = -1;
    m_buffer = nullptr; // <- 임시값이 널 포인터를 가리킬 가능성에 유의하기 위해 추가할 수 있다.
}

int Stack::GetSize() {
    return m_size;
}
int Stack::GetTop() {
    return m_top;
}
bool Stack::SetSize(int size) {
    if(size<m_size) return false;
    int* tmp=m_buffer;

    m_buffer=new int[m_size];
//    if (tmp != nullptr)
    memcpy(m_buffer, tmp, sizeof(int)*(m_top+1));

    delete [] tmp;
    m_size=size;
    return true;
}
bool Stack::GetData(int index, int& data) {
    if(index<0 || index>m_top)  return false;
    data=m_buffer[index];
    return true;
}
int main() {
    Stack s;
    s.SetSize(5);  // 스택 크기 설정

    cout << "스택 크기: " << s.GetSize() << endl;
    cout << "스택 top 위치: " << s.GetTop() << endl;

    return 0;
}
