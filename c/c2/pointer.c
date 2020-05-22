#include<stdio.h>

int main(void) {

    /* int num = 6;
     *    name: num
     *    value: 6
     *    type: int
     *    location: where the variable i stored
     *    address: label for the location
     */
    int num = 6;     /* Integer */
    int * ptr;       /* Pointer to an integer (or integer pointer) */

    /* & : reference operator - returns the address */
    /* * : dereference operator - returns an alias */

    ptr = &num;    /* ptr holds the address of num */
    printf("num = %d, address %p, size=%ld\n", num, (void *) &num, sizeof(num));
    printf("ptr = %p, address %p, size=%ld, *p=%d\n", (void *) ptr, (void *) &ptr, 
                                                      sizeof(ptr), *ptr);

    /* *p is an alias of num */
    *ptr = 20;
    printf("\nAfter *ptr=20\n");
    printf("num = %d, address %p, size=%ld\n", num, (void *) &num, sizeof(num));
    printf("ptr = %p, address %p, size=%ld, *p=%d\n", (void *) ptr, (void *) &ptr, 
                                                      sizeof(ptr), *ptr);

    printf("\n");
    printf("ptr & num: \n");
    printf("  ptr = %p\n", (void *) ptr);
    printf("  *ptr = %d\n", *ptr);
    printf("  num = %d\n", num);
    printf("  &num = %p\n", (void *) &num);
    printf("  *(&num) = %d\n", *(&num));
    printf("  &(*ptr) = %p\n", (void *) &(*ptr));




    return(0);
}

