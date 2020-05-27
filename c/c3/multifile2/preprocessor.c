#include<stdio.h>
#include"myfunctions.h"

#define NUM 10

int main(void) {
    int x = NUM;
    int y = 0;
    int z = 0;
    char num[] = "NUM";

    printf("x=%d, y=%d, z=%d, num=%s\n", x, y, z, num);

    printf("\n");
    while (y < NUM * 2) {
        z = MAX(y, 10);
        printf("x=%d, y=%d, z=%d\n", x, y, z);
        y++;
    }

    printf("\n");
    x = addone(x);
    printf("x=%d, y=%d, z=%d\n", x, y, z);

    printf("\nCounter = %d\n", get_counter());
    return 0;
}
