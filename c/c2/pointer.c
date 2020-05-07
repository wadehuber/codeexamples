#include<stdio.h>
#include<stdlib.h>

int main(void) {

  /* int num = 6 
   *   name: num
   *   value: 6
   *   type: int
   *   stored at some location in memory
   *     that location has an address
   */
  int num = 6; /* Integer */
  int * ptr;   /* Pointer to an integer (or integer pointer) */
  char * cptr; /* character pointer */
  char str[] = "1234567890";   /* Character array (or string) */
  int * aptr;

  /* & : reference operator - returns the address */
  /* * : dereference operator - returns an alias */

  ptr = &num;   /* Set ptr to the address of num */
  printf("num = %d, %p, %lu\n", num, (void *) &num, sizeof(num));
  printf("ptr = %p, %p, %lu, *ptr=%d\n", (void*)ptr, (void*)&ptr, sizeof(ptr), *ptr);
  
  /* *ptr is an alias to num */
  *ptr = 20;
  printf("\nnum = %d, %p, %lu\n", num, (void *) &num, sizeof(num));
  printf("ptr = %p, %p, %lu, *ptr=%d\n", (void*)ptr, (void*)&ptr, sizeof(ptr), *ptr);

  printf("\nptr & num:\n");
  printf("ptr = %p\n", (void*) ptr);
  printf("*ptr = %d\n", *ptr);
  printf("&num = %p\n", (void*) &num);
  printf("*(&num) = %d\n", *(&num));
  printf("&(*ptr) = %p\n", (void*) &(*ptr));
  /* COMPILE ERROR printf("&(*num) = %p\n", &(*num)); */
  
  /* Don't try this at home! 
  ptr = 20;
  printf("ptr = %p\n", (void*) ptr);
  printf("*ptr = %d\n", *ptr);

  // This either 
  aptr = *ptr;  // *ptr is an int!
  printf("&(*aptr)) = %p\n", (void*) &(*aptr));
  printf("*aptr = %d\n", *aptr);
  */

  /* Allocate memory */
  printf("\nAllocating memory: \n");
  cptr = malloc(10 * sizeof(char));
  for (int ii=0;ii<9;ii++) {
    *(cptr+ii) = 'A' + ii;
  }
  *(cptr+9) = '\0';
  printf("str=%s\n", str);
  printf("cptr=%s\n", cptr);
   
  /* Allocate memory for an array */
  aptr = malloc(10 * sizeof(int));   /* Make sure you allocate enough bytes! */
  for(int ii=0;ii<9;ii++) {
    *(aptr+ii) = ii * 10;
  }

  printf("aptr = ");
  for(int ii=0;ii<9;ii++) {
    printf("[%d] ", *(aptr+ii));
  }
  printf("\n");
  
  free(cptr);

  return 0;
}
