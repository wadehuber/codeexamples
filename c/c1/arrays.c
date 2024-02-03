#include<stdio.h>

int main(void) {

    int array[10];    /* integer array declaration */

    /* Initializing array declaration */
    int a[4] = {1, 2, 3, 4};
    double b[] = {2.4, 3.14, 9.99999};  /* b is the size of the initializer */
    /* What happens if we declare an array with size smaller than
     *   the initializer? */

    unsigned int ii;

    /* Initialize array using a loop */
    for (ii=0;ii<10;ii++) {
        array[ii] = ii * 100;
    }

    /* Printing a & b like this in undefined behavior due to the index
     *  being out-of-bounds */
    for (ii=0;ii<10;ii++) {
        printf("array[%d]=%d\t", ii, array[ii]);
        printf("a[%d]=%d\t", ii, a[ii]);
        printf("b[%d]=%.2f\n", ii, b[ii]);
    }
    printf("\n");

    /* Print some information about the arrays */
    printf("Size of array=%lu\n", sizeof(array));
    printf("Size of a=%lu\n", sizeof(a));
    printf("Size of b=%lu\n", sizeof(b));
    printf("Size of int=%lu\n", sizeof(int));
    printf("Size of double=%lu\n", sizeof(double));
    printf("\n");

    /* Using sizeof to determine the array bounds */
    a[2] = 20;
    a[3] = 200;
    for (ii=0;ii<sizeof(a)/sizeof(int);ii++) {
        printf("a[%d]=%d (%X)\n", ii, a[ii], a[ii]);
    }
    printf("\n");

    return 0;
}
