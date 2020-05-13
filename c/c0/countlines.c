/* 
 * Count the number of newline characters in a file
 * Enter control-d to pass an EOF character to input 
 */

#include<stdio.h>

int main(void) {
    int c;      /* input character */
    int nl = 0; /* counter for number of newlines */

    /* While the input character is not the End of File character */
    while ( (c = getchar()) != EOF ) {
        /* If the input character is a newline, increment the counter */
        if (c == '\n') {
            nl++;
        }
    }

    printf("There were %d newlines.\n", nl);

    return 0;
}
