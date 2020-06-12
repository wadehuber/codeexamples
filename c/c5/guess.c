/* To compile:
   Override the default secret number with 15 
     gcc -DSECRETNUM=15 guess.c

   Print extra debugging output
     gcc -DDEBUG guess.c

   To do both of the above:
     gcc -DSECRETNUM=15 -DDEBUG guess.c
*/

#include<stdio.h>

#ifndef SECRETNUM
#define SECRETNUM 42
#endif

int main() {

    int num;
    printf ("Guess the number: ");
    scanf ("%d", &num);

#ifdef DEBUG
    printf("--- guess=%d, acutal=%d ---\n", num, SECRETNUM);
#endif

    if (num==SECRETNUM) {
        printf ("You guessed right!\n");
    }
    else {
        printf("Nope!  You are bad at this game!\n");
    }

    return 0;
}
