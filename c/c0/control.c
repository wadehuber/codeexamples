/* C Control Structure examples */
#include <stdio.h>
 
int main (void)
{
  int a = 5;
  int b, ii;
 
  printf ("Enter an integer : ");
  scanf ("%d", &b);
 
  printf ("\nIf-then-else statment : ");
  if (a < b)
      printf("%d is less than %d\n", a, b);
  else
      printf("%d is not less than %d\n", a, b);
 
  printf ("\nSwitch statement : ");
  switch (b)
  {
    case 1 :
      printf("You entered a one.\n");
      break;  /* Without the break execution will continue to the next line */
    case 2 :
      printf("You entered a two.\n");
      break;
    case 3 :
      printf("You entered a three.\n");
      break;
    case 4 :
      printf("You entered a four\n");
      break;
    default :  /* The default case is used when no other cases match */
      printf("You entered a number greater than 4 or less than 1\n");
  }
  
  printf ("\nWhile loop : \n");
  ii = 0;
  while (ii <= b)
  {
      printf ("  Your number = %d, loop variable = %d\n", b, ii);
      ii = ii + 2;
  }
  
  /* The body of a do-while loop is always executed at least once */ 
  printf ("\nDo-while loop : \n");
  do {
      printf ("  Your number = %d, loop variable = %d\n", b, ii);
      ii -= 2;
  } while ( (ii > 0) );
  

  /* Note: in C the loop variable must be declared before the loop */
  printf ("\nFor loop : \n");
  for (ii=0;ii<b;ii++) {
    printf ("  loop variable = %d\n", ii);
  }
 
  /* The break statement exists the current loop */
  printf ("\nBreak example : \n");
  for(;;) { 
      /* If a is bigger than 100 quit the loop */
      if (a > 100) {
          printf ("  Breaking . . \n");
          break;
      }
      else {
          a++;
      }
  }

  /* The continue statment skips the rest of the current iteration */ 
  printf ("\nContinue example : \n");
  for (ii=0;ii<=b;ii++) {
      /* If ii is not a multiple of 3 then go to next loop iteration */
      if ( (ii % 3) != 0) {
          continue; 
      }
      printf ("  %d", ii);
  }
  printf ("\n");
 
  return 0;
}

