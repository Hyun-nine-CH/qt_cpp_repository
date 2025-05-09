#include <iostream>

using namespace std;

int main(void)
{
    int *p = nullptr;
    //p = new int{12.0}; // error type이 정확하지 않음
    p = new int(12.0);
    if(p == nullptr) { // C++ 11에서 좀 더 정확하게 null이 아닌 nullptr로
        cout << "Memory allocation error!" << endl;
        return -1;
    }

    cout << "Input the number : ";
    cin >> *p;
    cout << "The inputted number is " << p[0] << endl;

    delete p;
    p = nullptr;

    return 0;
}
