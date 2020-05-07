/* Examples of recursion in C */
#include<stdio.h>

#define MAX 25

int counter[MAX];
int fibtail_helper(int, int, int);

/* iterative */
int fibwhile(int n) {
  int f = 1, f1 = 1, f2 = 1;
  int ii = n;
  while (ii > 2) {
    f = f1 + f2;
    f2 = f1;
    f1 = f;
    ii--;
  }
  return f;
}

/* Recursive */
int fib(int n) {
  counter[n]++;
  if (n <= 0) {
    return 0;
  }
  else if (n <= 1) {
    return 1;
  }
  else {
    return(fib(n-1) + (fib(n-2)));
  }
}

/* Tail-recursion */
int fibtail(int n) {
  return fibtail_helper(n, 0, 1);
}

int fibtail_helper(int n, int f2, int f1) {
  counter[n]++;
  if (n <= 1) {
    return f1;
  }
  else {
    return(fibtail_helper(n-1, f1, f1+f2));
  } 
}

int main(void) {
  int ii;
  for (ii=0;ii<MAX;ii++) {
    counter[ii]=0;
  }

  /*
  printf("fib(%d)=%d\n", MAX, fib(MAX));
  */
  printf("fibtail(%d)=%d\n", MAX, fibtail(MAX));

  for (ii=0;ii<MAX;ii++) {
    printf("counter[%d] = %d\n", ii, counter[ii]);
  }

  return 0;
}
