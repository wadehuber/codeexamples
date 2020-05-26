#include<stdio.h>
#include<stdlib.h>

int globalVar = 10;                    /* Static memory */

void func(int fParameter) {
  int fLocalVar = 20;                  /* Stack memory */
  static int fStaticLocalVar = 30;     /* Static memory */

  printf("FUNCTION: fParameter=%d at %p\n", fParameter, (void *) &fParameter);
  printf("FUNCTION: fLocalVar=%d at %p\n", fLocalVar, (void *) (void *) &fLocalVar);
  printf("FUNCTION: fStaticLocalVar=%d at %p\n", fStaticLocalVar, (void *) &fStaticLocalVar);
  printf("FUNCTION: globalVar=%d at %p\n", globalVar, (void *) &globalVar);

  globalVar++;
  fStaticLocalVar++;
}

int main(void) {
  int mLocalVar = 40;                  /* Stack memory */
  static int mStaticLocalVar = 50;     /* Static memory */

  int * mLocalVarPtr;                  /* Stack memory */
  mLocalVarPtr = malloc(sizeof(int));  /* Heap memory */
  *mLocalVarPtr = 60;

  printf("MAIN: mLocalVar=%d at %p\n", mLocalVar, (void *) &mLocalVar);
  printf("MAIN: mStaticLocalVar=%d at %p\n", mStaticLocalVar, (void *) &mStaticLocalVar);
  printf("MAIN: mLocalVarPtr=%p (value=%d) at %p\n", (void *) mLocalVarPtr, 
		                                     *mLocalVarPtr, (void *) &mLocalVarPtr);
  printf("MAIN: globalVar=%d at %p\n", globalVar, (void *) &globalVar);
  printf("\n");

  globalVar ++;
  func(100);
  printf("\n");

  globalVar ++;
  printf("MAIN: mLocalVar=%d at %p\n", mLocalVar, (void *) &mLocalVar);
  printf("MAIN: mStaticLocalVar=%d at %p\n", mStaticLocalVar, (void *) &mStaticLocalVar);
  printf("MAIN: mLocalVarPtr=%p (value=%d) at %p\n", (void *) mLocalVarPtr, 
		                                     *mLocalVarPtr, (void *) &mLocalVarPtr);
  printf("MAIN: globalVar=%d at %p\n", globalVar, (void *) &globalVar);
  printf("\n");

  func(200);
  printf("\n");

  printf("MAIN: globalVar=%d at %p\n", globalVar, (void *) &globalVar);
  
  free(mLocalVar);
  return 0;
}
