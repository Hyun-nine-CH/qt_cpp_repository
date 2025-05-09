#include <iostream>

using namespace std;

int main() {
//    const char *cp;
//    char *q = static_cast<char*>(cp); // error
//    const_cast<string>(cp); // error

    const char * str = "Hello";
    char * str2 = const_cast<char*>(str);
    cout<<str2<<endl;

//    const char* str = "Hello";
//    char * str2 = const_cast<char*>(str);
//    str2[2] = 'a'; // run-time error
//    cout<<str2<<endl;

    return 0;
}
