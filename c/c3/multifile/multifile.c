#include<stdio.h>
#include"mystuff.h"

int main(void) {
  printf("Max 1: %d\n", MAX(20, 13));
  printf("Max 2: %d\n", MAX(NUM, 13));
  printf("Max 3: %d\n", max_of_three(20, 13, NUM));
  return 0;
}
