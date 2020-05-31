/* example of a C program that takes command-line arguments */
#include<stdio.h>

/* argc is the number of arguments, argv is a string array of each argument
 * (Note that each argument is passed as a string
 */
int main(int argc, char * argv[]) {
    
    /* Print the number of arguments passed to our function */
    printf("argc = %d\n", argc);

    /* Print each individual argument.  argv[0] is the name of the command */
    for(int ii=0;ii<argc;ii++) {
        printf("argv[%d] = %s\n", ii, argv[ii]);
    }
    
    return 0;
}
