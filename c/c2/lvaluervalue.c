#include <stdio.h>

int main(void) {
    int x = 5;        /* x is a modifiable lvalue */
    const int y = 7;  /* y is a non-modifiable lvalue */

    x = 10;           /* OK: x can appear on the left side of = */
    x = y;            /* OK: y can be read as a value */

    /*
       x = y means "store the value of y into the location named x"

       So:
         - x must be a writable location
         - y only needs to produce a value
    */

    /*
       lvalue:
         An expression that refers to an object in memory.
         It can appear on the left side of = only if it is modifiable.

       rvalue:
         A value used in an expression.
         It cannot be assigned to directly.
    */

    /* These would cause compilation errors: */
    /*
       y = x;      // ERROR: y is const, so it is not modifiable
       10 = x;     // ERROR: 10 is not an lvalue
       x + 1 = y;  // ERROR: x + 1 produces a value, not a storage location
    */

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}