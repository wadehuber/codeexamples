#include <stdio.h>

int main(void) {
    char str1[] = "Hello";  /* string (null-terminated character array) */
    char str2[] = {'W', 'o', 'r', 'l', 'd'};  /* character array - not a string! */
    char str3[] = {'E', 'n', 'd', '.', '\0'}; /* string (null-terminated character array) */
    char str4[] = "This is a really long string.  Maybe too long?"; 

    int ii; 

    printf("str1: size=%lu %s\n", sizeof(str1), str1);
    printf("str2: size=%lu %s\n", sizeof(str2), str2);
    printf("str3: size=%lu %s\n", sizeof(str3), str3);
    printf("str4: size=%lu %s\n", sizeof(str4), str4);
    printf("\n");

    /* Null */
    printf("Null: [%c] decimal=%d hex=%X\n", '\0', '\0', '\0');
    printf("\n");

    ii = 0;
    printf("str1 char-by-char: ");
    while (str1[ii] != '\0') {
        printf("%c ", str1[ii]);
        ii++;
    }
    printf("\n");

    ii = 0;
    printf("str3 values char-by-char:\n");
    while (str3[ii] != '\0') {
        printf("  str3[%d]: %c (ASCII:%4d %4o %4X)\n", ii, 
                       str3[ii], str3[ii], str3[ii], str3[ii]);
        ii++;
    }
    printf("\n");

    printf("str4: %s\n", str4);
    str4[29] = '\0';
    printf("str4: %s\n", str4);
    for(ii=0;ii<sizeof(str4)/sizeof(char);ii++) {
        printf("[%c]", str4[ii]);
    }
    printf("\n");

    return 0;
}
