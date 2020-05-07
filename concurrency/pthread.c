#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> 

/* To compile: 
 *    gcc --std=c11 -pedantic -Wall pthread.c
 *    (you may also need to include -lpthread to pull in the thread library 
 */

void *count_to_ten(void *x) {
    int ii;
    printf("\t\t\t\tThread:\n");
    for (ii=0;ii<10;ii++) {
        printf("\t\t\t\tx=%d\n", (*(int *)x)++);
        fflush(stdout);  /* Force all output to the console */
        sleep(1);
    }
    printf("\nThread finished!\n");
    return NULL;
}

int main() {
  int x = 0;
  int y = 0;
  int rc;
  pthread_t new_thread;

  printf("Before:\n");
  printf("  x=%d at %p\n",x, (void *) &x);
  printf("  y=%d at %p\n",y, (void *) &y);

  /* count_to_ten(&x); */
  rc = pthread_create(&new_thread, NULL, count_to_ten, &x);
  if (rc != 0) {
      fprintf(stderr, "ERROR code %d calling pthread_create\n", rc);
      exit(-1);
  }
 
  printf("\t\t\tMain:\n");
  for(int ii=0;ii<5;ii++) {
      printf("\t\t\ty=%d\n",y);
      y++;
      sleep(1);
  }

  /* Wait for the thread to exit */
  if (pthread_join(new_thread, NULL)) {
      fprintf(stderr, "Error joining pthread\n");
      exit(-1);
  }

  printf("After:\n");
  printf("  x=%d at %p\n",x, (void *) &x);
  printf("  y=%d at %p\n",y, (void *) &y);

  return(0);

}
