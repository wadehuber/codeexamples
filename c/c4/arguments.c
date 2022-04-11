/* example of a C program that takes command-line arguments */
#include<stdio.h>

/* 
   argc is the number of arguments
   argv is an array of strings holding each argument
     (note that each argument is passed as a string)
*/
int main(int argc, char * argv[]) {

    /* Print the number of argumnts passed to our program */
    printf("argc = %d\n", argc);

    /* Print out each argument */
    for (int ii=0;ii<argc;ii++) {
        printf("argv[%d] = %s\n", ii, argv[ii]);
    }
    
    return 0;
}
