#include<stdio.h>

int main(void) {

    int int_var = 10;
    char char_var = 'A';
    char str_var[] = "C Sizes";

    /* Use sizeof(varname) to find how much memory is allocated for a variable */
    printf("int_var=%d, sizeof(int_var)=%lu\n", int_var, sizeof(int_var));
    printf("char_var=%c, sizeof(char_var)=%lu\n", char_var, sizeof(char_var));
    printf("str_var=%s, sizeof(str_var)=%lu\n", str_var, sizeof(str_var));
    printf("\n");

    /* You can also use sizeof(varname) to find out how much memory is 
        allocated for a literal */
    printf("integer literal %d: sizeof(4)=%lu\n", 4, sizeof(4));
    printf("character literal '%c': sizeof(4)=%lu\n", '4', sizeof('4'));
    printf("string literal \"%s\": sizeof(4)=%lu\n", "4", sizeof("4"));

    return(0);
}