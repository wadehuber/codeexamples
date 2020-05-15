#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

int main(int argc, char * argv[]) {
  FILE *numberlist;
  char buffer[SIZE];
  int ii = 1;
  int sum=0;
  char * input;

  if (argc < 2) {
    fputs("Missing filename to read\n", stderr);
    exit(-1);
  }
  numberlist = fopen(argv[1], "r");
  while ( fgets(buffer, SIZE, numberlist) ) {
     /* the first call to strtok with a buffer tokenizes that string */
     /*printf("Read buffer: %s", buffer); */
     input = strtok(buffer, " ");
     sum = 0;
     while(input != NULL) {
       sum += atoi(input);
       /* subsequent calls to strtok with NULL will get the next token */
       input = strtok(NULL, " ");
     }
     printf("[%d] sum=%d\n",ii,sum);
     ii++;
  }

  fclose(numberlist);

  return 0;
}
