#include<stdio.h>
#include<stdlib.h>

/* Example C file from video
 *  - pointers
 *  - struct pointers
 *  - void pointers
 */

/* Define a struct with a floating point number & a char array (string) */
typedef struct {
  float num;
  char name[10];
} ptr_example_t;

int main(void) {

  int nums[10];
  int* ptr = nums;  /* ptr points to the nums array */

  ptr_example_t mystruct = {12.345, "Arizona"};
  ptr_example_t * struct_ptr = &mystruct;  /* struct_ptr points to mystruct */

  void * void_ptr;  /* void (typeless) pointer */

  /* Initialize nums array using the pointer */
  for(int ii=0;ii<10;ii++) {
    *(ptr+ii) = ii+1;
  }

  /* Print nums array using the pointer */
  for(int ii=0;ii<10;ii++) {
    printf("nums[%d] = %d\n", ii, *(ptr+ii));
  }

  /* Print mystruct using the variable */
  printf("[variable] mystruct: num=%.2f, name=%s\n", mystruct.num, mystruct.name);

  /* Print mystruct using the pointer to mystruct */
  printf("\nUsing a pointer;\n");
  printf("[pointer] mystruct: num=%.2f, name=%s\n", struct_ptr->num, struct_ptr->name);

  /* void pointer */
  printf("\n\nUsing a void pointer;\n");
  void_ptr = nums;   /* void_ptr points to the integer array */
  *(((int*) void_ptr) + 4) = 100;  /* change a value in the array using the pointer */
  /* Print the array using the pointer */
  for(int ii=0;ii<10;ii++) {
    printf("nums[%d] = %d\n", ii, *(((int *)void_ptr)+ii));
  }

  void_ptr = &mystruct; /* Now void_ptr points to the struct mystruct */
  /* Print the structure using the void pointer */
  printf("[pointer] mystruct: num=%.2f, name=%s\n", ((ptr_example_t*) void_ptr)->num, 
		                                    ((ptr_example_t*) void_ptr)->name);

  /* Allocate 100 bytes of memory, put the address in void_ptr */
  void_ptr = malloc(100);

  /* Put some characters in the memory pointed to by void_ptr */
  for (int ii=0;ii<20;ii++) {
    *(((char*) void_ptr) + ii) = 'A' + ii; 
  }
  *(((char*) void_ptr) + 21) = '\0';  /* null-terminator to make it a string */

  /* Print the memory pointed to by void_ptr as a char & as an int */
  printf("\nAllocated memory (char) = %s\n", (char*) void_ptr); 
  printf("Allocated memory (int) = %x\n", *((unsigned int*) void_ptr)); 
  printf("Allocated memory (int) = %x\n", *(((unsigned int*) void_ptr) +1)); 

  free(void_ptr);  /* Free memory allocated by void_ptr */

  return 0;
}
