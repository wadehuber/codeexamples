#include<stdio.h>

#define NUM 10   /* Macro / symbolic constant */

/* enumeration constant */
typedef enum {ONE, TEN=10, ELEVEN, TWENTY=20} numbers_t;

int main(void) {

  int my_int = 30;
  const int my_const = NUM * 2;    /* constant variable */
  int i = NUM;
  int * j = &my_const;
  int * sneaky_ptr = &my_int;
  numbers_t k = TWENTY;
  const int *p = &my_int;
  
  printf("Before:\n");
  printf("i=%d [%p]\n", i, (void *) &i);
  printf("*j=%d j=%p, [%p]\n", *j, (void *)j, (void *) &j);
  printf("*p=%d p=%p, [%p]\n", *p, (void *)p, (void *) &p);
  printf("*sneaky_ptr=%d sneaky_ptr=%p, [%p]\n", 
            *sneaky_ptr, (void *)sneaky_ptr, (void *) &sneaky_ptr);
  printf("k=%d [%p]\n", k, (void *) &k);
  printf("my_int=%d [%p]\n", my_int, (void *) &my_int);
  printf("my_const=%d [%p]\n", my_const, (void *) &my_const);
  printf("NUM=%d\n", NUM);
  printf("ONE=%d\n", ONE);
  printf("TEN=%d\n", TEN);
  printf("ELEVEN=%d\n", ELEVEN);
  printf("TWENTY=%d\n", TWENTY);

  /* Not allowed
   *   my_const ++;
   *   TEN++;
   *   NUM++;
   *   TEN = 11;
   *   (*p)++;
   *   *(&my_const) = 42;
   */

  /* Allowed */
  (*j)++;   /* But not good if j is pointing to a constant! */
  p = &my_const;

  printf("\nAfter (*j)++:\n");
  printf("i=%d [%p]\n", i, (void *) &i);
  printf("*j=%d j=%p, [%p]\n", *j, (void *)j, (void *) &j);
  printf("*p=%d p=%p, [%p]\n", *p, (void *)p, (void *) &p);
  printf("*sneaky_ptr=%d sneaky_ptr=%p, [%p]\n", 
            *sneaky_ptr, (void *)sneaky_ptr, (void *) &sneaky_ptr);
  printf("k=%d [%p]\n", k, (void *) &k);
  printf("my_int=%d [%p]\n", my_int, (void *) &my_int);
  printf("my_const=%d [%p]\n", my_const, (void *) &my_const);
  printf("NUM=%d\n", NUM);
  printf("TEN=%d\n", TEN);

  sneaky_ptr--;
  (*sneaky_ptr)++;
  printf("\nAfter sneaky_ptr--; (*sneaky_ptr)++:\n");
  printf("i=%d [%p]\n", i, (void *) &i);
  printf("*j=%d j=%p, [%p]\n", *j, (void *)j, (void *) &j);
  printf("*p=%d p=%p, [%p]\n", *p, (void *)p, (void *) &p);
  printf("*sneaky_ptr=%d sneaky_ptr=%p, [%p]\n", 
            *sneaky_ptr, (void *)sneaky_ptr, (void *) &sneaky_ptr);
  printf("k=%d [%p]\n", k, (void *) &k);
  printf("my_int=%d [%p]\n", my_int, (void *) &my_int);
  printf("my_const=%d [%p]\n", my_const, (void *) &my_const);
  printf("NUM=%d\n", NUM);
  printf("TEN=%d\n", TEN);

  return 0;
}
