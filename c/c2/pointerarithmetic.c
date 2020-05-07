#include<stdio.h>

int main(void) {
  int x = 7;
  int y = 3333;
  int z;
  int * p = &y;

  printf("Initial values:\n");
  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("z: %16d, %p, %lu\n", z, (void *) &z, sizeof(z));
  printf("p: %16p, %p, %lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p); 

  printf("\nz=10:\n");
  z=10;
  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("z: %16d, %p, %lu\n", z, (void *) &z, sizeof(z));
  printf("p: %16p, %p, %lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p); 

  printf("\n*p=12:\n");
  *p=12;
  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("z: %16d, %p, %lu\n", z, (void *) &z, sizeof(z));
  printf("p: %16p, %p, %lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p); 

  /* YMMV - None of this is guaranteed to work on your machine like it did in class */
  printf("\np++:\n");
  p++;
  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("z: %16d, %p, %lu\n", z, (void *) &z, sizeof(z));
  printf("p: %16p, %p, %lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p); 

  printf("\n*p=24:\n");
  *p=24;
  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("z: %16d, %p, %lu\n", z, (void *) &z, sizeof(z));
  printf("p: %16p, %p, %lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p); 

  printf("\n(*p)++:\n");
  (*p)++;
  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("z: %16d, %p, %lu\n", z, (void *) &z, sizeof(z));
  printf("p: %16p, %p, %lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p); 

  printf("\n(*(--p))++:\n");
  (*(--p))++;
  printf("x: %16d, %p, %lu\n", x, (void *) &x, sizeof(x));
  printf("y: %16d, %p, %lu\n", y, (void *) &y, sizeof(y));
  printf("z: %16d, %p, %lu\n", z, (void *) &z, sizeof(z));
  printf("p: %16p, %p, %lu, *p=%d\n", (void *) p, (void *) &p, sizeof(p), *p); 

  return 0;
}
