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
void memdump(char *start, int len) {
    int ii=0;
    while(ii < len) {
        printf("%p: %4d %4X %3c\n", (start+ii), *(start+ii), *(start+ii), *(start+ii));
        ii++;
    }
}

int main(void) {

    /* ex.a = ASCII values of a,b,c,d, ex.b=ASCII value of #### */
    struct example ex1 = {0x61626364, 'A', 'B', 'C', 'D', 0x23232323};
    struct example * sptr = &ex1;

    printf("Contents of structure: \n");
    printf("      ex1.a=%d %x\n", ex1.a, ex1.a);
    printf("     ex1.c1=%x %c\n", ex1.c1, ex1.c1);
    printf("   sptr->c2=%x %c\n", sptr->c2, sptr->c2);
    printf("     ex1.c3=%x %c\n", ex1.c3, ex1.c3);
    printf("   sptr->c4=%x %c\n", sptr->c4, sptr->c4);
    printf("    sptr->b=%d %x\n", sptr->b, sptr->b);
    printf("\n");

    printf("memdump(&ex1):\n");
    memdump((char*) &ex1, sizeof(ex1)*2);

    return 0;
}