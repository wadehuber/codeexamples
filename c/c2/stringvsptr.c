#include<stdio.h>

int main(void) {
  char *p = "Hello"; 
  char *s = "this is a string";
  char t[] = "Also a string";

  printf("\n==== print string ====\n");
  printf("p [%p]: %14p, %s\n", (void *) &p, (void *) p, p);
  printf("s [%p]: %14p, %s\n", (void *) &s, (void *) s, s);
  printf("t [%p]: %14p, %s\n", (void *) &t, (void *) t, t);

  printf("\n==== print character ====\n");
  printf("p [%p]: %14p, %c [%d]\n", (void *) &p, (void *) p, *p, *p);
  printf("s [%p]: %14p, %c [%d]\n", (void *) &s, (void *) s, *s, *s);
  printf("t [%p]: %14p, %c [%d]\n", (void *) &t, (void *) t, *t, *t);

  printf("\n==== print string+1 ====\n");
  printf("p : %14p, %s\n", (void *) (p+1), p+1);
  printf("s : %14p, %s\n", (void *) (s+1), s+1);
  printf("t : %14p, %s\n", (void *) (t+1), t+1);

  printf("\n==== print character+1 ====\n");
  printf("p : %c [%d]\n", *(p+1), *(p+1));
  printf("s : %c [%d]\n", *(s+1), *(s+1));
  printf("t : %c [%d]\n", *(t+1), *(t+1));

  printf("\n==== print character+8 ====\n");
  printf("p : %c [%d]\n", *(p+8), *(p+8));
  printf("s : %c [%d]\n", *(s+8), *(s+8));
  printf("t : %c [%d]\n", *(t+8), *(t+8));

  printf("\n==== pointer arithmetic vs array indexing ====\n");
  printf("s: [%p] %c\n", (void *) &s, *(s+12));
  printf("s: [%p] %c\n", (void *) &s, s[12]);

  printf("\n==== print string using pointer arithmetic : s=p ====\n");
  s=p;
  while(*s != '\0') {
    printf("[%c]", *s);
    s++;
  }
  printf("\n");
 
  return 0;
}
