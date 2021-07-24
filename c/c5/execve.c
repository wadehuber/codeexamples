/* Making a system call from C */

#include<stdio.h>
#include<unistd.h>

int main(void) {

    /* 
    char cmd[] = "/usr/bin/ls";
    char cmd[] = "./userscript.sh";
    */
    char cmd[] = "./args.out";

    char * argVec[] = {"args.out", "arg1", "arg2", "3", NULL};
    char * envVec[] = {"CSC220=Linux", "SECRET=Study Hard", NULL};

    printf("Start of execve call %s:\n", cmd);
    printf("==============================================================\n");
    if (execve(cmd, argVec, envVec) == -1) {
        perror("Could not execute execve");
    }
    printf("Oops, something went wrong!");
  
    return 0;
}
