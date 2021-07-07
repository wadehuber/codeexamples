#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h> 

int main(void) {
    int n = 0; 
    int pid;
    pid_t childwait;

    printf("Before fork: n=%d\n", n);
    sleep(1);

    /* fork the process
         returns child PID to the parent process
         return 0 to the child process
    */
    pid = fork();

    /* Child process */
    if (pid == 0) {
        n = 1;
        printf("\t\t\t\tChild process:\n");
        printf("\t\t\t\t  n=%d, PID=%d\n", n, pid);
        while (n < 10) {
            printf("\t\t\t\t  n=%d\n", n);
            n++;
            sleep(1);
        }
        printf("\t\t\t\tChild complete..\n");
    }
    /* Parent process */
    else {
        printf("\tParent process:\n");
        printf("\t  n=%d, PID=%d\n", n, pid);
        while (n <= 50) {
            printf("\t  n=%d\n", n);
            n += 10;
            sleep(1);
        }
        printf("\tParent: waiting for child.\n");
        wait(&childwait);
        printf("\tParent: child complete.\n");
        printf("\tParent: complete.\n");

    }

    sleep(2); 

    exit(0);
}
