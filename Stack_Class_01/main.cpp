#include <iostream>

using namespace std;

class Stack {
public:
    int m_size;
    int m_top;
    int *m_buffer;

    void Initialize(int size=10);
    void RemoveAll();
    bool Push(int value);
    bool Pop(int& value);
};

void Stack::Initialize(int size) {
    m_size=size;
    m_top = -1;
    m_buffer = new int[m_size];
    memset(m_buffer, 0, sizeof(int) *m_size);
}

void Stack::RemoveAll() {
    m_size = 0;
    m_top = -1;
    delete[] m_buffer;
    m_buffer = NULL;
}

bool Stack::Push(int value) {
    if(m_top >= m_size -1)  return false;
    m_buffer[++m_top] = value;
    return true;
}  // (): 타입 달라도 묵시적 변환함; {}: 타입 다르면 에러

bool Stack::Pop(int& value) {
    if(m_top<0)     return false;
    value = m_buffer[m_top--];
    return true;
}

int main() {
    Stack s;
    s.SetSize(10);
    cout << "스택 크기: " << s.GetSize() << endl;
    return 0;
}
