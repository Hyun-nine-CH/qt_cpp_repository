#include "compare.h"

// auto를 사용할 수 없다.

int Compare(const int a, const int b) {
    if(a>b)
        return 1;
    else if(a==b)
        return 0;
    else
        return -1;
}

int Compare(const float a, const float b) {
    if(a>b)
        return 1;
    else if(a==b)
        return 0;
    else
        return -1;
}

int Compare(const char a, const char b) {
    if(a>b)
        return 1;
    else if(a==b)
        return 0;
    else
        return -1;
}

/*
a b c ''<- NULL이면 빠져 나와야된다 아니면 죽음
a b c d

a b c > A B C
*/

int Compare(const char str1[], const char str2[]) {
    int i;

    for(i=0; str1[i]!='\0' && str2[i]!='\0'; i++) {
        if(str1[i]>str2[i])
            return 1;
        else if(str1[i]<str2[i])
            return -1;
        else
            ;
    }
    if(str1[i]=='\0' && str2[i]!='\0')
        return -1;
    else if(str1[i]!='\0' && str2[i]=='\0')
        return 1;
    else
        return 0;
}
