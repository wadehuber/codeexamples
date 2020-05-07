/* Very basic linked list example */
#include <stdio.h>
#include <stdlib.h>
#include"basiclist.h"

/* To run as a test: 
    gcc -ansi -pedantic -Wall basiclist.c -DTEST
*/

int list_add(node_t ** list, void * data) {
  int ret = 0;
  node_t * newnode = (node_t *) malloc(sizeof(node_t));
  if (newnode == NULL) {
    ret = -1;
  }
  else {
    newnode->data = data;
    newnode->next = *list;
    *list = newnode;
  }
  return ret;
}

void * list_remove_first(node_t ** list) {
  node_t * old_front = *list;
  void * data = old_front->data;

  *list = old_front->next;
  free(old_front);
  return data;
}

#ifdef TEST
int main(void) {
  int ii;
  int * new_int;
  node_t * list = NULL;
  node_t * curr;
  int num;

  for(ii=1;ii<=10;ii++) {
    new_int = (int *) malloc(sizeof(int));
    *new_int = rand() % ((ii+1) * 10);
    list_add(&list, new_int);
  }

  printf("Initial list:\n");
  ii = 0;
  curr = list;
  while (curr != NULL) {
    printf("list[%d] = %d\n", ii, *((int *) curr->data));
    ii++;
    curr = curr->next;
  }

  printf("\n");
  num = *((int *) list_remove_first(&list));
  printf("Remove 1 = %d\n", num);
  num = *((int *) list_remove_first(&list));
  printf("Remove 2 = %d\n", num);
  printf("\n");

  printf("List after removing 2 elements:\n");
  ii = 0;
  curr = list;
  while (curr != NULL) {
    printf("list[%d] = %d\n", ii, *((int *) curr->data));
    ii++;
    curr = curr->next;
  }
  printf("It worked!\n");
  return 0;
}
#endif

