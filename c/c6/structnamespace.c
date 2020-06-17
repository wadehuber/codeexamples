#include<stdio.h>

/* Create type struct my_struct */
struct my_struct {
    int num;
    char name[10];
};

/* Create type my_struct */
typedef struct {
    int count;
    float average;
} my_struct;

int main () {
    struct my_struct struct1 = {3, "my_struct"};
    my_struct struct2 = {2, 1.234};

    printf("struct mystruct: num=%d, name=%s\n", struct1.num, struct1.name);
    printf(" mystruct: count=%d, average=%s\n", struct2.count, struct2.average);

    return 0;
}
