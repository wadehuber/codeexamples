#include <stdio.h>

int main(void) {
    char str1[] = "Hello";   /* string (null-terminated character array) */
    char str2[] = {'W', 'o', 'r', 'l', 'd'}; /* character array (not a string!) */
    char str3[] = {'e', 'n', 'd', '\0'}; /* null-terminated char array (a string!) */
    char str4[] = "This is a really long string.  Maybe too long?";
    int ii;

    printf("str1: %s \t%lu\n", str1, sizeof(str1));
    printf("str2: %s \t%lu\n", str2, sizeof(str2));
    printf("str3: %s \t%lu\n", str3, sizeof(str3));
    printf("str4: %s \t%lu\n", str4, sizeof(str4));
    printf("\n");

    ii = 0;
    printf("str1 char-by-char: ");
    while (str1[ii] != '\0') {
        printf("%c", str1[ii]);
        ii++;
    }
    printf("\n\n");

    ii = 0;
    printf("str3 values char-by-char: \n");
    while (str3[ii] != '\0') {
        printf("str3[%d]: %c (ASCII=%d\n", ii, str3[ii], str3[ii]);
        ii++;
    }
    printf("\n\n");

    printf("str4: %s\n", str4);
    str4[29] = '\0';
    printf("str4: %s\n", str4);
    printf("str4 char-by-char: ");
    for(ii=0;ii<sizeof(str4)/sizeof(char);ii++) {
        printf("%c", str4[ii]);
    }
    printf("\n\n");

    str1[0] = 'M';
    printf("str1: %s\n", str1);
    str1[4] = '#';
    printf("str1: %s\n", str1);
    str1[5] = '#';
    printf("str1: %s\n", str1);

    return 0;
}
