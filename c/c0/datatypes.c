/* C data type examples */
#include<stdio.h>

int main(void) {
  int x = 59;            /* Integer literal */
  int y = 0x0A;          /* Hexidecimal literal */
  int z;
  unsigned int a = -40;  /* What happens here? */
  char c = 'A';          /* Character literal */
  char k = 66;
  char s[] = "Hello!";   /* String literal */
  float f = 10.0 / 3.0;  /* Float literals */
 

  /* To print variables in C, you use a control sequence to represent the
       variable's place in the string, then include a list of the variables
       you want to print after the string. */
  /* Examples of printf control sequences 
     %d - integer
     %x - hexidecimal
     %u - unsigned
     %c - character
     %f - floating point
     %s - string
  */
  printf("x = %d (%x hex)\n", x, x);
  printf("y = %x (%d dec)\n", y, y);
  printf("a = %u (%d int) (%x hex)\n", a, a, a);
  printf("c = %c (%d int) (%x hex)\n", c, c, c);
  printf("k = %c (%d int) (%x hex)\n", k, k, k);
  printf("f = %f (%.2f formatted)\n", f, f);
  printf("s= %s\n", s);
  /* Note that z has not been initialized.  What happens if we 
   *  uncomment out the next line? */
  /*
  printf("z = %d (%x hex)\n", z, z);
  */
  z = x + y;
  printf("z = %d (%x hex)\n", z, z);

  /* int vs char */
  printf("\nHex: 100 - A = %d\n", 100-0xA);
  printf("Char: 100 - A = %d\n", 100-'A');
  for(z=0;z<26;z++) {
     /* We can add an integer to a character literal */
     printf("%c ", 'A' - z);
  }
  printf("\n");

  return 0;
}
