#include <iostream>

using namespace std;

namespace first {
int value=1;
}

namespace second {
int value=2;
}

int main()
{
    cout<<first::value<<endl;
    cout<<second::value;
    return 0;
}
