#include <iostream>

int main()
{
    int num=10;
    int &ref=num;

    std::cout<<"num="<<num<<std::endl;
    std::cout<<"ref="<<ref<<std::endl;

    ref=100;

    std::cout<<"num="<<num<<std::endl;
    std::cout<<"ref="<<ref<<std::endl;

    std::cout<<"&num="<<&num<<std::endl;
    std::cout<<"&ref="<<&ref<<std::endl;

    return 0;
}
