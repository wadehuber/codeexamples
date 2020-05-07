#include<stdio.h>

/* Example of errors introduced when assigning int values to float variables. */

int main(void) {
    int my_int = 2147483647;
    float my_float = my_int;

    printf("my_int=2147483647, my_float=my_int:\n");
    printf("my_int: %d  size=%d\n", my_int, sizeof(my_int));
    printf("my_float: %f  size=%d\n", my_float, sizeof(my_float));

    printf("\nmy_int=my_int-64, my_float=my_int:\n");
    my_int = my_int - 63;
    my_float = my_int;
    printf("my_int: %d  size=%d\n", my_int, sizeof(my_int));
    printf("my_float: %f  size=%d\n", my_float, sizeof(my_float));

    printf("\nmy_int=my_int-1, my_float=my_int:\n");
    my_int = my_int - 1;
    my_float = my_int ;
    printf("my_int: %d  size=%d\n", my_int, sizeof(my_int));
    printf("my_float: %f  size=%d\n", my_float, sizeof(my_float));

    return 0;
}
