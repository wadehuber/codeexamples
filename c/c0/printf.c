#include<stdio.h>

int main(void) {
	int num = 24;
	float num2 = 12.345678;

	printf("num = %d\n", num);
	printf("%d + %d = %d\n", 7, 3, 7+3);

	/* Different control sequence give different output */
	printf("num: %d %o %x\n", num, num, num);

	/* Floating point number */
	printf("num2: %f\n", num2);
	printf("num2: %.2f\n", num2);  /* Print 2 decimal places */

	/* Formatting */
	printf("num:%10d\n", num);
	printf("num2:%20.3f\n", num2);

	/* Tabs & newlines */
	printf("Tab\ttab\ttab\ttab\nnewline\n\tnewline\n");
	
	return 0;
}
