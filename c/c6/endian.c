#include<stdio.h>

int main() {
  /* only low order bit in n is set */
  unsigned int n = 1;
  /* c will be set to the first byte in the representation of n*/
  char *c = (char *) &n;

  /* C will be 1 if little endian (low order byte first */
  if (*c) {
    printf("Little endian\n");
  }
  /* C will be 0 if big endian (high order byte first */
  else {
    printf("Big endian\n");
  }

  return 0;
}
