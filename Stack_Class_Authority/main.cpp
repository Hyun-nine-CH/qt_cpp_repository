#include <iostream>

using namespace std;

class Stack {
protected:
    int m_size;
    int m_top;
    int *m_buffer;

public:
    void Initialize(int size=10);
    void RemoveAll();
    bool Push(int value);
    bool Pop(int& value);
};

int main()
{
    Stack s1;
    s1.Initialize(5);
//    s1.m_top=1;
    int data;
    s1.Pop(data);
//    delete [] s1.m_buffer;
    s1.Push(123);
    return 0;
}
