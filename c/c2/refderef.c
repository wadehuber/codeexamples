#include <stdio.h>

int main(void) {
    int num = 10;
    int *ptr = &num;

    /*
       In C, & is usually called the address-of operator,
       not the reference operator.

       & : address-of operator -- gets the address of a variable
       * : dereference operator -- follows an address to access the value
    */

    /*
       & means "address of"

       &num means:
       the address where num is stored
    */
    printf("num  = %d\n", num);
    printf("&num = %p\n", (void *)&num);

    /*
       ptr stores the address of num.

       Since ptr contains an address,
       *ptr means:
       go to that address and access the value there
    */
    printf("\nptr  = %p\n", (void *)ptr);
    printf("*ptr = %d\n", *ptr);

    /*
       & moves from a variable to its address.
       * moves from an address back to the value.

       Since ptr is &num, these refer to the same int:
    */
    printf("\nnum      = %d\n", num);
    printf("*ptr     = %d\n", *ptr);
    printf("*(&num)  = %d\n", *(&num));

    /*
       Changing *ptr changes num because *ptr accesses
       the same memory location as num.
    */
    *ptr = 20;

    printf("\nAfter *ptr = 20:\n");
    printf("num  = %d\n", num);
    printf("*ptr = %d\n", *ptr);

    /*
       These two addresses are the same:
       ptr is the address of num,
       and &(*ptr) is the address of the value ptr points to.
    */
    printf("\nptr      = %p\n", (void *)ptr);
    printf("&(*ptr)  = %p\n", (void *)&(*ptr));

    return 0;
}
