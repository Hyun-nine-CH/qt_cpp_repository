#include <iostream>

using namespace std;

int main()
{
    int sum=0, i=0;
    for(i=1; i<=10; i++)
        sum=sum+i;

    std::cout<<"1~10까지의 합"<<sum<<std::endl;
    return 0;
}
