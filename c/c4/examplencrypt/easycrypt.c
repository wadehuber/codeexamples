/*
 * To compile:
 *    gcc --std=c11 -pedantic -Wall easycrypt.c -o encrypt
 *    gcc --std=c11 -pedantic -Wall easycrypt.c -D DECRYPT -o decrypt
 *
 * Sample outpu:
 * $ echo "This is a test" | ./encrypt 
 * Uijt!jt!b!uftu
 *
 * [student@localhost class6]$ echo "This is a test" | ./encrypt | ./decrypt 
 * This is a test
 */
#include<stdio.h>

#ifdef DECRYPT
#define OP -
#else
#define OP +
#endif

unsigned int easyendecrypt(char c);

int main(void) {
  int c;

  while ( (c = getc(stdin)) != EOF) {
    printf("%c", easyendecrypt(c));
  }

  printf("\n");
  return 0;
}

unsigned int easyendecrypt(char c) {
  return c OP 1;
}
