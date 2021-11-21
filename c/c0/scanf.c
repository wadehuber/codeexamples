#include<stdio.h>

int main(void) {
    int intVar;
    char charVar;
    float floatVar;
    char stringVar[100];

    printf("Enter a number: ");
    scanf("%d %c", &intVar, &charVar);
    fflush(stdin);
    printf("Enter a floating point number: ");
    scanf("%f", &floatVar);
    fflush(stdin);
    printf("Enter a string: ");
    scanf("%s", stringVar);
    fflush(stdin);

    printf("Number = %d\n", intVar);
    printf("Character = %c\n", charVar);
    printf("Floating Point = %.1f\n", floatVar);
    printf("String = %s\n", stringVar);


    return 0;
}