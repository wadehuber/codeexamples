#include<stdio.h>

int main(void) {
    int var = 3;
    int var2 = 0;

    /* Here, the * means "pointer type" */
    int * ptr = &var;
    printf("var=%d, var2=%d, ptr=%p\n", var, var2, (void*) ptr);

    /* Here, the * means "dereference" */
    *ptr = 5;
    printf("var=%d, var2=%d, ptr=%p\n", var, var2, (void*) ptr);

    /* Here, the * is the "multiplication operator" */
    var2 = var * 10;
    printf("var=%d, var2=%d, ptr=%p\n", var, var2, (void*) ptr);

    /* Here, the first * is "dereference", the second is "multiply" */
    var2 = *ptr * 4;
    printf("var=%d, var2=%d, ptr=%p\n", var, var2, (void*) ptr);

    return 0;
}