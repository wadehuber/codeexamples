#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int value;
    int * numbers;
    char * str;
} example_t;

int main(void) {

    int x = 14;
    int arr[5] = {1, 2, 3, 4, 5};
    char * name = "structures with pointers";
    
    example_t struct_var;
    example_t * struct_ptr = malloc(sizeof(example_t));

    struct_var.value = x;
    struct_var.numbers = arr;
    struct_var.str = name;


    /* I can either use pointers to existing variables, 
       or allocate new memory */
    struct_ptr->value = 10;
    struct_ptr->numbers = malloc(4 * sizeof(int));
    struct_ptr->str = malloc(25 * sizeof(char));

    /* Initialize values in memory allocated for struct_ptr fields */
    for (int ii=0;ii<4;ii++) {
        *(struct_ptr->numbers+ii) = ii * 11;
    }
    strncpy(struct_ptr->str, "Pointer fun", 25);

    printf("struct_var: value=%d str=%s (%p)\n", struct_var.value, struct_var.str, struct_var.str);
    printf("   numbers (%p): ", (void *)struct_var.numbers);
    for(int ii=0;ii<5;ii++) {
        printf("%d ", struct_var.numbers[ii]);
    }
    printf("\n");

    printf("struct_ptr: value=%d str=%s (%p)\n", struct_ptr->value, struct_ptr->str, struct_ptr->str);
    printf("   numbers (%p): ", (void *)struct_ptr->numbers);
    for(int ii=0;ii<4;ii++) {
        printf("%d ", struct_ptr->numbers[ii]);
    }
    printf("\n");

    free(struct_ptr->numbers);
    free(struct_ptr->str);

    return 0;
}