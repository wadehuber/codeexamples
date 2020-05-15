/* Examples of functions from ctypes.h 
   This header file has some helpful functions for working with types */

#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(void) {
    int ii;
    char * str = "Hello, TK-421!";

    for (ii=0;ii<strlen(str);ii++) {
        printf("str[%2d]='%c'  (ASCII 0x%x)  ", ii, str[ii], str[ii]);

        /* Check what type of character str[ii] is */
        if (isalnum(str[ii])) {
            printf ("ALNUM ");
        } 
        if (isalpha(str[ii])) {
            printf ("ALPHA ");
        } 
        if (isdigit(str[ii])) {
            printf ("DIGIT ");
        } 
        if (islower(str[ii])) {
            printf ("LOWER ");
        } 
        if (isupper(str[ii])) {
            printf ("UPPER ");
        } 
        if (isspace(str[ii])) {
            printf ("SPACE ");
        } 
        if (ispunct(str[ii])) {
            printf ("PUNCT ");
        } 
        printf("\n");
    }

    printf("\nAll upper case: ");
    for (ii=0;ii<strlen(str);ii++) {
        printf("%c", toupper(str[ii]));
    }
    printf("\nAll lower case: ");
    for (ii=0;ii<strlen(str);ii++) {
        printf("%c", tolower(str[ii]));
    }

    return 0;
}
