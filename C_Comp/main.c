#include <stdio.h>
/*
void SwapByValue(int n1, int n2) {
    int temp=n1;
    n1=n2;
    n2=temp;
}
*/
void SwapByRef(int *ptr1, int *ptr2) {
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
}

int main()
{
    int n1=10;
    int n2=11;

    printf("original values: [%d, %d]\n", n1, n2);
    SwapByRef(&n1, &n2);
    printf("changed values: [%d, %d]",n1, n2);

    return 0;
}
