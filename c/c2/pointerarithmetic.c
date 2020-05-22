#include<stdio.h>

int main(void) {
    int x[5] = {0, 11, 22, 33, 44}; 
    int * p = &x[0];

    printf("Initial values\n");
    for(int ii=0;ii<5;ii++) {
        printf("x[%d]=%16d at address %p, size=%lu\n", ii, x[ii], (void *) &x[ii], sizeof(int));
    }
    printf("   p=%16p at address %p, size=%lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p);
    printf("\n");

    *p = 100;
    printf("*p=100\n");
    for(int ii=0;ii<5;ii++) {
        printf("x[%d]=%16d at address %p, size=%lu\n", ii, x[ii], (void *) &x[ii], sizeof(int));
    }
    printf("   p=%16p at address %p, size=%lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p);
    printf("\n");

    p++;
    printf("p++\n");
    for(int ii=0;ii<5;ii++) {
        printf("x[%d]=%16d at address %p, size=%lu\n", ii, x[ii], (void *) &x[ii], sizeof(int));
    }
    printf("   p=%16p at address %p, size=%lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p);
    printf("\n");

    *p = 1111;
    printf("*p=1111\n");
    for(int ii=0;ii<5;ii++) {
        printf("x[%d]=%16d at address %p, size=%lu\n", ii, x[ii], (void *) &x[ii], sizeof(int));
    }
    printf("   p=%16p at address %p, size=%lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p);
    printf("\n");

    p = p + 2;
    printf("p = p + 2\n");
    for(int ii=0;ii<5;ii++) {
        printf("x[%d]=%16d at address %p, size=%lu\n", ii, x[ii], (void *) &x[ii], sizeof(int));
    }
    printf("   p=%16p at address %p, size=%lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p);
    printf("\n");

    (*p)++;
    printf("(*p)++\n");
    for(int ii=0;ii<5;ii++) {
        printf("x[%d]=%16d at address %p, size=%lu\n", ii, x[ii], (void *) &x[ii], sizeof(int));
    }
    printf("   p=%16p at address %p, size=%lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p);
    printf("\n");


    p--;
    printf("p--\n");
    for(int ii=0;ii<5;ii++) {
        printf("x[%d]=%16d at address %p, size=%lu\n", ii, x[ii], (void *) &x[ii], sizeof(int));
    }
    printf("   p=%16p at address %p, size=%lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p);
    printf("\n");


    (*(--p))++;
    printf("(*(--p))++\n");
    for(int ii=0;ii<5;ii++) {
        printf("x[%d]=%16d at address %p, size=%lu\n", ii, x[ii], (void *) &x[ii], sizeof(int));
    }
    printf("   p=%16p at address %p, size=%lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p);
    printf("\n");

    return 0;
}
