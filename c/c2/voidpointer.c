#include<stdio.h>
#include<string.h>

struct my_struct_t {
  int a;
  int b;
};

int main(void) {
  int num = 10;
  char str[] = "My string";
  struct my_struct_t rec = {10, 42};

  void * void_ptr;

  printf("Initial values:\n");
  printf("num = %d\n", num);
  printf("str = %s\n", str);
  printf("rec = {%d %d}\n", rec.a, rec.b);
  
  /* We can use a void pointer to point to anything */
  void_ptr = (void*) &num;
  *((int*)void_ptr) = 999;


  void_ptr = (void*) str;
  strncpy((char*) void_ptr, "Hello!", 7);
  void_ptr = (void*) &rec;
  ((struct my_struct_t *) void_ptr)->a = -1;
  ((struct my_struct_t *) void_ptr)->b = 53;

  printf("\nFinal values:\n");
  printf("num = %d\n", num);
  printf("str = %s\n", str);
  printf("rec = {%d %d}\n", rec.a, rec.b);

  return 0;
}
