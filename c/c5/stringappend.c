#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Allocate a new new string that is the result of appending str1 & str2 */
char * append(char * str1, char * str2) {
    char * ret = NULL;

    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    size_t newsize = len1 + len2 + 1;

#ifdef DEBUG
    printf("Appending: \n");
    printf(" str1 (%lu): %s\n", len1, str1);
    printf(" str2 (%lu): %s\n", len2, str2);
    printf(" new string size = %lu\n", newsize);
#endif

    ret = malloc(newsize * sizeof(char));
    if (ret == NULL) {
        fprintf(stderr, "Unable to allocate new string\n");
    }
    else {
        strncpy(ret, str1, len1);
        strncpy(ret+len1, str2, len2);
        ret[newsize-1] = '\0';
    }

    return ret;
}

int main() {
    char * result;

    result = append("Hello", "World!");
    printf("Result=[%s]  len=%lu\n", result, strlen(result));

    return 0;
}

