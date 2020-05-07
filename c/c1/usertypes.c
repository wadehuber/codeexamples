#include<stdio.h>
#include<string.h>

typedef unsigned int num;           /* user-defined type */
typedef enum {false, true} boolean; /* enumeration type */

/* struct */
struct a_struct {
  int a;
  int b;
};

/* typedef struct */
typedef struct {
  int n;
  boolean success;
  char s[16];
} my_struct_t;

typedef union {
  int n;
  boolean success;
  char s[16];
} my_union_t;

int main(void) {
  num x = 10;
  boolean is_it_true = false;
  my_struct_t myStruct = {10, true, "Hello!"};
  struct a_struct myStruct2 = {100, 50};
  struct {int x; int y;} myStruct3 = {40, 41};
  my_union_t myUnion;

  printf("x=%d \n", x);
  printf("is_it_true=%d\n", is_it_true);
  is_it_true = true;
  printf("is_it_true=%d\n", is_it_true);
  if (is_it_true == true) {
    printf("It's true!\n");
  }
  else {
    printf("It's false\n");
  }

  printf("\nStructs:\n");
  printf("myStruct: %d, %d, %s\n", myStruct.n, myStruct.success, myStruct.s);
  printf("myStruct2: %d, %d\n", myStruct2.a, myStruct2.b);
  printf("myStruct3: %d, %d\n", myStruct3.x, myStruct3.y);


  printf("\nUnion:\n");
  myUnion.n = 0x44434241;
  printf("myUnion: n = %x, s=%s\n", myUnion.n, myUnion.s);
  myUnion.success = false;
  printf("myUnion: n = %x, s=%s\n", myUnion.n, myUnion.s);
  strncpy(myUnion.s, "x44434241", 10);
  printf("myUnion: n = %x, s=%s\n", myUnion.n, myUnion.s);

  printf("Sizes:\n");
  printf("x (num): %ld\n", sizeof(x));
  printf("is_it_true (boolean): %ld\n", sizeof(is_it_true));
  printf("myStruct (my_struct_t): %ld\n", sizeof(myStruct));
  printf("myStruct2 (struct a_struct): %ld\n", sizeof(struct a_struct));
  printf("myStruct3 (struct int x; int y;): %ld\n", sizeof(myStruct3));
  printf("myUnion (my_union_t): %ld\n", sizeof(myUnion));

  return 0;
}
