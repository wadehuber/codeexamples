#include<stdio.h>

int main(void) {
  int c;
  int nl=0, caps=0, lowers=0, nums=0;

  while ( (c = getchar()) != EOF ) {
    if (c == '\n') {
      nl++;
    }
    else if ( (c >= 'A') && (c <= 'Z') ) {
      caps++;
    }
    else if ( (c >= 'a') && (c <= 'z') ) {
      lowers++;
    }
    else if ( (c >= '0') && (c <= '9') ) {
      nums++;
    }
  }
  printf("There were %d newlines!\n", nl);
  printf("There were %d upper case characters!\n", caps);
  printf("There were %d lower case characters!\n", lowers);
  printf("There were %d numbers!\n", nums);

  return 0;
}
