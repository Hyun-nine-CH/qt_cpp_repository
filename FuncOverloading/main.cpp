#include "compare.h"

int main() {
    int a=34, b=4;
    float c=1.234f, d=98.34f;
    char e='H', f='K';
    char str1[]="computer", str2[]="computers";

    printf("%d\n", Compare(a,b));
    printf("%d\n", Compare(c,d));
    printf("%d\n", Compare(e,f));
    printf("%d\n", Compare(str1,str2));

    return 0;
}
