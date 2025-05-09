#include <iostream>

using namespace std;

void plus1(int n) { n++; }
void plus2(int &n) { n+=2; }
//void plus3(const int n) { n+=3; }
//void plus4(const int &n) { n+=4; }
int main(void)
{
    int num1 = 1;
    plus1(num1); cout << "1 : " << num1 << endl;
    plus2(num1); cout << "2 : " << num1 << endl;
    //plus3(num1); cout << "3 : " << num1 << endl;
    //plus4(num1); cout << "4 : " << num1 << endl;
    return 0;
}
