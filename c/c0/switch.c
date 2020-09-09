#include<stdio.h>


int main(void) {

    int num = 0;

    printf ("Enter a number: ");
    scanf("%d", &num);
    printf("\n");

    printf("First comparision:\n");
    /*
    if (num == 5) {
        printf("You entered a 5\n");
    }
    else if (num == 10) {
        printf("You entered a 10\n");
    }
    else if (num == 12) {
        printf("You entered a 12\n");
    }
    else if (num == 17) {
        printf("You entered a 17\n");
    }
    else {
        printf("You didn't enter 5, 10, 12, or 17!\n");
    }
    */
    switch (num) {
        case 5:
            printf("You entered a 5\n");
            break;
        case 10:
            printf("You entered a 10\n");
            break;
        case 12:
            printf("You entered a 12\n");
            break;
        case 17:
            printf("You entered a 17\n");
            break;
        default:
            printf("You didn't enter 5, 10, 12, or 17!\n");
    }

    printf("\nSecond comparision:\n");
    /*
    if (num < 20) {
        if (num < 10) {
            if (num < 5) {
                printf ("%d is less than 5\n", num);
            }
            printf ("%d is less than 10\n", num);
        }
        printf ("%d is less than 20\n", num);
    }
    */
    switch (num) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            printf ("%d is less than 5\n", num);
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            printf ("%d is less than 10\n", num);
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
            printf ("%d is less than 20\n", num);
    }
    return 0;
}