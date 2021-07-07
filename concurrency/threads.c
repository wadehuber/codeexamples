#include<stdio.h>
#include<threads.h>
#include<unistd.h> 

int global_var = 0;

_Thread_local int thread_counter = 0;

int thread1(void * arg) {
    int ii=1;
    while (ii <= 12) {
        printf("  thread1 %d\n", ii);
        ii++;
        global_var += ii;
        thread_counter ++;
        sleep(1);
    }
    printf("  End of thread1 - global_var=%d  thread_counter=%d\n", 
                  global_var, thread_counter);
    return 0;
}

int thread2(void * arg) {
    thread_counter = 1;
    for (int ii=1;ii<=3;ii++) {
        printf("\t\t  thread2 %d  global_var=%d\n", ii, global_var);
        thread_counter *= ii;
        sleep(3);
    }
    printf("\t\t  End of thread2 - global_var=%d  thread_counter=%d\n", 
                  global_var, thread_counter);
    return 0;
}

int main (void) {
     thrd_t thr1;
     thrd_t thr2;
    int ret1;
    int ret2;
 
    thread_counter = 10;
    printf("Starting threads - global_var=%d  thread_counter=%d\n", 
                  global_var, thread_counter);

    /* Create the threads */
    thrd_create(&thr1, thread1, NULL);
    thrd_create(&thr2, thread2, NULL);

    /* Wait for the threads to complete */
    thrd_join(thr1, &ret1);
    thrd_join(thr2, &ret2);

    printf("\n");
    printf("Threads complete - global_var=%d  thread_counter=%d\n", 
                  global_var, thread_counter);
    printf("  Thread 1 returned %d\n", ret1);
    printf("  Thread 2 returned %d\n", ret2);

    return 0;
}
