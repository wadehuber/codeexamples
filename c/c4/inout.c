/* Examples of different ways to perform input & output */
#include<stdio.h>
#include<string.h>

int main(void) {
  char c;
  char outStr[100];
  int ii;

  printf("Read one character with getchar\n");
  c = getchar();
  printf("c = %c, %d\n\n",c,c);
  printf("\nPrint one character with putchar\n");
  putchar(c);
  putchar('\n');

  /* printf examples */
  printf("\nprintf examples\n");
  printf("Integer: %10d, %d\n", 7, 3);
  printf("Character: %10c, %c, %8c, %4c, %d\n", 'k', 'k', 120, 'l', 'l');
  printf("Float: %6.2f, %.1f\n", 2.0/3.0, 3.14);
 
  printf("\nsprintf & puts examples\n");
  /* Similar to printf, but the string is put in "outStr", not written to output 
     This is a convienent way to generate strings based on the value of a variable */
  sprintf(outStr, "Float: %6.2f, %.1f\n", 2.0/3.0, 3.14);
  puts(outStr);
  sprintf(outStr, "Don't tell me to be qui\0et!\n");  /* \0 in middle */
  puts(outStr);

  /* character by character output */
  printf("outStr=[");
  for(ii=0;ii<strlen(outStr);ii++)
     putchar(outStr[ii]);
  printf("]\n");
  
  return 0;

}
