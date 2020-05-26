#include<stdio.h>

/* compile with gcc -DDEBUG debug.c to get debug logs */

#ifdef DEBUG
#define PRINTDEBUG(fmt,...) fprintf(stderr, fmt, __VA_ARGS__)
#else
#define PRINTDEBUG(fmt,...)
#endif

int main(void) {
    int ii, x=10, y=0;

    PRINTDEBUG("DEBUG %d\n", x);

    y = 0;
    for (ii=0;ii<4;ii++) {
#ifdef DEBUG
        fprintf(stderr, "Debug: y=%d\n", y);
#endif
        y++;
    }

    for (ii=0;ii<4;ii++) {
        PRINTDEBUG("DEBUG x=%d\n", x);
        printf("%d: %d\n",ii,x);
        x+=y;
        PRINTDEBUG("DEBUG after x+=y: x=%d\n", x);
    }
    return 0;
}
