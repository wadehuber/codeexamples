/* Function to count the number of spaces in a string */
#include<stdio.h>

#define LEN 100

int count_spaces(char[], int);

int main(void) {
    char str[LEN];

    printf("Enter a string: ");
    fgets(str, LEN, stdin);  /* Get a string from input, store it in str */

    printf("Your string is: %s", str);
    printf("Your string has %d spaces\n", count_spaces(str, LEN));
        
    return(0);
}

/* Count the number of spaces in the string str */
int count_spaces(char str[], int len) {
    int index = 0;
    int count = 0;

    /* The size of the string is unknown, so we check for the index to
     *  less than len & that we haven't seen the null-terminator */
    while ( (index < len) && ( str[index] != '\0') ) {
        if (str[index] == ' ') {
            count ++;
        }
        index ++;
    }
    return count;
}
