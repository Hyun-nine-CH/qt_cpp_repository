#include <iostream>
using namespace std;

int RetuRefFunc(int n) {
    int num=20;
    num+=n;
    return num;
}

int main() {

    int num1=10;
    int ref=RetuRefFunc(num1);

    // (또는) int &ref=RetuRefFunc(10);

    cout<<&ref<<endl;
    return 0;
}
