#include "str.h"

void StringCharArray::toCharArray(char *str) {
    int i, len=this->length();
    for(i=0; i<len; i++)
        *(str+i)=this->at(i);
    *(str+i)='\0';
}

int main()
{
    StringCharArray string{"Hello World"};
//    char len[BUFSIZ];

    return 0;
}

/*
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class StringCharArray : public std::string
{
public:
    StringCharArray(const char* s) : std::string(s) {}

    void toCharArray(char *str);
};

void StringCharArray::toCharArray(char *str)
{
    int len = this->length();

    for (int i = 0; i < len; ++i) {
        *(str + i) = this->at(i);
    }

    *(str + len) = '\0';
}

int main(void)
{
    StringCharArray customString = "Hello, World!";
    int length = customString.length();
    char* charArray = new char[length + 1];
    customString.toCharArray(charArray);

    cout << charArray << endl;

    delete[] charArray;
    charArray = nullptr;

  return 0;
}
*/
