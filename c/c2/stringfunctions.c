/* Examples of string functions 
 * Keep in mind: in C strings are null-terminated character arrays.  
 * So my_string[10] is a string of 9 characters + 1 null terminator
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LEN 10

void str_fun(char str[]);

int main(void) {
    char str1[LEN] = "Hello";
    char str2[LEN] = "World";
    char * ptr1 = (char *) malloc(LEN);
    char * ptr2 = (char *) malloc(LEN);
    char programming[] = "C programming is fun";
    char mystr[100];

    ptr1[0] = '\0';
    ptr2[0] = '\0';

    printf("Initial strings: \n");
    printf("  str1: [%p] sizeof=%lu  strlen=%lu  str1=%s\n", str1, sizeof(str1), strlen(str1), str1);
    printf("  str2: [%p] sizeof=%lu  strlen=%lu  str2=%s\n", str2, sizeof(str2), strlen(str2), str2);
    printf("  ptr1: [%p] sizeof=%lu  strlen=%lu  ptr1=%s\n", ptr1, sizeof(ptr1), strlen(ptr1), ptr1);
    printf("  ptr2: [%p] sizeof=%lu  strlen=%lu  ptr2=%s\n", ptr2, sizeof(ptr2), strlen(ptr2), ptr2);

    printf("Copying a string:\n");

    /* NOTE: strcpy should not be used because it does no bounds checking! */
    /* strcpy(str2, "Programming220"); */
    strncpy(ptr1, "CSC220", LEN-1);
    strncpy(ptr2, programming, LEN-1);
    printf("  str1: [%p] sizeof=%lu  strlen=%lu  str1=%s\n", str1, sizeof(str1), strlen(str1), str1);
    printf("  str2: [%p] sizeof=%lu  strlen=%lu  str2=%s\n", str2, sizeof(str2), strlen(str2), str2);
    printf("  ptr1: [%p] sizeof=%lu  strlen=%lu  ptr1=%s\n", ptr1, sizeof(ptr1), strlen(ptr1), ptr1);
    printf("  ptr2: [%p] sizeof=%lu  strlen=%lu  ptr2=%s\n", ptr2, sizeof(ptr2), strlen(ptr2), ptr2);

    printf("\nPassing a string to a function\n");
    printf("  str1: ");
    str_fun(str1);
    printf("  ptr1: ");
    str_fun(ptr1);
    
    printf("\nComparing strings:\n");
    if (strncmp(str1, "Hello", LEN) == 0) {
        printf ("  %s and \"Hello\" are the same through LEN (%d) characters)\n", str1, LEN);
    }
    else {
        printf ("  %s and \"Hello\" are different through LEN (%d) characters)\n", str1, LEN);
    }

    if (strncmp(str1, "Hello!", LEN) == 0) {
        printf ("  %s and \"Hello!\" are the same through LEN (%d) characters)\n", str1, LEN);
    }
    else {
        printf ("  %s and \"Hello!\" are different through LEN (%d) characters)\n", str1, LEN);
    }

    if (strncmp(str1, "Hello!", 5) == 0) {
        printf ("  %s and \"Hello!\" are the same through 5 characters)\n", str1);
    }
    else {
        printf ("  %s and \"Hello!\" are different through 5 characters)\n", str1);
    }

    if (strncmp(str1, str2, LEN) < 0) {
        printf("  %s is before %s\n", str1, str2);
    }
    else {
        printf("  %s is after %s\n", str1, str2);
    }

    if (strncmp(str2, str1, LEN) < 0) {
        printf("  %s is before %s\n", str2, str1);
    }
    else {
        printf("  %s is after %s\n", str2, str1);
    }

    printf("\nConcatenating strings:\n");
    strncat(str1, "!!!", 4);  /* Append 4 characters to str1 */
    strncat(str2, "CSC220", 3); /* Append 3 characters to str2 */
    printf("  str1: [%p] sizeof=%lu  strlen=%lu  str1=%s\n", str1, sizeof(str1), strlen(str1), str1);
    printf("  str2: [%p] sizeof=%lu  strlen=%lu  str2=%s\n", str2, sizeof(str2), strlen(str2), str2);

    printf("\nCreate a string with sprintf:\n");
    sprintf(mystr, "Hello, World!");
    printf("  mystr: %s\n", mystr);
    sprintf(mystr, "(%d,%d)", 12, -4);
    printf("  mystr: %s\n", mystr);
    sprintf(mystr, "%.2fx^%d", 2.4938, 3);
    printf("  mystr: %s\n", mystr);
    sprintf(mystr, "[%d, %c, %p, %s, %d]", 10, '@', (void*)ptr1, ptr1, -30);
    printf("  mystr: %s\n", mystr);

    return(0);
}

void str_fun(char str[]) {
    printf("  str: [%p] strlen=%lu  str=%s\n", str, strlen(str), str);

}
