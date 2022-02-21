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
    int h;
    struct struct4 * i;
} struct4;

int main(void) {

    struct struct1 s1 = {1, 2};
    type2_t s2 = {3, 4};
    type3_t s3a = {5, 6};
    struct struct3 s3b = {7, 8};

    struct struct4 s4a = {9, 10};
    struct4 s4b = {11, 12};

    return(0);
}