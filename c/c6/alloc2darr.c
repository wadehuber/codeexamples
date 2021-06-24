#include<stdio.h>
#include<stdlib.h>

int main(void) {
    int counter = 1;
    int ** arr2d;  /* Pointer to array of pointers */

    /* Allocate an array of 3 pointers - one for each row */
    arr2d = malloc(3 * sizeof(int *));

    /* For each pointer allocated above, allocate an array of 5 integers */
    for (int rr=0;rr<3;rr++) {
        arr2d[rr] = malloc(5 * sizeof(int));
    }

    /* Fill up the array using array indexing*/
    for (int rr=0;rr<3;rr++) {
        for (int cc=0;cc<3;cc++) {
            arr2d[rr][cc] = counter;
            counter++;
        }
    }
    
    /* Print the array, this time using pointer arithmetic*/
    for (int rr=0;rr<3;rr++) {
        for (int cc=0;cc<3;cc++) {
            printf("%3d", *(*(arr2d+rr)+cc));
        }
        printf("\n");
    }

    /* free each row */
    for (int rr=0;rr<3;rr++) {
        free(arr2d[rr]);
    }
    /* free array of pointers to rows */
    free(arr2d);
    return 0;
}