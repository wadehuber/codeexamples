#include<stdio.h>
#include<stdlib.h>

int * new_int_return(int val) {
    int * newptr;
    newptr = malloc(sizeof(int));
    *newptr = val;
    return newptr;
}

void new_int_parm(int ** ptr, int val) {
    int * newptr;
    newptr = malloc(sizeof(int));
    *newptr = val;
    *ptr = newptr;
}

int main(void) {

    int * ptr1;
    int * ptr2;

    /* Note that the pointers are not initalized here, so we are not dereferencing */
    printf("Original:\n");
    printf("   ptr1=%p  &ptr1=%p\n", (void*) ptr1, (void*) &ptr1);
    printf("   ptr2=%p  &ptr2=%p\n", (void*) ptr2, (void*) &ptr2);
    printf("\n");

    printf("new_int_return:\n");
    ptr1 = new_int_return(4);
    ptr2 = new_int_return(7);
    printf("   ptr1=%p  *ptr=%d  &ptr1=%p\n", (void*) ptr1, *ptr1, (void*) &ptr1);
    printf("   ptr2=%p  *ptr=%d  &ptr2=%p\n", (void*) ptr2, *ptr2, (void*) &ptr2);
    printf("\n");

    free(ptr1);
    free(ptr2);

    printf("new_int_parm:\n");
    new_int_parm(&ptr1, 5);
    new_int_parm(&ptr2, 8);
    printf("   ptr1=%p  *ptr=%d  &ptr1=%p\n", (void*) ptr1, *ptr1, (void*) &ptr1);
    printf("   ptr2=%p  *ptr=%d  &ptr2=%p\n", (void*) ptr2, *ptr2, (void*) &ptr2);
    printf("\n");

    free(ptr1);
    free(ptr2);

    return 0;
}