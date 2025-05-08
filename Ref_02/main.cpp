#include <iostream>

using namespace std;

int main()
{
    int val1=100;
    int &val2=val1;
    // int &val3=200;
    int &val4=val2;
    // int &val5;
    val1=val1*3;
    cout<<"val1="<<val1<<endl;
    cout<<"val2="<<val2<<endl;
    cout<<"val4="<<val4<<endl;
    return 0;
}
