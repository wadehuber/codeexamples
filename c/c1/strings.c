#include <stdio.h>

int main(void) {
  char str1[] = "Hello";   /* string (null-terminated character array) */
  char str2[] = {'W', 'o', 'r', 'l', 'd'}; /* character array (not a string!) */
  char str3[] = {'e', 'n', 'd', '\0'}; /* null-terminated char array (a string!) */
  char str4[] = "This is a really long string.  Maybe too long?";
  int ii;

  printf("str1: %s \t %lu\n", str1, sizeof(str1));
  printf("str2: %s \t %lu\n", str2, sizeof(str2));
  printf("str3: %s \t %lu\n", str3, sizeof(str3));
  printf("str4: %s \t %lu\n", str4, sizeof(str4));

  printf("\nPrint 20 bytes starting at str2;\n");
  for(ii=0;ii<20;ii++) {
    printf("str2[%d]=%c (%d)\n", ii, str2[ii], str2[ii]);
  }

  printf("\nstr4[29] = '\\0';\n");
  str4[29] = '\0';
  printf("str4: %s \t %lu\n", str4, sizeof(str4));

  for(ii=0;ii<100;ii++) {
    printf("[%2c] ", str4[ii]);
    if ((ii+1) % 16 == 0) {
      printf("\n");
    }
  }
  printf("\n");

  return 0;
}
