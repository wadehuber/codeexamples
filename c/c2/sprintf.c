#include <stdio.h>

#define BUFFER_SIZE 50

/*
   Note on sprintf vs snprintf:

   sprintf writes formatted text into a character array,
   but it does not know the size of the array.

   snprintf also writes formatted text into a character array,
   but it receives the size of the array. This helps prevent
   writing past the end of the buffer.

   snprintf is usually the safer choice.

   Also note:
   In C, this function does not really "return a string."
   Instead, main creates the character array, then passes it
   to the function. The function fills that array with text.
*/

void makeCourseString(char buff[], int size,
                      char subject[], int course_num,
                      char semester[], int year) {
    /*
       buff is the destination array.
       size is the amount of space available in buff.

       The remaining arguments work like printf.
    */

    snprintf(buff, size, "%s %d, (%s %d)",
             subject, course_num, semester, year);
}

int main(void) {
    char buff[BUFFER_SIZE];

    char subject[] = "CSC";
    int course_num = 240;

    char semester[] = "Spring";
    int year = 2026;

    makeCourseString(buff, BUFFER_SIZE,
                     subject, course_num,
                     semester, year);

    printf("The resulting string is: ");
    puts(buff);

    return 0;
}