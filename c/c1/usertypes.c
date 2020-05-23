#include<stdio.h>
#include<string.h>

typedef unsigned int number;         /* user-defined type */
typedef enum {false, true} boolean;  /* enumeration type */
typedef enum {NUM1=3, NUM2=10, NUM3} nums;

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

/* typedef union */
typedef union {
    int n;
    boolean success;
    char s[16];
} my_union_t;

int main(void) {

    number x = 10;
    boolean is_it_true = false;
    nums val = NUM1;

    struct a_struct myStruct1 = {100, 50};
    my_struct_t myStruct2 = {10, true, "Hello!"};
    struct {int x; int y;} myStruct3 = {40, 41};

    my_union_t myUnion;

    printf("x = %d\n", x);

    printf("is_it_true %d\n", is_it_true);
    if(is_it_true == true) {
        printf("  It is true!\n");
    }
    if (!is_it_true) {
        printf("  It is false!\n");
    }

    is_it_true=true;
    printf("is_it_true %d\n", is_it_true);
    if(is_it_true == true) {
        printf("  It is true!\n");
    }
    if (!is_it_true) {
        printf("  It is false!\n");
    }

    printf("val = %d\n", val);
    printf("  valid values: %d %d %d\n", NUM1, NUM2, NUM3);
    printf ("\n");

    printf("Structs:\n");
    printf("myStruct1: %d %d\n", myStruct1.a, myStruct1.b);
    printf("myStruct2: %d %d %s\n", myStruct2.n, myStruct2.success, myStruct2.s);
    printf("myStruct3: %d %d\n", myStruct3.x, myStruct3.y);
    printf("\n");

    myStruct1.a = 2 * myStruct3.y;
    myStruct2.n = 30;
    strncpy(myStruct2.s, "Go!", 4);

    printf("Structs:\n");
    printf("myStruct1: %d %d\n", myStruct1.a, myStruct1.b);
    printf("myStruct2: %d %d %s\n", myStruct2.n, myStruct2.success, myStruct2.s);
    printf("myStruct3: %d %d\n", myStruct3.x, myStruct3.y);
    printf("\n");
 
    printf("Union:\n");
    myUnion.n = 0x44434241;
    printf("myUnion: %d %d %s\n", myUnion.n, myUnion.success, myUnion.s);
    myUnion.success = false;
    printf("myUnion: %d %d %s\n", myUnion.n, myUnion.success, myUnion.s);
    strncpy(myUnion.s, "x44434241", 10);
    printf("myUnion: %x %d %s\n", myUnion.n, myUnion.success, myUnion.s);
    printf("\n");

    printf("Sizes:\n");
    printf("x (num): %ld\n", sizeof(x));
    printf("is_it_true (boolean) %ld\n", sizeof(is_it_true));
    printf("myStruct1 (struct a_struct): %ld\n", sizeof(myStruct1)); 
    printf("myStruct2 (my_struct_t): %ld\n", sizeof(myStruct2));
    printf("myStruct3 (struct int x; int y;): %ld\n", sizeof(myStruct3));
    printf("myUnion (my_union_t): %ld\n", sizeof(myUnion));
    printf("\n");
   
     

    return(0);
}
