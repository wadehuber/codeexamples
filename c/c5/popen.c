/* Getting output from a system call from C */
/* Note that popen is not Standard C - do not use the std=c11 flag */
#include<stdio.h>
#include<stdlib.h>

#define BUFFER 100 

int main(void) {
    FILE * output;
    char buffer[BUFFER];

    printf("Starting system call . . .\n");
    output = popen("ls -l", "r"); /* execute UNIX command & get output */
    printf("Done with system call\n");

    if (output == NULL) {
	    fputs("POPEN: Failed to execute command.\n", stderr);
    }
    else {
	    while(fgets(buffer, BUFFER-1, output) != NULL) {
		    printf("OUTPUT: %s", buffer);
	    }
    }
    pclose(output);

    return 0;
}
