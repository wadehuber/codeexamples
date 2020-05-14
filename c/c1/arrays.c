#include<stdio.h>

int main(void) {
    
    int array[10];    /* array declaration */

    /* Initializing array declaration */
    int a[4] = {1, 2, 3, 4};
    double b[] = {2.4, 3.14, 9.9999};   /* b is the size of the initializer */
    /* What happens if we declare an array with a size smaller than the initialzer? */

    unsigned int ii;

    /* This is undefined behavior! */
    for(ii=0;ii<10;ii++) {
        array[ii] = ii * 100;
        printf("array[%d]=%d\t\ta[%d]=%d\t\tb[%d]=%.2f\n", ii, array[ii], ii, a[ii], ii, b[ii]);
    }
    printf("\n");

    printf("Size of array=%lu\n", sizeof(array));
    printf("Size of a=%lu\n", sizeof(a));
    printf("Size of b=%lu\n", sizeof(b));
    printf("Sizeof int=%lu\n", sizeof(int));
    printf("Sizeof double=%lu\n", sizeof(double));
    printf("\n");


    a[2] = 20;
    a[3] = 200;
    for (ii=0;ii<sizeof(a)/sizeof(int);ii++) {
        printf("a[%d]=%d  (%x)\n", ii, a[ii], a[ii]);
    }
    printf("\n");
    return 0;
}
