#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define SIZE 100

int main(int argc, char * argv[]) {
    char buffer[SIZE];
    FILE *numberfile;
    int sum=0;
    int ii=0;
    char * number;

    if (argc < 2) {
        fputs("Missing filename to read\n", stderr);
        exit(-1);
    }

    numberfile = fopen(argv[1], "r");
    if (numberfile == NULL) {
        /* perror prints the string + the errno error 
         * perror("Error while opening file"); 
         */
        fprintf(stderr, "Error while opening \"%s\": %s\n", argv[1], 
                                                        strerror(errno));
        exit(-1);
    }

    ii = 1;
    while ( fgets(buffer, SIZE, numberfile) ) {
        /* The first call to strtok with a buffer tokenizes that string */
        number = strtok(buffer, " ");
        while(number != NULL) {
            /* subsequent calls to strtok with NULL will get the next token */
            sum += atoi(number);
            number = strtok(NULL, " ");
        }

#ifdef DEBUG
        printf("\n[line %d] sum=%d\n", ii, sum);
#endif
        ii++;
    }

    printf("\nTotal = %d\n", sum);
    fclose(numberfile);

    return 0;
}
