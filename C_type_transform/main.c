#include <stdio.h>
#include <math.h>

int main()
{
    int i = 3.65; // 버림
    long l = M_PI;
    float f = M_PI; // 올림
    double d = M_PI;

    printf("%d %ld\n", i, l);
    printf("%.20f %.20f\n", f, d);
    return 0;
}
