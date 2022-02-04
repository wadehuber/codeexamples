#include<stdio.h>

int main(void) {

    int int_var = 10;
    char char_var = 'A';
    int int_arr[] = {1,2,3,4,5,6,7,8,9,10};
    char str_var[] = "C Sizes";

    /* Use sizeof varname to find out how much memory is allocated for a variable */
    printf("int_var=%d, sizeof int_var=%lu\n", int_var, sizeof int_var);
    printf("char_var=%c, sizeof char_var=%lu\n", char_var, sizeof char_var);
    printf("int_arr[0]=%d, sizeof int_arr=%lu\n", int_arr[0], sizeof int_arr);
    printf("str_var=%s, sizeof str_var=%lu\n", str_var, sizeof str_var);

    /* Use sizeof type to find out how much memory is allocated for a type */
    printf("\n");
    printf("sizeof int=%lu\n", sizeof(int));
    printf("sizeof short=%lu\n", sizeof(short));
    printf("sizeof long=%lu\n", sizeof(long));
    printf("sizeof char=%lu\n", sizeof(char));
    printf("sizeof float=%lu\n", sizeof(float));
    printf("sizeof double=%lu\n", sizeof(double));

    printf("\n");
    printf("sizeof literals:\n");
    printf("sizeof(%d)=%lu\n", 42, sizeof(42));
    printf("sizeof('%c')=%lu (printed as int: %d)\n", 'A', sizeof('A'), 'A');
    printf("sizeof(\"%s\")=%lu\n", "A", sizeof("A"));
    printf("sizeof(%.2f)=%lu\n", 4.2, sizeof(4.2));

    return(0);
}