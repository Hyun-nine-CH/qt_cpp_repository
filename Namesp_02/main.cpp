#include <iostream>

using namespace std;

namespace AAA {
namespace BBB {
namespace CCC {
int num1;
int num2;

}

}

}

int main()
{
    AAA::BBB::CCC::num1=10;
    AAA::BBB::CCC::num2=11;
    namespace ABC=AAA::BBB::CCC;

    cout<<ABC::num1<<endl;
    cout<<ABC::num2<<endl;
    return 0;
}
