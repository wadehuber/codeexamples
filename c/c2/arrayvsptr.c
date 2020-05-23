#include<stdio.h>

#define COUNT 16

int main(void) {
    int nums[COUNT];
    int * p;  /* Integer pointer */

    p = nums;   /* equivalent to p = &nums[0] */

    for(int ii=0;ii<COUNT;ii++) {
        nums[ii] = ii;
    }

    printf("Array indexing: ");
    for(int ii=0;ii<COUNT;ii++) {
        printf("%d ", nums[ii]);
    }
    printf("\n");

    printf("Pointer arithmetic: ");
    for(int ii=0;ii<COUNT;ii++) {
        printf("%d ", *(p+ii));
    }
    printf("\n");
   
    printf("Array indexing using pointer name: ");
    for(int ii=0;ii<COUNT;ii++) {
        printf("%d ", p[ii]);
    }
    printf("\n");

    printf("Pointer arithmetic using array name: ");
    for(int ii=0;ii<COUNT;ii++) {
        printf("%d ", *(nums+ii));
    }
    printf("\n");
    printf("\n");
   
    printf("Are arrays and pointers the same?\n");
    printf("   size of nums: %ld\n", sizeof(nums));
    printf("   size of p: %ld\n", sizeof(p));

    /* You can assign a value to a pointer, but not an array name */
    /*   VALID: p = &ii; */
    /*   ERROR: nums = &ii */

    printf("\n\nPointer arithmetic (using increment operator): \n  ");
    for(int ii=0;ii<COUNT;ii++) {
        printf("%d ", *p);
        p++;
    }
    /* at this point p does not point to the start of the array */
    printf("\np=%p, *p=%d\n", (void *) p, *p);
    p--;
    printf("\np=%p, *p=%d\n", (void *) p, *p);
    printf("\n");

    return(0);
}
