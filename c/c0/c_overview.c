#include<stdio.h>
#include<string.h>

/* 
 * Data types
 * Arrays
 * User-defined types (structs)
 * Functions
 */

/* Forward declarations */
void print_num(int);
int add_numbers(int a, int b);

/* User-defined type */
struct simple_struct {
    int num;
    char name[10];
};

int main(void) {

    /* Variables */
    int x = 10;
    char c = 'K';
    struct simple_struct thing = {25, "Arizona"};

    /* Arrays */
    int nums[5];
    int vals[] = {3, 7, 5, 1, 10};
    char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char world[] = "world";


	printf("Hello, world\n");

    /* Printing values */
    printf("x=%d, c=%c\n", x, c);
    printf("x=%X, c=%d\n", x, c);
    printf("hello=%s, sizeof(hello)=%lu\n", hello, sizeof(hello));
    printf("world=%s, sizeof(world)=%lu\n", world, sizeof(world));

    /* Working with structs */
    printf("\n");
    printf("thing: num=%d, name=%s\n", thing.num, thing.name);
    thing.num = thing.num * 10;
    thing.name[4] = 'X';
    printf("thing: num=%d, name=%s\n", thing.num, thing.name);
    thing.num = 2021;
    /*thing.name="Texas"; NOT ALLOWED */
    strncpy(thing.name, "Texas", 6);
    printf("thing: num=%d, name=%s\n", thing.num, thing.name);

    /* Loops */
    printf("\n");
    for (int ii=0;ii<5;ii++) {
        nums[ii] = vals[ii] * ii;
    }

    int jj=0;
    printf("Array contents:\n");
    while (jj < 5) {
        printf("  vals[%d]=%d, nums[%d]=%d\n", jj, vals[jj], jj, nums[jj]);
        jj++;
    }

    /* Calling user-defined functions */
    printf("\nprint_num:\n");
    print_num(6);
    print_num(x);
    print_num(nums[3]);
    print_num(add_numbers(vals[2], 10));
    nums[0] = add_numbers(vals[2], x + 4);
    print_num(nums[0]);

    return 0;
}

/* Function defintions */
void print_num(int num) {
    printf("The number is %d\n", num);
}

int add_numbers(int a, int b) {
    return a + b;
}