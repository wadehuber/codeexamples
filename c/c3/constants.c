#include<stdio.h>

#define NUM 10   /* Macro / symbolic constant */

/* enumeration constant */
typedef enum {ONE, TEN=10, ELEVEN, TWENTY=20} numbers_t;

int main(void) {

    int my_int = 30;
    const int my_const = NUM * 2;   /* constant variable */

    int i = NUM;
    const int * j = &my_const;
    numbers_t k = TWENTY;
    const int *p = &my_int;

    printf("Values:\n");
    printf("i=%d [%p]\n", i, (void *) &i);
    printf("*j=%d j=%p, [%p]\n", *j, (void *)j, (void *) &j);
    printf("*p=%d p=%p, [%p]\n", *p, (void *)p, (void *) &p);
    printf("k=%d [%p]\n", k, (void *) &k);
    printf("my_int=%d [%p]\n", my_int, (void *) &my_int);
    printf("my_const=%d [%p]\n", my_const, (void *) &my_const);
    printf("NUM=%d\n", NUM);
    printf("ONE=%d TEN=%d  ELEVEN=%d  TWENTY=%d\n", ONE, TEN, ELEVEN, TWENTY); 

    /* Not allowed:
         my_const++;
         TEN++;
         NUM++;
         TEN = 21;
         (*p)++;
         *(&my_const) = 42;
         (*j)++;   // This WILL be allowed if j is not a const ptr (warning only)
     */

    printf("*j=%d j=%p, [%p]\n", *j, (void *)j, (void *) &j);
    printf("my_const=%d [%p]\n", my_const, (void *) &my_const);

    return 0;
}
