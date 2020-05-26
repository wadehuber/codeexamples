/* Examples of recursion in C */
#include<stdio.h>

#define MAX 26
int counter[MAX];

int fibtail_helper(int, int, int);

/* Fib(1) = 1
 * Fib(2) = 1 
 * Fib(N) = Fib(N-1) + Fib(N-2)
 */

/* Iterative */
int fibwhile(int n) {
    int f=1, f1=1, f2=1;
    int ii = n;

    while (ii>2) {
        f = f1 + f2;
        f2 = f1;
        f1 = f;
        ii--;
    }
    return f;
}

/* Recursive */
int fib(int n) {
    counter[n]++;
    if (n <= 1) {
        return n;
    }
    else {
        return(fib(n-1) + fib(n-2));
    }
}

/* Tail recursive solution */
int fibtail(int n) {
    return fibtail_helper(n, 1, 1);
}

int fibtail_helper(int n, int f2, int f1) {
    counter[n]++;
    if (n <= 2) {
        return f1;
    }
    else {
        return(fibtail_helper(n-1, f1, f1+f2));
    }
}

int main(void) {
    
    for(int ii=1;ii<MAX;ii++) {
        counter[ii]=0;
    }
    
    for(int ii=1;ii<MAX;ii++) {
        printf("counter[%d] = %d\n", ii, counter[ii]);
    }
    printf("fib(25) = %d\n", fibtail(25));
  
    return 0;
}
