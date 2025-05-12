#include <iostream>

using namespace std;

class Stack {

protected:
    int m_size;
    int m_top;
    int *m_buffer;

public:
    int GetSize();
    int GetTop();
    bool SetSize(int size);
    bool GetData(int index, int& data);
};

int Stack::GetSize() {
    return m_size;
}

int Stack::GetTop() {
    return m_top;
}

bool Stack::SetSize(int size) {
    if(size < m_size)   return false;
    int* tmp=m_buffer;
    m_size=size;
    m_buffer=new int[m_size];
    memcpy(m_buffer, tmp, sizeof(int)*(m_top+1));
    delete [] tmp;
    return true;
}

bool Stack::GetData(int index, int& data) {
    if(index < 0 || index > m_top)      return false;
    data = m_buffer[index];
    return true;
}

int main() {
    Stack s;
    s.SetSize(10);
    cout << "스택 크기: " << s.GetSize() << endl;
    return 0;
}
