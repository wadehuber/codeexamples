#include<stdio.h>
#include"multifile/mystuff.h"

int main() {
    int numbers[] = {0,0,0};
    int count;
    int biggest=0;
    int ii;

    /* Prompt user for how many numbers they want to enter */
    printf("How many numbers do you want to enter? ");
    scanf("%d", &count);
    if (count < 1) {
        count = 1;
    }
    if (count > 3) {
        count = 3;
    }

    for (ii=0;ii<count;ii++) {
        printf("Enter number %d: ", ii+1);
        scanf("%d", &numbers[ii]);
    }

    switch(count) {
        case 1:
            biggest = numbers[0];
            break;
        case 2:
            biggest = MAX(numbers[0], numbers[1]);
            break;
        case 3:
            biggest = max_of_three(numbers[0], numbers[1], numbers[2]);
            break;
    }
    printf("The largest number entered was %d\n", biggest);

    return 0;
}