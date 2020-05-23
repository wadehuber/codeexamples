#include<stdio.h>

int main(void) {

    char * p = "Hello";
    char * s = "this is a string";
    char t[] = "Also a string";

    printf("\n==== print string ==== \n");
    printf("p: address=%16p, p=%p, %s\n", (void *) &p, (void *) p, p);
    printf("s: address=%16p, s=%p, %s\n", (void *) &s, (void *) s, s);
    printf("t: address=%16p, %s\n", (void *) &t, t);
    printf("\n");


    /* This code displays the address where the characters in t are stored */
    /*
    printf("\n==== where is t stored? ====\n");
    char * cptr = t;
    int index=0;
    while (*(cptr+index) != '\0') {
        printf(" t[%d]=%c address:%p\n", index, *(cptr+index), (void*) (cptr+index));
        index ++;
    }
    */

    printf("==== print character ==== \n");
    printf("p: address=%16p, p=%p, %c [%d]\n", (void *) &p, (void *) p, *p, *p);
    printf("s: address=%16p, s=%p, %c [%d]\n", (void *) &s, (void *) s, *s, *s);
    printf("t: address=%16p, %c [%d / %d]\n", (void *) &t, *t, *t ,t[0]); 
    printf("\n");

    printf("==== print character + 1 ==== \n");
    printf("p: %c [%d]\n", *(p+1), *(p+1));
    printf("s: %c [%d]\n", *(s+1), *(s+1));
    printf("t: %c [%d / %d]\n", *(t+1), *(t+1) ,t[1]); 
    printf("\n");

    printf("\n==== print string + 1 ==== \n");
    printf("p: %s\n", (p+1));
    printf("s: %s\n", (s+1));
    printf("t: %s\n", (t+1));
    printf("\n");

    printf("==== print character + 8 ==== \n");
    printf("p: %c [%d]\n", *(p+8), *(p+8));
    printf("s: %c [%d]\n", *(s+8), *(s+8));
    printf("t: %c [%d / %d]\n", *(t+8), *(t+8) ,t[8]); 
    printf("\n");

    printf("\n==== print string + 8 ==== \n");
    printf("p: %s\n", (p+8));
    printf("s: %s\n", (s+8));
    printf("t: %s\n", (t+8));
    printf("\n");

    printf("\n==== print string using pointer arithmetic ==== \n");
    char * strptr = t;
    while (*strptr != '\0') {
        printf("[%c]", *strptr);
        strptr++;
    }
    printf("\n"); 

    return 0;
}
