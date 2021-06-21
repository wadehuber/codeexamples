/* Making a system call from C */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main() {

    char cmd1[] = "echo This is a test of the system function";
    char cmd2[] = "ls -l";

    char error1[] = "dosomestuff";
    char error2[] = "ls doesnotexist.txt";

    int rc;

    printf("Start of system call %s:\n", cmd1);
    printf("================================================================================\n");
    rc = system(cmd1);
    printf("================================================================================\n");
    printf("Done with system call. Return code=%d\n", rc);
    printf("\n");

    printf("Start of system call %s:\n", error1);
    printf("================================================================================\n");
    rc = system(error1);
    printf("================================================================================\n");
    printf("Done with system call. Return code=%d\n", rc);
    printf("\n");

    printf("Start of system call %s:\n", error2);
    printf("================================================================================\n");
    rc = system(error2);
    printf("================================================================================\n");
    printf("Done with system call. Return code=%d\n", rc);
    printf("\n");

    printf("Start of system call %s:\n", cmd2);
    printf("================================================================================\n");
    rc = system(cmd2);
    printf("================================================================================\n");
    printf("Done with system call. Return code=%d\n", rc);
    printf("\n");

    return 0;
}
