#include <iostream>
#include <cstring>  // memset 사용 시 필요

using namespace std;

class Stack {
public:
    int m_size;
    int m_top;
    int* m_buffer;

    void Initialize(int size = 10);
    void RemoveAll();
    bool Push(int value);
    bool Pop(int& value);
    int GetSize() const;     // ⬅ 크기 반환 함수 추가
};

void Stack::Initialize(int size) {
    m_size = size;
    m_top = -1;
    m_buffer = new int[m_size];
    memset(m_buffer, 0, sizeof(int) * m_size);
}

void Stack::RemoveAll() {
    m_size = 0;
    m_top = -1;
    delete[] m_buffer;
    m_buffer = nullptr;
}

bool Stack::Push(int value) {
    if (m_top >= m_size - 1) return false;
    m_buffer[++m_top] = value;
    return true;
}

bool Stack::Pop(int& value) {
    if (m_top < 0) return false;
    value = m_buffer[m_top--];
    return true;
}

int Stack::GetSize() const {
    return m_size;
}

int main() {
    Stack s;
    s.Initialize(10); // SetSize 대신 Initialize 사용
    cout << "스택 크기: " << s.GetSize() << endl;

    // 스택에 값 추가
    s.Push(10);
    s.Push(20);
    s.Push(30);

    int value;
    while (s.Pop(value)) {
        cout << "Pop된 값: " << value << endl;
    }

    s.RemoveAll();  // 메모리 정리
    return 0;
}
