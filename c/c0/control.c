/* C Flow Control examples */
#include<stdio.h>

int main(void) {
    int a = 5;
    int b, ii;
     
    printf("Enter an integer : ");
    scanf("%d", &b);
    
    /* If-then-else statement */
    if (a < b) {
        printf("a=%d is less than b=%d\n", a, b);    
    }
    else {
        printf("a=%d is not less than b=%d\n", a, b);    
    }

    /* Case statement */
    switch (b)
    {
       case 1 :
             printf("You entered a one.\n");
            break;
        case 2 :
            printf("You entered a two.\n");
            break;
        case 3 :
            printf("You entered a three.\n");
            break;
        case 4 :
            printf("You entered a four.\n");
            break;
        case 5 :
            printf("You entered a five.\n");
            break;
        case 6 :
            printf("You entered a six.\n");
            break;
        default : /* The default case is used when no other cases match */
            printf("You entered a number\n");
    }

    /* While loop */
    printf("While loop:\n");
    ii = 0;
    while (ii <= b) {
        printf("  Your number = %d, loop variable = %d\n", b, ii);
        ii = ii+2;
    }

    /* Do-while loop - the body is always executed at least once */
    printf("Do-while loop:\n");
    do {
        printf("  Your number = %d, loop variale = %d\n", b, ii);
        ii = ii-2;
    } while (ii > 0);

    /* For loop (note in ANSI C the variable must be declared first */
    printf("For loop:\n");
    for (ii=0; ii<b; ii++) {
        printf("   for: loop variable = %d\n", ii);
    }

    /* The break statement exits the current loop */
    printf("Break:\n");
    for(;;) {
        /* Once a is bigger than 1000 exit the loop */
        if (a > 100) {
            printf("  Breaking at a=%d. . . \n", a);
            break;
        }
        else {
            a++;
        }
    }

    /* The continue statement skips to the next iteration */
    printf("Continue:\n");
    for(int jj=0;jj<=b;jj++) {
       if ( (jj % 3) != 0) {
             continue;
        }
        printf("  %d", jj);
    }
    printf("\n");

    return 0;
}

