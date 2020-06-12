#include<stdio.h>
#include<stdlib.h>

#define BUFFER 100 

int main(void) {

    FILE *output;
    char buffer[BUFFER];

    printf("Starting system call . . \n");
    output = popen("ls -l", "r");  /* execute Linux command & get output */
    printf("Done with system call\n");

    if (output == NULL) {
        fputs("POPEN: Failed to execute command.\n", stderr);
    }
    else {
        int count = 1;
        while(fgets(buffer, BUFFER-1, output) != NULL) {
            printf("OUTPUT[%d]: %s", count, buffer);
            count ++;
        }
    }
    pclose(output);

    return 0;
}
