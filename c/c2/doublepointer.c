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
    *ptr = newptr;  /* Dereferencing ptr gives me an alias of the pointer that was passed */
}

int main(void) {

    /* Introduction to double pointers */
    int val = 7;          /* Integer variable */
    int * ptr = &val;     /* Integer pointer variable (pointer to int) */
    int ** dptr = &ptr;   /* Integer pointer pointer variable (pointer to int pointer) */

    printf("    val [%p]: val=%d\n", (void*) &val, val);
    printf("    ptr [%p]: ptr=%p *ptr=%d\n", (void*) &ptr, (void*) ptr, *ptr);
    printf("   dptr [%p]: dptr=%p *dptr=%p **dptr=%d\n", (void*) &dptr, (void*) dptr,(void*) *dptr, **dptr);
    printf("\n");

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

    printf("new_int_parm:\n");
    new_int_parm(&ptr1, 3);
    new_int_parm(&ptr2, 8);
    printf("   ptr1=%p  *ptr=%d  &ptr1=%p\n", (void*) ptr1, *ptr1, (void*) &ptr1);
    printf("   ptr2=%p  *ptr=%d  &ptr2=%p\n", (void*) ptr2, *ptr2, (void*) &ptr2);
    printf("\n");

    return 0;
}