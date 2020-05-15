#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STRLEN 20       /* default string length */

/* User defined type */

struct mystruct_t {
  char name[STRLEN];
  int num;
};

/* forward declarations */
void print_structure(struct mystruct_t s);
void print_struct(const struct mystruct_t * s);
void init_structure(struct mystruct_t *, char *, int); /* no param names required */

int main (void) {
  struct mystruct_t struct1 = {"Alice", 10};  /* Initializing declaration */
  struct mystruct_t * ptr = NULL;

  /* malloc allocates memory from the heap */
  ptr = malloc(sizeof(struct mystruct_t));
  strncpy(ptr->name, "Bob", STRLEN);
  ptr->num=10;

  /* print both structures */
  print_structure(struct1);
  print_structure(*ptr);

  /* modify both structures */
  init_structure(&struct1, "Sue", 30);
  init_structure(ptr, "Robert", 20);

  /* print both structures */
  printf("\nPrinting both structures after init_structure using print_struct\n");
  print_struct(&struct1);
  print_struct(ptr);

  printf("\nPrinting both structures after print_struct using print_structure\n");
  print_structure(struct1);
  print_structure(*ptr);
  return 0;
}
/* struct is pass-by-address */
void init_structure(struct mystruct_t *s, char * name, int num) {
  strncpy(s->name, name, STRLEN);
  s->num=num;
}

/* struct parameter is pass-by-value */
void print_structure(struct mystruct_t s) {
  printf("name: %s, num=%d\n", s.name, s.num);
}

/* Better print_structure */
void print_struct(const struct mystruct_t * s) {
  printf("name: %s, num=%d\n", s->name, s->num);
  /* s->num=55; NOT ALLOWED */
}
