/* Examples of allocating memory */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define COUNT 10

char * allocate_string(const char * str);

struct my_struct {
    int a;
    char * b;
};

int main(void) {
    int * intptr;
    int * nums;
    char * ptr;
    char sentence[] = "Chandler-Gilbert Community College";
    struct my_struct * thing;

    /* Allocating a single integer */
    intptr = malloc(sizeof(int));   /* Allocate 1 ints worth of memory */
    if(intptr == NULL) {
        fputs("Error allocating memory for pointer inptr.\n",stderr);
        exit(-1);
    }
    *intptr = 10;
    printf("intptr=%p, &intptr=%p, *intptr=%d\n", (void *) intptr, (void *) &intptr, *intptr);

    /* Allocating an integer array */
    nums = malloc(COUNT * sizeof(int));
    if(nums == NULL) {
        fputs("Error allocating memory for pointer nums.\n",stderr);
        exit(-1);
    }
    for(int ii=0;ii<COUNT;ii++) {
        *(nums+ii) = 11 * ii;
    }
    printf("Allocated nums.  Sizeof(nums)=%ld\n", sizeof(nums));
    printf("  Values: ");
    for(int ii=0;ii<COUNT;ii++) {
        printf("%d ", *(nums+ii));
    }
    printf("\n");

    /* Allocating a string */
    printf("\nAllocating strings:\n");
    ptr = malloc(COUNT * sizeof(char));   /* Allocate 10 bytes */
    if(intptr == NULL) {
        fputs("Error allocating memory for pointer ptr.\n",stderr);
        exit(-1);
    }
    strncpy(ptr, "Hello!", COUNT);
    printf("ptr=%p, len=%lu, string=%s\n", (void *) ptr, strlen(ptr), ptr);
    free(ptr);

    ptr = allocate_string("This is a test.");
    printf("ptr=%p, len=%lu, string=%s\n", (void *) ptr, strlen(ptr), ptr);
    free(ptr);
    ptr = allocate_string("A");
    printf("ptr=%p, len=%lu, string=%s\n", (void *) ptr, strlen(ptr), ptr);
    free(ptr);
    ptr = allocate_string(sentence);
    printf("ptr=%p, len=%lu, string=%s\n", (void *) ptr, strlen(ptr), ptr);
    free(ptr);

    /* malloc does not clean the memory */
    ptr = malloc(32);
    printf("%p : ", (void *) ptr);
    for (int ii=0;ii<32;ii++) {
        printf("%x ", (unsigned int) *(ptr+ii));
    }
    printf("\n");
    free(ptr);

    /* calloc *does* "clean" them memory */
    ptr = calloc(32, sizeof(char));
    printf("%p : ", (void *) ptr);
    for (int ii=0;ii<32;ii++) {
        printf("%x ", (unsigned int) *(ptr+ii));
    }
    printf("\n");

    /* Allocate a struct */
    printf("\nAllocating a struct\n");
    thing = malloc(sizeof(struct my_struct));
    thing->a = 30;
    thing->b = allocate_string("Name here");
    printf("%p: a=%d b=%s\n", (void *) thing, thing->a, thing->b);

    free(thing->b);
    free(thing);
    free(intptr);
    free(nums);

    return(0);
}

/* Allocate a new string with the same characters as parameter str
 *   We are assuming that str is a valid C string (null-terminated)
 *   The const modifier ensures that we don't modify str
 */
char * allocate_string(const char * str) {

    /* Get size of the string */
    int size = strlen(str) + 1;

    char * newstr = malloc(size * sizeof(char));   /* Allocate the string */
    if (newstr == NULL) {
        fputs("Error allocating memory for newstr.\n", stderr);
    }
    else {
        strncpy(newstr, str, size);
    }

    /* Note that while newstr is a local variable, the memory it points to is
     *   still available after we return from the function. */
    return newstr;
}
