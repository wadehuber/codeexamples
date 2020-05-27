#include<stdio.h>
#include"myfunctions.h"

int counter = 0;

/* counter functions */
void init_counter(void) {
  counter = 0;
}

int get_counter(void) {
    return counter;
}

/* general functions */
int addone(int n) {
  counter ++;
  return (n+1);
}

void doubleIt(int * n) {
  counter ++;
  *n = *n * 2;
}

int factorial(int n) {
  counter  ++;
  if (n <= 1)
    return 1;
  else
    return (n * factorial(n-1));
}

#ifdef TEST
int main(void) {
  int a = 10;

  printf ("counter=%d, a=%d\n", counter, a);
  init_counter();
  addone(a);
  printf("addone(a)=%d\n", addone(a)); 
  printf("addone(20)=%d\n", addone(20)); 
  printf ("counter=%d, a=%d\n", counter, a);
  doubleIt(&a);
  printf ("counter=%d, a=%d\n", counter, a);
  printf("10!=%d\n", factorial(10)); 
  printf ("counter=%d, a=%d\n", counter, a);

  printf("\nTesting inline functions:\n");
  printf("  TRIPLE(a) = %d\n", TRIPLE(a));
  printf("  ABSM(a) = %d\n", ABSM(a));
  printf("  ABSM(-10) = %d\n", ABSM(-10));
  printf("  MAX(-10,5)) = %d\n", MAX(-10,5));
  printf("  MAX(11,5)) = %d\n", MAX(11,5));

  return 0;
}
#endif
