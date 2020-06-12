/* Making a system call from C */

#include<stdio.h>
#include<stdlib.h>

int main() {

    printf("Starting system call . . \n");
    int rc;
    rc = system("ls -l");   /* execute the Linux command to list directory contents */
    printf("Done with system call. Return code=%d\n", rc);

    return 0;
}
