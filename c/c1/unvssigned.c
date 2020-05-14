#include<stdio.h>

int main(void) {
    int a = -1;
    unsigned int b = 1;

    printf("a: signed=%d  unsigned=%u\n", a, a);
    printf("b: signed=%d  unsigned=%u\n", b, b);
    printf("\n");

    if (a<b) {
        printf("a=%d is less than b=%u\n", a, b);
    }
    else {
        printf("a=%d is not less than b=%u\n", a, b);
    }

    if (b<a) {
        printf("b=%u is less than a=%d\n", b, a);
    }
    else {
        printf("b=%u is not less than a=%d\n", b, a);
    }

    return 0;
}
