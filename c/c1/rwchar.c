#include<stdio.h>

/* Example of character input & output */

int main(void) {
    int in_char;
    char c;

    printf("Enter a series of characters ");
    /* getchar() reads a single character from standard input 
     * we loop until we see a newline
     */
    do {
        in_char = getchar();
        printf ("[%d]", in_char);
    }
    while (in_char != '\n');

    /* getc works like getchar() but you specify where to read the character
     * You can read from stdin (standard input) or a file
     * putc writes to a file, in this case stdout (standard output)
     */
    printf("\nEnter a word : ");
    do {
        in_char = getc(stdin);
        putc(in_char, stdout);
    }
    while (in_char != '\n');

    return 0;
}
