/* Add all numbers passed as command line arguments */
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv[]) {

  int ii;
  int sum=0;

  /* Skip argv[0] since it is the file name */
  for(ii=1;ii<argc;ii++) {
    /* For each argument, convert it to an int and add to the sum */
    /* NOTE: this assumes all arguments are valid ints! */
    sum += atoi(argv[ii]);
  }

  printf("%d\n", sum);
  return 0;
}
