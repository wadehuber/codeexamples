#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 100

/* Files get read with a trailing newline, which is often not what you want
   Loop through until we find a newline, then replace it with a null terminator */
void chomp(char * ptr) {
  while(*ptr != '\n') {
    ptr++;
  }
  *ptr='\0';
}

/* Add together the ASCII values of all characters in a string.  Note that this
   assumes we pass a valid string.  Technically this function counts the ASCII
   values of all bytes starting at ptr until a null terminator is reached.  */
int add_ascii(char * ptr) {
  int sum=0;
  while(*ptr != '\0') {
    sum = sum + *ptr;
    ptr++;
  }
  return sum;
}

int main(void) {
  FILE *infile, *outfile;   /* File pointers */
  FILE *fileptr;
  char inputbuffer[SIZE];
  char outstring[SIZE];
  int ii = 1;

  /* Open infile for reading ("r") and outfile for writing ("w") */
  infile = fopen("names.txt", "r");
  outfile = fopen("output.txt", "w");

  fileptr = fopen("names.txt", "r");
  int count = 0;
  for ( ; getc(fileptr) != EOF; count++) {
      ;
  }
  printf("The number of characters in the file is %d\n", count);
  fclose(fileptr);

  /* Read the input file line by line (in SIZE increments) */
  while ( fgets(inputbuffer, SIZE, infile) ) {
     chomp(inputbuffer);
     /* Quit if we see Bigfoot */
     if (strncmp(inputbuffer, "Bigfoot", SIZE) == 0) {
       continue;
     }
     printf("%2d: %s\n", ii, inputbuffer);

     /* Write a formatedd output line to outstring, then write outstring to the output file */
     sprintf(outstring, "Name=%s   ASCII total: %d\n", inputbuffer, add_ascii(inputbuffer));
     fputs(outstring, outfile);
     ii++;
  }

  /* Close the files since we are done with them */
  fclose(infile);
  fclose(outfile);

  return 0;
}

