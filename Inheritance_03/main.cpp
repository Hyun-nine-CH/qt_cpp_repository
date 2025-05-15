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
