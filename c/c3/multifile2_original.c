#include<stdio.h>

/* symbolic constants */
#define MULTIPLE 7
#define SIZE 10

/* inline functions */
#define triple(a) a*3
#define absm(a) ( (a<0) ? -(a) : a)
#define MAX(A,B)  (((A) > (B)) ? (A) : (B))

/* forward declarations */
void init_counter(void);
int addone(int n);
void doubleIt(int * n);
int factorial(int n);

int counter = 0;

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

  return 0;
}

void init_counter(void) {
  counter = 0;
}

int get_counter(void) {
    return counter;
}

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
