#include <stdio.h>
struct Student {
    int id;
    double gpa;
};

int main(void) {
    struct Student s1 = {123, 3.65};

    /*
       ptr stores the address of s1.
       It does NOT hold the struct itself; it points to where it is located in memory.
    */
    struct Student *ptr = &s1;

    /* Use the dot operator when working with a regular struct variable.  */
    printf("ID: %d\n", s1.id);
    printf("GPA: %.2f\n", s1.gpa);

    /* Use the arrow operator when working with a pointer to a struct.  */
    printf("ID: %d\n", ptr->id);
    printf("GPA: %.2f\n", ptr->gpa);

    /*
       The arrow operator is shorthand.
       This:
           ptr->id
       Means the same thing as:
           (*ptr).id

       The parentheses are needed because . has higher precedence than *.
    */
    printf("Same ID again: %d\n", (*ptr).id);

    return 0;
}