#include <iostream>

namespace BestComlmpl {
void SimpleFunc(void) {
    std::cout<<"BestCom이 정의한 함수"<<std::endl;
}
}

namespace ProgComlmpl {
void SimpleFunc(void) {
    std::cout<<"ProgCom이 정의한 함수"<<std::endl;
}
}

int main()
{
    BestComlmpl::SimpleFunc();
    ProgComlmpl::SimpleFunc();
    return 0;
}
