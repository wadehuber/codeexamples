/* example of a C program that accepts command line arguments */
#include<stdio.h>

/* argc is the number of arguments, argv is an array of pointers to each arg */
/* note that each arg is passed as a string */
int main(int argc, char * argv[]) {

  int ii;

  /* Print the number of arguments passed to our program */
  printf("argc = %d\n", argc);


  /* Print each indivual argument.  arg[0] is the name of the command */
  for(ii=0;ii<argc;ii++) {
    printf("argv[%d] = %s\n", ii, argv[ii]);
  }
  return 0;
}
