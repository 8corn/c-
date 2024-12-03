#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *x;
    x = (int *)calloc(1, sizeof(int));

    if (x == NULL) {
        puts("메모리 할당 실패");
    } else {
        *x = 2^3;
        printf("*x = %d\n", *x);

        free(x);
    }

    return 0;
}