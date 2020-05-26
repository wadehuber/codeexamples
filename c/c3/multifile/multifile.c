#include<stdio.h>
#include"mystuff.h"

int main(void) {
    printf("Max1: %d\n", MAX(20, 13));
    printf("Max2: %d\n", MAX(NUM, 13));
    printf("Max3: %d\n", max_of_three(20, 13, NUM));
    return 0;
}
