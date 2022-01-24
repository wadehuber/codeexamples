#include <stdio.h>
#include <string.h>

int main(void) {
	/* 2D array - Array of 5 character arrays of length 15 */
	char s1[5][32] = {
		"Arizona",
		"Texas",
		"New Hampshire",
		"Utah",
		"California"
	};

	/* 1D array - Array of 5 character pointers - "ragged array" */
	/*   Note that initialization is exactly the same as above */
	char * s2[5] = {
		"Arizona",
		"Texas",
		"New Hampshire",
		"Utah",
		"California"
	};

	int s1size = sizeof(s1);
	int s2size = sizeof(s2);
	int ii;

	/* Print each array */
	printf("s1 - Array of character arrays:\n");
	for (ii = 0; ii < 5; ii++)  {
		printf("   %s\n", s1[ ii ]); 
	}

	printf("\n\ns2 - Array of pointers to strings:\n");
	for (ii = 0; ii < 5; ii++) {
		printf("   %s\n", s2[ ii ]); 
        /* Add size of string + null-teminator */
		s2size += (strlen(s2[ii]) + 1) * sizeof(char);
	}

	/* Print sizes */
	printf ("\nSizes: s1=%d, s2=%d (%lu)\n", s1size, s2size, sizeof(s2));
	
	return 0;
}
