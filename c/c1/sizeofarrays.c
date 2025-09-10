#include<stdio.h>

/* In C, arrays passed to functions decay to pointers, so sizeof(arr) 
   will not give the size of the array. Best practice is to pass the
   size of the array as a parameter to any function that will be 
   using an array, including strings. */
void myFunction(int arr[]) {
    printf("Inside myFunction, sizeof(arr)=%lu\n", sizeof(arr));
}

int main(void) {

    int int_arr[] = {1,2,3,4,5,6,7,8,9,10};
    char char_arr[] = {'A','B','C','D','E','F','G','H','I','J'};

    /* The arrays have the same number of elements, but different
         sizes - divide by the element size to get the count */
    printf("In main, sizeof(int_arr) =%lu\n", sizeof(int_arr));
    printf("In main, sizeof(char_arr)=%lu\n", sizeof(char_arr));

    printf("The number of elements in int_arr is %lu\n", 
           sizeof(int_arr)/sizeof(int_arr[0]));
    printf("The number of elements in char_arr is %lu\n", 
           sizeof(char_arr)/sizeof(char_arr[0]));

    myFunction(int_arr);

    return(0);
}   