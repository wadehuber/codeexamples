#include<stdio.h>

/* symbolic constants */
#define LOWER 0
#define UPPER 100

int main(void) {
    int fahr;
    double celsius;
    int step = 20;

    fahr = LOWER;
    while( fahr <= UPPER ) {
        celsius = 5.0 * (fahr - 32.0) / 9.0;

        /* 
            %4d - print integer in a 4 character wide column
            \t  - tab character
            %6.1f - print a floating point number with 1 cecimal (6 char wide)
            \n - newline character
        */
        printf("%4d\t%6.1f\n", fahr, celsius);
        fahr += step;
    }
    return 0;
}
