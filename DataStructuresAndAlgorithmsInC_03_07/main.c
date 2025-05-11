#include <stdio.h>
#include <string.h>
#include <bsearch_line.c>

int int_cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main(void) {
    int arr[] = {5, 7, 3, 2, 9, 1};
    int key = 1;

    int *result = seqsearch(&key, arr, sizeof(arr)/sizeof(arr[0]), sizeof(int), int_cmp);

    if (result != NULL)
        printf("찾은 값: %d\n", *result);
    else
        printf("값을 찾지 못했습니다.\n");

    return 0;
}
