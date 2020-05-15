/* Examples of math functions 
 *
 * To compile:
 *    gcc --std=c11 -pedantic -Wall math.c -lm
 */
#include<stdio.h>
#include<math.h>

/* PI & E are not defined in the C standard.  
 * POSIX implementations include PI & E in math.h 
 */

#define E 2.718282
#define PI 3.141593

int main(void) {

    double a = 64.0;
    double b, c;

    b = -1.0 * sqrt(a);
    c = sqrt(14.2);

    printf("Initial values: \n");
    printf("  a=%.2f, b=%.2f, c=%.2f\n", a, b, c);
    printf("  e=%f, pi=%f\n", E, PI);


    printf("\nPower function:\n");
    printf("  pow(3,2)=%.2f, pow(3,-2)=%.2f, pow(3,2.5)=%.2f\n", 
            pow(3,2), pow(3,-2), pow(3,2.5));
    
    printf("\nLogarithms:\n");
    printf("  log(E)=%.2f, log(10.0)=%.2f, log(100.0)=%.2f\n", 
            log(E), log(10.0), log(100.0));
    printf("  log10(E)=%.2f, log10(10.0)=%.2f, log10(100.0)=%.2f\n", 
            log10(E), log10(10.0), log10(100.0));

    printf("\nFloor & celiling function results: \n");
    printf("  floor(a)=%.2f, floor(b)=%.2f, floor(c)=%.2f\n", floor(a), floor(b), floor(c));
    printf("   ceil(a)=%.2f,  ceil(b)=%.2f,  ceil(c)=%.2f\n", ceil(a), ceil(b), ceil(c));
    printf("   fabs(a)=%.2f,  fabs(b)=%.2f,  fabs(c)=%.2f\n", fabs(a), fabs(b), fabs(c));

    printf("\nTrig\n");
    a = PI / 4.0;
    b = PI / 2.0;
    c = PI;
    printf("   a=PI/4=%.2f, b=PI/2=%.2f, c=PI=%.2f\n", a, b, c);
    printf("   cos(a)=%.2f, cos(b)=%.2f, cos(c)=%.2f\n", cos(a), cos(b), cos(c));
    printf("   sin(a)=%.2f, sin(b)=%.2f, sin(c)=%.2f\n", sin(a), sin(b), sin(c));
    printf("   tan(a)=%.2f, tan(b)=%.2f, tan(c)=%.2f\n", tan(a), tan(b), tan(c));

    return 0;

}
