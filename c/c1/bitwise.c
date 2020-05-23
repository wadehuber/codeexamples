#include<stdio.h>

int main() {
    unsigned int num = 8;

    printf("\nInitial:\n");
    printf("  num = %x\n", num);

    printf("\nLeft shift by 2:\n");
    num = num << 2;
    printf("  num = %x\n", num);

    printf("\nRight shift by 4:\n");
    num = num >> 4;
    printf("  num = %x\n", num);

    printf("\nLeft shift by 2:\n");
    num = num << 2;
    printf("  num = %x\n", num);

    printf("\nBitwise operators:\n");
    printf("num & 1 = %x\n", num & 1);   /* Logical AND */
    printf("num | 1 = %x\n", num | 1);   /* Logical OR */
    printf("num ^ 1 = %x\n", num ^ 1);   /* Logical XOR */

    printf("\n");
    printf("num & 9 = %x\n", num & 9);   /* Logical AND */
    printf("num | 9 = %x\n", num | 9);   /* Logical OR */
    printf("num ^ 9 = %x\n", num ^ 9);   /* Logical XOR */

    return(0);
}
