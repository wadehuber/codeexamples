#include<stdio.h>
#include<string.h>

typedef enum {false, true} boolean;

typedef struct {
  int n;
  boolean success;
  char s[16];
} my_struct_t;

int main(void) {
  my_struct_t myStruct = {10, true, "Hello!"}; 
  my_struct_t * ptr;

  printf("\nStruct contents:\n");
  ptr = &myStruct;
  printf("myStruct: %d, %d, %s\n", myStruct.n, myStruct.success, myStruct.s);
  printf("ptr: %d, %d, %s\n", ptr->n, ptr->success, ptr->s);
 
  printf("\nChange struct through variable:\n"); 
  myStruct.n = 30;
  myStruct.success = false;
  strncpy(myStruct.s, "World!",10);
  printf("  myStruct: %d, %d, %s\n", myStruct.n, myStruct.success, myStruct.s);
  printf("Change struct through ptr:\n"); 
  ptr->n = 50;
  ptr->success = true;
  strncpy(ptr->s, "Goodbye!",10);
  printf("  ptr: %d, %d, %s\n", ptr->n, ptr->success, ptr->s);

  printf("\nSizes:\n");
  printf("myStruct (my_struct_t): %ld\n", sizeof(myStruct));
  printf("ptr (my_struct_t *): %ld\n", sizeof(ptr));
  return 0;
}
