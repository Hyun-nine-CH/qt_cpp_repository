#include <stddef.h>

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size,
                int (*compar)(const void *, const void *)) {
    const char *ptr = base;  // void*는 산술 연산 안 되므로 char*로 캐스팅

    for (size_t i = 0; i < nmemb; i++) {
        const void *element = ptr + i * size;
        if (compar(key, element) == 0) {
            return (void *)element;  // 찾으면 그 요소의 주소 반환
        }
    }

    return NULL;  // 못 찾으면 NULL 반환
}
