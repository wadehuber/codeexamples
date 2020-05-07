#include<stdio.h>
#include<string.h>

/* 
 * Data types
 * Arrays
 * User-defined types (structs)
 * Functions
 */

/* Forward declarations */
void print_num(int num);
int add_numbers(int a, int b);

struct simple_struct {
	int num;
	char name[10];
};

int main(void) {
	int x = 10;
	char c = 'K';
	int nums[5];
	int vals[] = {1,2,3,4};
	struct simple_struct thing = {25, "Arizona"};

	char hello[] = {'H', 'e', 'l', 'l', 'o', '\0'};  /* Null terminated */
	char world[] = "world";

	printf("Hello, world\n");

	printf("x=%d, c=%c\n", x, c);
	printf("x=%x, c=%d\n", x, c);
	printf("hello=%s, sizeof hello = %lu\n", hello, sizeof(hello));
	printf("world=%s, sizeof world = %lu\n", world, sizeof(world));

	printf("thing: num=%d, name=%s\n", thing.num, thing.name);
	thing.num = thing.num * 10;
	thing.name[4] = 'X';
	printf("thing: num=%d, name=%s\n", thing.num, thing.name);
	thing.num = 2020;
	/* thing.name = "Texas";  // You can't do this! */
        strncpy(thing.name, "Texas", 6);
	printf("thing: num=%d, name=%s\n", thing.num, thing.name);

	print_num(add_numbers(thing.num, 6));
	nums[0] = add_numbers(vals[2], 10);
	print_num(nums[0]);
	
}

void print_num(int num) {
	printf("The number is %d\n", num);
}

int add_numbers(int a, int b) {
	return a + b;
}

