#include<stdio.h>

/* Forward declaration - what happens if we remove these? */
void say_hello();
int add_ten(int);
void add_twenty(int *);
int add_array(int[], int);

int main(void) {

  int a = 5;
  int b = 0;
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

  printf("a=%d, b=%d\n", a, b);
  printf("add_ten(a)=%d, add_ten(b)=%d\n", add_ten(a), add_ten(b));
  printf("a=%d, b=%d\n", a, b);
  printf("add_twenty(&b)\n");
  add_twenty(&b);
  printf("a=%d, b=%d\n", a, b);
  printf("add_ten(a)=%d, add_ten(b)=%d\n", add_ten(a), add_ten(b));
  printf("a=%d, b=%d\n", a, b);

  printf("\nadd_array(arr, 8) = %d\n", add_array(arr, 8));
  printf("\n");

  say_hello();

  return 0;
}

/* No return type */
void say_hello() {
  printf("Hello!\n");
}

/* Call-by-value - returns a value, but does not modify */
int add_ten(int x) {
  return x + 10;
}

/* Call-by-address - modifies the parameter x, does not return a value */
void add_twenty(int * x) {
  *x = *x + 20;
}

/* Since the array length is unknown we need to pass the length as a parameter */
int add_array(int a[], int len) {
  int sum = 0;
  for (int ii=0;ii<len;ii++) {
    sum += a[ii];
  }
  return sum;
}

