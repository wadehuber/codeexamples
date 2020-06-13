#include<stdio.h>
/* For gdb example - compile with -g flag */

struct thing {
  int a;
  char c[8];
};

void problem2() {
  /*  Next line would be a bug
  int k = 0;
  */
  int k = 2;
  int a = 10 / k;
  printf("k=%d, a=%d\n", k, a);
}

void problem1() {
  problem2();
}

int main(void) {
  int a = 10, ii;
  struct thing s = {50, "Hello!"};
  struct thing * ptr = &s;

  for (ii=0;ii<10;ii++) {
    printf("a=%d\n", ++a);
  }

  problem1();

  printf("ptr=%d %s\n", ptr->a, ptr->c);
  return 0;
}

