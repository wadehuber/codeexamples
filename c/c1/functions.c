#include<stdio.h>

#define LENGTH 10


/* Forward declaration */
void say_hello();
int add_ten(int);
void add_twenty(int *);
int add_array(int[], int);

int main(void) {
    int a = 5;
    int b = 0;
    int arr[LENGTH] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    say_hello();
    printf("a=%d, b=%d\n", a, b);
    printf("add_ten(a)=%d, add_ten(b)=%d\n", add_ten(a), add_ten(b));
    printf("a=%d, b=%d\n", a, b);
    printf("add_twenty(&b)\n");
    add_twenty(&b);
    printf("a=%d, b=%d\n", a, b);
    printf("add_ten(a)=%d, add_ten(b)=%d\n", add_ten(a), add_ten(b));
    printf("a=%d, b=%d\n", a, b);

    printf("arr: ");
    for(int ii=0;ii<LENGTH;ii++) {
        printf("%d ", arr[ii]);
    }
    printf("\n");

    printf("add_array(arr,LENGTH)=%d\n", add_array(arr,LENGTH));
    return 0;
}

/* No return type */
void say_hello() {
    printf("Hello!\n");
}

/* Return an int, parameter is call-by-value - local copy, doesn't modify caller */
int add_ten(int x) {
    return x + 10;
}

/* Call-by-address - modifys the parameter in the caller */
void add_twenty(int *x) {
    *x = *x + 20;
}

int add_array(int a[], int len) {
    int sum = 0;
    for (int ii=0;ii<len;ii++) {
        sum += a[ii];
    }
    return sum;
}
