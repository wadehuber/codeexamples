#include<stdio.h>

int add(int x, int y) {

    return x + y;

}


int main() {

    int x = 11 + 6;
    int y = add(326, 599);

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}