#include <iostream>

using namespace std;

template<typename R, typename T, typename U>
R const add(T const& a, U const& b) {
    return a+b;
}

int main() {
    double i = 5.1;
    int j = 5;
    cout<<i<<"+"<<j<<"="<<add(i,j)<<endl;
    return 0;
}
