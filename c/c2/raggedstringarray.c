#include <stdio.h>
#include <string.h>

int main(void) {
	int ii;
	int s1size=0, s2size=0;

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


	/* Print each array */
	printf("s1 - Array of character arrays:\n");
	s1size = 0;
	for (ii = 0; ii < 5; ii++)  {
		printf("   %s\n", s1[ ii ]); 
	}
	s1size = sizeof(s1);

	printf("\n\ns2 - Array of pointers to strings:\n");
	s2size = sizeof(s2);
	for (ii = 0; ii < 5; ii++) {
		printf("   %s\n", s2[ ii ]); 
        /* Add size of string + null-teminator */
		s2size += (strlen(s2[ii]) + 1) * sizeof(char);
	}

	/* Print sizes */
	printf ("\nSizes: s1=%d, s2=%d\n", s1size, s2size);
	
	return 0;
}
