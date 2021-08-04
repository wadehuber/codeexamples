/* Macro examples */
/* Compile with gcc -E to see preprocessed code */

#include<stdio.h>

#define MAX 10

/* macros */
#define triple(a) a * 3
#define absm(a) ( (a<0) ? -(a) : a )

/* function */
int absf(int a) {
    if (a<0)
        return a * -1;
    else
         return a;
}

int main(void) {
    int j = MAX;
    int k = MAX * -1;
    int m = -8;
    int n = triple(4);

    printf("Original:\n");
    printf("j=%d, k=%d, m=%d, n=%d\n", j, k, m, n);

    printf("\nCalling absf (function):\n");
    printf("absf(%d)=%d\n", j, absf(j));
    printf("absf(%d)=%d\n", k, absf(k));
    printf("j=%d, k=%d, m=%d, n=%d\n", j, k, m, n);

    printf("\nCalling absm (macro):\n");
    printf("absm(%d)=%d\n", j, absm(j));
    printf("absm(%d)=%d\n", k, absm(k));
    printf("j=%d, k=%d, m=%d, n=%d\n", j, k, m, n);

    printf("\nCalling absf (function):\n");
    printf("absf(++%d)=%d\n", j, absf(++j));
    printf("absf(++%d)=%d\n", k, absf(++k));
    printf("j=%d, k=%d, m=%d, n=%d\n", j, k, m, n);

    printf("\nCalling absm (macro):\n");
    printf("absm(++%d)=%d\n", j, absm(++j));
    printf("absm(++%d)=%d\n", k, absm(++k));
    printf("j=%d, k=%d, m=%d, n=%d\n", j, k, m, n);

    return 0;
}
