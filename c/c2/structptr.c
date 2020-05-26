#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STRLEN 20       /* default string length */

struct mystruct_t {
    char name[STRLEN];
    int num;
};

/* Forward declarations */
void print_struct(const struct mystruct_t * s);
void update_structure(struct mystruct_t * s, char * name, int num);

int main (void) {
    struct mystruct_t struct1 = {"Alice", 10};  /* Initializing declaration */
    struct mystruct_t * ptr = NULL;

    /* malloc allocates memory from the heap */
    ptr = malloc(sizeof(struct mystruct_t));
    if(ptr == NULL) {
        fputs("Error allocating memory for pointer to mystruct_t.\n", stderr);
        exit(-1);
    }

    /* initialize the values in the mystruct_ struct that ptr points to */
    ptr->num = 10;
    strncpy(ptr->name, "Bob", STRLEN);

    /* print both structures */
    print_struct(&struct1);
    print_struct(ptr);

    /* modify the structures */
    update_structure(&struct1, "Sue", 30);
    update_structure(ptr, "Robert", 20);

    /* print both structures */
    print_struct(&struct1);
    print_struct(ptr);

    return(0);
}

/* print a mystruct_ structure */
void print_struct(const struct mystruct_t * s) {
    printf("name: %s, num%d\n", s->name, s->num);
}

/* update structure fields */
void update_structure(struct mystruct_t * s, char * name, int num) {
    strncpy(s->name, name, STRLEN);
    s->num = num;
}
