#include<stdio.h>
#include<string.h>

#define SIZE 16

int main(void) {
   char str1[SIZE];
   char str2[SIZE];
   char str3[SIZE];

   strncpy(str1, "XXXXXXXXXXXXXXX", SIZE);
   strncpy(str2, "YYYYYYYYYYYYYYY", SIZE);
   strncpy(str3, "ZZZZZZZZZZZZZZZ", SIZE);

   printf("Before:\n");
   printf("  str1: %s\n", str1);
   printf("  str2: %s\n", str2);
   printf("  str3: %s\n", str3);

   printf("\nEnter a string: ");
   /* gets is dangerous!  
    * Try to enter a long character string here and see what happens
      gets(str2);
    */

   fgets(str2, SIZE, stdin);

   printf("\nAfter:\n");
   printf("  str1: %s\n", str1);
   printf("  str2: %s\n", str2);
   printf("  str3: %s\n", str3);

   return 0;
}
