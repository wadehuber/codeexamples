/* Example of scanning memory byte by byte */
#include <stdio.h>

struct example {
    int a;
    char c1;
    char c2;
    char c3;
    char c4;
    int b;
};

/* dump len bytes of memory starting at start */
void memdump (char * start, int len) {
    int ii = 0;
    char * ptr = start;

    while (ii<len) {
        printf ("%p: %4d %4x  (%c)\n", (ptr+ii), *(ptr+ii), *(ptr+ii), *(ptr+ii));
        ii++;
    }
}

int main(void) {

    /* ex.a = ASCII values of a,b,c,d, ex.b=ASCII value of #### */
    struct example ex1 = {0x61626364, 'A', 'B', 'C', 'D', 0x23232323};

    printf("Contents of structure: \n");
    printf("    ex1.a=%x\n", ex1.a);
    printf("   ex1.c1=%c\n", ex1.c1);
    printf("   ex1.c2=%c\n", ex1.c2);
    printf("   ex1.c3=%c\n", ex1.c3);
    printf("   ex1.c4=%c\n", ex1.c4);
    printf("    ex1.b=%x\n", ex1.b);
    printf("\n");

    printf("memdump(ex1): \n");
    memdump ((char*) &ex1, sizeof(ex1));

    return 0;
}