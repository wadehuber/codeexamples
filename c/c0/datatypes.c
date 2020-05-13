/* C data types */
#include <stdio.h>
#include <limits.h>

int main(void) {
    int x = 59;            /* integer literal */
    int y = 0x0A;          /* hexidecimal literal */
    int z = 013;           /* octal literal */
    
    unsigned int a = -40;  /* what happens here? a is unsigned! */
    long int b = 10000000;
    
    char c = 'A';          /* character literal */
    char k = 66; 
    
    char s[] = "Hello!";   /* string literal */
    
    float f = 10.0 / 3.0;  /* floating point literals */    
    double d = 3.14159;    /* double-precision float */

    /* To print variables in C, you use a control sequence to represent the
         variable's place in the string, then include a list of the variables
         you want to print after the string.
       Examples of printf control sequences
         %d - integer
         %x - hexidecimal
         %o - octal
         %u - unsigned
         %c - character
         %f - floating point
         %s - string
    */

    printf("x = %d (%X hex) (%o octal)\n", x, x, x);
    printf("y = %d (%X hex) (%o octal)\n", y, y, y);
    printf("z = %d (%X hex) (%o octal)\n", z, z, z);

    printf("a = %u (%d signed) (%X hex)\n", a, a, a);
    printf("b = %lu\n", b);

    printf("c = %c (%d int) (%X hex)\n", c, c, c);
    printf("k = %c (%d int) (%X hex)\n", k, k, k);

    printf("f = %f (%.2f formatted)\n", f, f);
    printf("d = %f (%.2f formatted)\n", d, d);

    printf("s = %s\n", s);

    /* int vs char */
    printf("Hex: 100 - A = %d\n", 100-0xA);
    printf("Char: 100 - A = %d\n", 100-'A');

    for(z=0;z<26;z++) {
        printf("%c", 'A' + z);
    }
    printf("\n");

    printf("%10d %5c %10.2f\n", x, c, f);

    printf("\n");
    printf("Data types & sizes\n");
    printf("         char:\tsize=%ld\tmin=%d\tmax=%d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("          int:\tsize=%ld\tmin=%d,\tmax=%d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("        short:\tsize=%ld\tmin=%d,\t\tmax=%d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("         long:\tsize=%ld\tmin=%ld,\tmax=%ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("unsigned long:\tsize=%ld\tmax=%lu\n", sizeof(unsigned long), ULONG_MAX);
    printf("        float:\tsize=%ld\n", sizeof(float));
    printf("       double:\tsize=%ld\n", sizeof(double));

    return 0;
}
