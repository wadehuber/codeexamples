#include <stdio.h>

int main()
{
    /* 1D Array */
    int A[3]={1, 2, 3};
    
    /* 2D Array */
    int B[2][3]={
	 { 1, 2, 3},
	 { 4, 5, 6}
    };

    int ii;

    printf("\nA: ");
    printf("%p ", (void*) A);
    printf("%p ", (void*) (A+1));
    printf("%p ", (void*) (A+2));
    
    printf("\n*A: ");
    printf("%d ", *A);
    printf("%d ", *(A+0));
    printf("%d ", *(A+1));
    printf("%d ", *(A+2));
    printf("\n");

    /* Address of elements in an array */
    printf("\nB (B[0]): ");
    printf("%d ", *(*(B)+0));
    printf("%d ", *(*(B)+1));
    printf("%d ", *(*(B)+2));
    printf("%d ", B[0][0]);
    printf("%d ", B[0][1]);
    printf("%d ", B[0][2]);
    printf("%p ", (void *) (B));
    printf("%p ", (void *) *(B));
    printf("%p ", (void*) &B[0]);
    printf("%p ", (void*) &B[0][0]);
    printf("%p ", (void*) &B[0][1]);
    printf("%p ", (void*) &B[0][2]);
    printf("\n");
   
    printf("B+1 (B[1]): ");
    printf("%d ", *(*(B+1)+0));
    printf("%d ", *(*(B+1)+1));
    printf("%d ", *(*(B+1)+2));
    printf("%d ", B[1][0]);
    printf("%d ", B[1][1]);
    printf("%d ", B[1][2]);
    printf("%p ", (void *) (B+1));
    printf("%p ", (void *) *(B+1));
    printf("%p ", (void*) &B[1]);
    printf("%p ", (void*) &B[1][0]);
    printf("%p ", (void*) &B[1][1]);
    printf("%p ", (void*) &B[1][2]);
    printf("\n");
   
    
    printf("\n");
    // pointer ptr points at array num
    int *ptr = &B[0][0];
  
    // other variables
    int TOTAL_CELLS = (2 * 3);

    printf("\nVia  (ptr+ii): ");
    /* print the addresses of the array via ptr ptr */
    for (ii = 0; ii < TOTAL_CELLS; ii++) {
      printf("%p ", (void*) (ptr + ii));
    }
    printf("\n");
  
    /* print the elements of the array num via pointer ptr */
    printf("Via *(ptr+ii): ");
    for (ii = 0; ii < TOTAL_CELLS; ii++) {
      printf("%d ", *(ptr + ii));
    }
    printf("\n");

    return 0;
}
