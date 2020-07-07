#include<stdio.h>
#include<string.h>

// Union will only allocate enough memory for the largest field
union myUnion {
    int x;
    double d;
    char s[16];
};

int main(void) {
    union myUnion values;

    values.x = 10;
    printf("values.x=%d   sizeof(values=%ld)\n", values.x, sizeof(values));

    values.d = 83.242;
    printf("values.d=%.2f   sizeof(values=%ld)\n", values.d, sizeof(values));

    strncpy(values.s, "HELLO", 6);
    printf("values.s=%s   sizeof(values=%ld)\n", values.s, sizeof(values));

    printf("values.x=%x   sizeof(values=%ld)\n", values.x, sizeof(values));

    return 0;
}
