#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Allocate a new string that is the result of appending str1 & str2 */
char * append(char * str1, char * str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t resize = len1 + len2 + 1;
    char * result;

#ifdef DEBUG
    printf("Appending: \n");
    printf("  str1 [%lu]: %s\n", len1, str1);
    printf("  str2 [%lu]: %s\n", len2, str2);
#endif

    result = malloc(resize * sizeof(char));
    strncpy(result, str1, len1);
    strncpy(result+len1, str2, len2);
    return result;
}

int main() {
    char * result;

    result = append("Hello", "World");
    printf("Result: [%s]\n", result);

    return 0;
}

