/* Examples of different ways to perform input & output in C */
#include<stdio.h>
#include<string.h>

int main(void) {
    char c;
    char outStr[100];

    printf("read one character with getchar()\n");
    c = getchar();
    printf("c=%c, %d\n", c, c);
    printf("putchar(c): ");
    putchar(c);
    putchar('\n');
    
    /* printf examples */
    printf("\n");
    printf("printf examples:\n");
    printf("  Integer: %d, %10d, %o, %X\n", 29, 29, 29, 29);
    printf("  Character: %c, %5d, %5c, %5d\n", 'r', 'r', 120, 120);
    printf("  Float: %6.2f, %.1f\n", 2.0/3.0, 2.0/3.0);

    printf("\n");
    printf("sprintf & puts examples:\n");
    sprintf(outStr, "  Float: %6.2f, %.1f\n", 2.0/3.0, 2.0/3.0);
    puts(outStr);
    sprintf(outStr, "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ");
    sprintf(outStr, "Don't tell me to be qu\0iet!");  /* null-terminator in the middle */
    puts(outStr);

    /* character-by-character output */
    printf("\n");
    printf("outStr:\n");
    for (int ii=0;ii<100;ii++) {
        putchar('[');
        putchar(outStr[ii]);
        putchar(']');
        if ((ii+1) % 25 == 0) {
            putchar('\n');
        }
    }

    return 0;
}
