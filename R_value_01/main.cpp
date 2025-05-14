#include <iostream>
using namespace std;

int Add(int x, int y) {
    return x + y;
}

int & inc(int &x) {
    return ++x;
}

int main() {
    int x=5;
    int y = x*5;
    ++x=7; // <- 이런 표현은 지양해야 한다.
    cout<<x<<endl;
    cout<<y<<endl;
}
