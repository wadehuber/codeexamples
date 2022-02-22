#include<stdio.h>

struct struct1 {
    int a;
    int b;
};

typedef struct {
    int c;
    int d;
} type2_t;

typedef struct struct3 {
    int e;
    int f;
} type3_t;

typedef struct struct4 {
    int g;
    float h;
    char * i;
    struct struct4 * j; 
} struct4;

int main(void) {

    struct struct1 s1 = {1, 2};

    type2_t s2 = {3, 4};

    struct struct3 s3a = {5, 6};
    type3_t s3b = {7, 8};

    struct struct4 s4a = {9, 10, NULL, NULL};
    struct4 s4b = {11, 12, NULL, NULL};

    printf("Struct & Typedef:\n");
    printf("  s1: %d %d\n", s1.a, s1.b);
    printf("  s2: %d %d\n", s2.c, s2.d);
    printf(" s3a: %d %d\n", s3a.e, s3a.f);
    printf(" s3b: %d %d\n", s3b.e, s3b.f);
    printf(" s4a: %d %.2f\n", s4a.g, s4a.h);
    printf(" s4b: %d %.2f\n", s4b.g, s4b.h);

    return(0);
}