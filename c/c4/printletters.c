#include<stdio.h>
#include<stdlib.h>

#define LEN 8

int main(void) {
    int num;
    char buffer[LEN];
    char c;
    char start, end;

    printf("How many letters do you want to print? ");
    fgets(buffer, LEN-1, stdin);
    num = atoi(buffer);
    printf("What is the starting letter? ");
    fgets(buffer, LEN-1, stdin);
    start = buffer[0];
    printf("What is the ending letter? ");
    fgets(buffer, LEN-1, stdin);
    end = buffer[0];

    for(int ii=0;ii<num;ii++) {
        c = start + (ii % (end-start+1));
        putc(c, stdout);
    }
    printf("\n");

    return 0;
}
