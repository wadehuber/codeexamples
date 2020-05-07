#include<stdio.h>

int main(void) {
  int a = -1;
  unsigned int b = 1;

  printf("a=%d\n",a);
  printf("b=%d\n",b);
  printf("\n");

  if (a<b) {
    printf("a is less than b\n");
  }
  else {
    printf("a is greater than b\n");
  }

  if (b<a) {
    printf("b is less than a\n");
  }
  else {
    printf("b is greater than a\n");
  }

  printf("\n");
  printf("a=%u\n",a);
  printf("b=%u\n",b);

  return 0;
}
