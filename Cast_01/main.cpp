#include <iostream>

using namespace std;

int main() {
    int num = 0x040204;
    char* ptr = reinterpret_cast<char*>(&num);
    std::cout<<static_cast<int>(*(ptr+1))<<std::endl;
    return 0;
}
