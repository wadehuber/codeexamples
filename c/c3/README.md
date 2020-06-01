# C3 - Multi-file programs, linked lists, constants, & recursion

## recursion.c

[Video](https://youtu.be/apSfrXPSRNg) - *Recursion examples*
This file uses the Fibonacci function to demonstrate a loop-based implemenation, an naive recursive implemenatation, and a tail-recursive implenation.  

## constants.c

[Video](https://youtu.be/svbqz77Fox4) - *Using constants in C*
This file has examples of symbolic & enumeration constants as well as constant variables.  It also shows how the value of a "constant" variable can be changed.  A constant variable is different from a symbolic constant since the constant variable will have memory allocated to it and we can have pointers to it, we just can't change it directly.  

## mystuff_originial.c / multifile

[Video](https://youtu.be/jHYn7b6NwLc) & [makefile video](https://youtu.be/rnPmx6-AiOs) - *Multifile C program example*
This mystuff_original.c file is split up into several files in the multifile directory.

## multifile2

[Video](https://youtu.be/lGfscPcDegY) = *A second multfile example*
Includes more examples of working with the preprocessor.  Also includes examples of inline functions.

## basiclist

[Video](https://youtu.be/yBF8AxoSO6I) - *Simple example of a linked list in C*
The basicilist.h is the header file that contains the struct definition and forward declarations for our linked list functions.  We use a node_t pointer to point to the first element in our linked list.  In the basiclist.c file, the list_add function takes a double pointer to the list (since it will add the new element to the front of the list) and a pointer to the data.  Since we don't know what type of data we are adding to the list, we use a void *.  The user of the code will need to handle casting back to the correct type.  The list_remove_first funtion frees the memory associated with the first element then points the list to the 2nd element.  There is also a test main function that will be compiled if you use the -DTEST flag.  The main method in basiclist.c creates a list of integers then prints them out.  
