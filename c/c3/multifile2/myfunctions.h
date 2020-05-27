#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

/* symbolic constants */
#define MULTIPLE 7
#define SIZE 10

/* inline functions */
#define TRIPLE(a) (a)*3
#define ABSM(a) ( ((a)<0) ? -((a)) : (a))
#define MAX(A,B)  (((A) > (B)) ? (A) : (B))

/* forward declarations */
void init_counter(void);
int get_counter(void);
int addone(int n);
void doubleIt(int * n);
int factorial(int n);

#endif
