#include<stdio.h>

int main() {
  unsigned int i = 8;

  printf("i = %x\n", i);
  i = i << 2;
  printf("i = %x  (i << 2)\n", i);
  i = i >> 4;
  printf("i = %x  (i >> 4)\n", i);
  i = i << 2;
  printf("i = %x  (i << 2)\n", i);

  printf("\nBitwise operators:\n");
  printf("i & 1 = %x\n", i & 1);  /* Logical AND */
  printf("i | 1 = %x\n", i | 1);  /* Logical OR */
  printf("i ^ 1 = %x\n", i ^ 1);  /* Logical XOR */
  printf("i ^ i = %x\n", i ^ i);  /* Logical XOR */
  printf("i & 9 = %x\n", i & 9);  /* Logical AND */
  printf("i | 9 = %x\n", i | 9);  /* Logical OR */
  printf("i ^ 9 = %x\n", i ^ 9);  /* Logical XOR */
  return 0;
}
