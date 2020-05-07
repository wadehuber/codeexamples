/* Macro examples */
/* Compile with gcc -E to see preprocessed code */
#include<stdio.h>

#define MAX 10
#define triple(a) a*3

/* macro - inline function */
#define absm(a) ( (a<0) ? -(a) : a)

/* function */
int absf(int a) {
  if (a<0)
    return a * -1;
  else
     return a;
}

int main() {

  int j=MAX;
  int k=MAX * -1;
  int m=-8;
  int n = triple(4);

  printf("j=%d, k=%d, m=%d, n=%d\n",j,k,m,n);

  printf("absf(j++) = %d \n",absf(j++));
  printf("absf(k++) = %d \n",absf(k++));

  printf("j=%d, k=%d, m=%d, n=%d\n",j,k,m,n);

  printf("absm(j++) = %d \n",absm(j++));
  printf("absm(k++) = %d \n",absm(k++));

  printf("j=%d, k=%d, m=%d, n=%d\n",j,k,m,n);

  return 0;
}
