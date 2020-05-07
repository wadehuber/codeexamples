#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/wait.h>

int main(int argc, char*argv[]) {
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
    sleep(1);

    /* Child process */
    if (pid == 0 ) {  
        printf("\t\t\t\tChild process:\n");
        printf("\t\t\t\t  n=%d, PID=%d:\n", n, pid);
        while (n < 10) {
            printf("\t\t\t\t  C=%d\n", n);
            n++;
            sleep(1);
        }
        sleep(2);
        printf("\t\t\t\tChild: complete, n=%d\n", n);
    }

    /* parent process */
    else {
        printf("\tParent process:\n");
        printf("\t  n=%d, PID=%d:\n", n, pid);
        while (n < 5) {
            printf("\t  P=%d\n", n);
            n++;
            sleep(1);
        }
        printf("\tParent: waiting for child\n");
        fflush(stdout);
        wait(&childwait);
        printf("\tParent: child complete, n=%d\n", n);
        fflush(stdout);
        sleep(1);
        printf("\tParent: complete, n=%d\n", n);


    }
    printf("PID = %d\n",pid);
    printf("After fork: n=%d\n", n); 
    sleep(1);

    exit(0);
}
