/* Simple command line calculator */
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]) {
    int sum = 0;

    /* Skip argv[0] since that that command name */
    for(int ii=1;ii<argc;ii++) {
        /* For each argument, convert it to an int and add to the sum */
        /* NOTE: this assumes all arguments are valid ints! */
        sum += atoi(argv[ii]);
    }

    printf("%d", sum);
    return 0;
}
