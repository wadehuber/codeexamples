#include <stdio.h>

int main()
{
    /* 1D Array */
    int A[3] = {1,2,3};

    /* 2D Array */
    int B[2][3] = { {1, 2, 3}, {4, 5, 6} };

    printf("A (1D array):\n");
    printf("  A[0] = %d  address=%p\n", A[0], (void*) &A[0]);
    printf("  A[1] = %d  address=%p\n", A[1], (void*) &A[1]);
    /* This is equivalent to the above */
    printf("  A[2] = %d  address=%p\n", *(A+2), (void*) (A+2));

    printf("\n");
    printf("B (2D array):\n");
    printf("  B[0] address=%p\n", (void*) &B[0]);
    printf("  B[1] address=%p\n", (void*) (B+1));


    printf("B[0] :\n");
    printf("  B[0][0] = %d  address=%p\n", B[0][0], (void*) &B[0][0]);
    printf("  B[0][1] = %d  address=%p\n", B[0][1], (void*) &B[0][1]);
    printf("  B[0][2] = %d  address=%p\n", *((*B)+2), (void*) ((*B)+2));
    printf("B[1] :\n");
    printf("  B[1][0] = %d  address=%p\n", B[1][0], (void*) &B[1][0]);
    printf("  B[1][1] = %d  address=%p\n", B[1][1], (void*) &B[1][1]);
    printf("  B[1][2] = %d  address=%p\n", *((*(B+1))+2), (void*) ((*(B+1))+2));

    printf("\n");
    int *ptr = B[0];
    int total_cells = 2 * 3;

    /* print the address of the array via pointer ptr */
    printf("\nAddress via pointer ptr:\n");
    for(int ii=0;ii<total_cells;ii++) {
        printf("  value=%d  address=%p\n", *(ptr+ii), (void *)(ptr+ii));
    }

    printf("\n"); 

    return(0);
}
