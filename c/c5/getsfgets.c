#include<stdio.h>
#include<string.h>

#define SIZE 16

void gets_vs_fgets() {
   char str1[SIZE];
   char str2[SIZE];
   char str3[SIZE];

   strncpy(str1, "XXXXXXXXXXXXXXXX", SIZE-1);
   strncpy(str2, "YYYYYYYYYYYYYYYY", SIZE-1);
   strncpy(str3, "ZZZZZZZZZZZZZZZZ", SIZE-1);

   printf("str1: %s\n", str1);
   printf("str2: %s\n", str2);
   printf("str3: %s\n", str3);

   printf("\nEnter a string of %d characters: ", SIZE-1);
   /* This is dangerous! Try to enter a long (> 20 character line here and see what happens */
   /*
   gets(str2);
   */
   /* This is the right way */
   fgets(str2, SIZE, stdin);

   printf("str1: %s\n", str1);
   printf("str2: %s\n", str2);
   printf("str3: %s\n", str3);
}

int main(void) {
   gets_vs_fgets();
   return 0;
}
