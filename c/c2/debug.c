#include<stdio.h>

/* compile with gcc -DDEBUG debug.c to get debug logs */

#ifdef DEBUG
#define PRINTDEBUG(fmt, ...)  fprintf(stderr, fmt, __VA_ARGS__)
#else
#define PRINTDEBUG(fmt, ...)
#endif

int main()
{
  int ii, x=10, y=0;
  PRINTDEBUG("  DEBUG %d", x);

  y = 0;
  for (ii=0;ii<4;ii++) {
    #ifdef DEBUG
    fprintf(stderr, "Debug: y=%d\n", y);
    #endif
    y++;
  }

  for (ii=0;ii<4;ii++) {
    PRINTDEBUG("  DEBUG %d", x);
    printf("%d: %d\n",ii,x);
    x+=y;
    PRINTDEBUG("  DEBUG %d", x);
  }
  return 0;
}
