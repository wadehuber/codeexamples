/* Example of struct sizing */
#include<stdio.h>

/* User defined types with 3 ints & 4 chars */
struct tightstruct {
    int num1; 
    int num2; 
    int num3; 
    char char1;
    char char2;
    char char3;
    char char4;
};

/* alternating char int - since ints must be word aligned each int
 *  will start after 3 bytes of char padding, wasting 3 bytes
 */
struct loosestruct {
    char char1;
    int num1; 
    char char2;
    int num2; 
    char char3;
    int num3; 
    char char4;
};

/* bitfield example (word padding still applies!) */
struct bitfield {
    int a : 10;   /* 10 bit int */
    int b : 5;    /*  5 bit int */
    unsigned int c : 1;    /*  1 bit unsigned int */
};

int main(void) {
    struct tightstruct tstruct = {0,1,2,'A','B','C','D'};
    struct loosestruct lstruct = {'W',7,'X',8,'Y',9,'Z'};
    struct bitfield bstruct = {7, 2, 1};


    printf("tightstruct: size=%ld, values: %d %d %d %c %c %c %c\n", 
            sizeof(tstruct),
            tstruct.num1, tstruct.num2, tstruct.num3, tstruct.char1,
            tstruct.char2, tstruct.char3, tstruct.char4);
    printf("loosestruct: size=%ld, values: %d %d %d %c %c %c %c\n", 
            sizeof(lstruct),
            lstruct.num1, lstruct.num2, lstruct.num3, lstruct.char1,
            lstruct.char2, lstruct.char3, lstruct.char4);
    printf("   bitfield: size=%ld, values: %d %d %u\n", 
            sizeof(bstruct), bstruct.a, bstruct.b, bstruct.c);

    return(0);
}
