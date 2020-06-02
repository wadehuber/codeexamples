#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void) {

    char str[] = "Hello, TK-421. 0xA@\tBye!";

    for(int ii=0;ii<strlen(str);ii++) {
        printf("str[%2d]=%c (ASCII %3d) ", ii, str[ii], str[ii]);

        /* Check what the type of the character at str[ii] is */
        if(isalnum(str[ii])) {
            printf("ALNUM ");
        }
        if(isalpha(str[ii])) {
            printf("ALPHA ");
        }
        if(isdigit(str[ii])) {
            printf("DIGIT ");
        }
        if(isxdigit(str[ii])) {
            printf("XDIGIT ");
        }
        if(islower(str[ii])) {
            printf("LOWER ");
        }
        if(isupper(str[ii])) {
            printf("UPPER ");
        }
        if(isspace(str[ii])) {
            printf("SPACE ");
        }
        if(ispunct(str[ii])) {
            printf("PUNCT ");
        }
        printf("\n");
    }

    printf("\n");
    printf("All upper case: ");
    for (int ii=0;ii<strlen(str);ii++) {
        printf("%c", toupper(str[ii]));
    }
    printf("\n");
    printf("All lower case: ");
    for (int ii=0;ii<strlen(str);ii++) {
        printf("%c", tolower(str[ii]));
    }
    printf("\n");

    return 0;
}
