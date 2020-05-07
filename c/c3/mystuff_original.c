#include<stdio.h>

/* Macros */
#define NUM 10
#define MAX(a,b) ( (a) > (b) ) ? (a) : (b)

/* Forward declaration */
int max_of_three(int a, int b, int c);

int main(void) {
  printf("Max1: %d\n", MAX(20, 13));
  printf("Max2: %d\n", MAX(NUM, 13));
  printf("Max3: %d\n", max_of_three(20, 13, NUM));
  return 0;
}

int max_of_three(int a, int b, int c) {
  if ( (a > b) && (a > c) ) 
    return a;
  else if (b > c) 
    return b;
  return c;
}
