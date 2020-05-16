#include<stdio.h>

#define COUNT 16

int main(void) {
  int arr[COUNT];
  int * ptr;
  int ii;

  ptr = arr;  /* equivalent to: ptr = &arr[0] */

  for(ii=0;ii<COUNT;ii++) {
      arr[ii] = ii;
  }

  printf("Array indexing: \n");
  for(ii=0;ii<COUNT;ii++) {
    printf("%d ", arr[ii]);
  }
  printf("\n\n");

  printf("Pointer arithmetic: \n");
  for(ii=0;ii<COUNT;ii++) {
    printf("%d ", *(ptr+ii));
  }
  printf("\n\n");

  printf("Array indexing using a pointer: \n");
  for(ii=0;ii<COUNT;ii++) {
    printf("%d ", ptr[ii]);
  }
  printf("\n\n");

  printf("Pointer arithmetic using an array name: \n");
  for(ii=0;ii<COUNT;ii++) {
    printf("%d ", *(arr+ii));
  }
  printf("\n\n");

  printf("\nAre arrays and pointers the same?\n");
  printf("  size of arr=%lu\n", sizeof(arr));
  printf("  size of ptr=%lu\n", sizeof(ptr));

  /* You can assign a value to a pointer, but not an array name */
  /* VALID: ptr = &ii; */
  /* COMPILE ERROR arr = &ii; */
    
  printf("\n\nPointer arithmetic (using increment operator): \n");
  for(ii=0;ii<COUNT;ii++) {
    printf("%d ", *ptr);
    ptr++;
  } 
  printf("\n");


  return 0;
}
