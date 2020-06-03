#include<stdio.h>

#define SIZE 100

/* Files get read with a trailing newline, which is often not what you want
   Loop through until we find a newline, then replace it with a null terminator */
void chomp(char *ptr) {
    while ( (*ptr != '\n') &&  (*ptr != '\0') ) {
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
    FILE * infile, *outfile;   /* file pointers */
    char inputbuffer[SIZE];
    char outstring[SIZE*2];
    int counter=0;

    /* Open infile for reading & outfile for writing*/
    infile = fopen("names.txt", "r");
    outfile = fopen("output.txt", "w");

    /* Read the input file line by line (in SIZE increments) */
    counter = 0;
    while ( fgets(inputbuffer, SIZE, infile) ) {
        chomp(inputbuffer);
        printf("%2d: %s\n", counter, inputbuffer);

        /* Write a formatted output line to outstring then write 
         *   outstring to the output file */
        sprintf(outstring, "Name=%s  [%d]\n", inputbuffer,
                                              add_ascii(inputbuffer));
        fputs(outstring, outfile);
        counter ++;
    }
    
    /* close the files since we are done with them */
    fclose(infile);
    fclose(outfile);


    /* Count the number of characters in the file */
    infile = fopen("names.txt", "r");
    counter=0;
    while( getc(infile) != EOF ) {
        counter++;
    }
    fclose(infile);
    printf("The number of characters in the file is %d\n", counter);

    return 0;
}

