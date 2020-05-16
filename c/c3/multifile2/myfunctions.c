#include<stdio.h>

#include"myfunctions.h"

int myNum = 0;

void init(void) {
  myNum = 0;
  printf("initializing, myNum = %d\n", myNum);
}

int addone(int n) {
  myNum++;
  return (n+1);
}

void doubleIt(int * n) {
  myNum *= 2;
  *n = *n * 2;
}

int factorial(int n) {
  myNum ++;
  if (n <= 1)
    return 1;
  else
    return (n * factorial(n-1));
}

#ifdef TEST
int main(void) {
  int a = 10;

  printf ("myNum = %d, a=%d\n", myNum, a);
  init();
  addone(a);
  printf("addone(a) = %d\n", addone(a)); 
  printf("addone(20) = %d\n", addone(20)); 
  printf ("myNum = %d, a=%d\n", myNum, a);
  doubleIt(&a);
  printf ("myNum = %d, a=%d\n", myNum, a);
  printf("10! = %d\n", factorial(10)); 
  printf ("myNum = %d, a=%d\n", myNum, a);

  return 0;
}
#endif
