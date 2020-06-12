#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
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
    }
    numberlist = fopen(argv[1], "r");
    if (numberlist == NULL) {
        fprintf(stderr, "Unable to open file %s  errno=%d\n", argv[1], errno);
        exit(-1);
    }
    sum = 0;
    while ( fgets(buffer, SIZE, numberlist) ) {
         /* the first call to strtok with a buffer tokenizes that string */
         /*printf("Read buffer: %s", buffer); */
         input = strtok(buffer, " ");
         while(input != NULL) {
             sum += atoi(input);
             /* subsequent calls to strtok with NULL will get the next token */
             input = strtok(NULL, " ");
         }
#ifdef DEBUG
         printf("[%d] sum=%d\n",ii,sum);
#endif
         ii++;
    }
    printf("Total = %d\n", sum);

    fclose(numberlist);

    return 0;
}
