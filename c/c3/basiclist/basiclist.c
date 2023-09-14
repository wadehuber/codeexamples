/* Very basic linked list example 

   To run as a test: 
    gcc --std=c11 -pedantic -Wall basiclist.c -DTEST
*/

#include <stdio.h>
#include <stdlib.h>
#include "basiclist.h"

#define COUNT 10

int list_add(node_t ** list, const void * data) {
    int ret = 0;

    node_t * newnode = malloc(sizeof(node_t));
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

const void * list_remove_first(node_t ** list) {
    node_t * old_front = *list;
    const void * data = old_front->data;

    *list = old_front->next;
    free(old_front);
    return(data);
}

#ifdef TEST
int main(void) {
    node_t * list = NULL;
    node_t * curr;
    int num;
    int * element;
    int ii;

    for(ii=1;ii<=COUNT;ii++) {
        int * new_int = malloc(sizeof(int));
        *new_int = rand() % ((ii+1) * COUNT);
        list_add(&list, new_int);
    }

    printf("Initial list:\n");
    curr = list;
    ii = 0;
    while (curr!=NULL) {
        printf("  (%d) = %2d at %p\n", ii, *((int *) curr->data), curr->data);
        ii++;
        curr = curr->next;
    }
    
    printf("\n");
    element = (int *) list_remove_first(&list);
    num = *element;
    free(element);
    printf("Remove 1: %d\n", num);
    element = (int *) list_remove_first(&list);
    num = *element;
    free(element);
    printf("Remove 2: %d\n", num);

    printf("\n");
    printf("List after removing 2 nodes:\n");
    curr = list;
    ii = 0;
    while (curr!=NULL) {
        printf("  (%d) = %2d at %p\n", ii, *((int *) curr->data), curr->data);
        ii++;
        curr = curr->next;
    }

    /* remove rest of list */
    curr = list;
    printf("\nCleaning up list ...\n");
    while (curr!=NULL) {
        curr = curr->next;
        element = (int *) list_remove_first(&list);
        free(element);
    }
    
    return 0;
} 
#endif

