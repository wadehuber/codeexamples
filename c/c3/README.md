### recursion.c
*Recursion examples*
This file uses the Fibonacci function to demonstrate a loop-based implemenation, an naive recursive implemenatation, and a tail-recursive implenation.  

### stringfunctions.c
*String Functions*
This file has examples of different string functions provided by C.

### constants.c
*Using constants in C*
This file has examples of symbolic & enumeration constants as well as constant variables.  It also shows how the value of a "constant" variable can be changed. 

### mystuff_originial.c / multifile`
*Multifile C program example*
This mystuff_original.c file is split up into several files in the multifile directory.

### basiclist
*Simple example of a linked list in C*
The basicilist.h is the header file that contains the struct definition and forward declarations for our linked list functions.  We use a node_t pointer to point to the first element in our linked list.  In the basiclist.c file, the list_add function takes a double pointer to the list (since it will add the new element to the front of the list) and a pointer to the data.  Since we don't know what type of data we are adding to the list, we use a void *.  The user of the code will need to handle casting back to the correct type.  The list_remove_first funtion frees the memory associated with the first element then points the list to the 2nd element.  There is also a test main function that will be compiled if you use the -DTEST flag.  The main method in basiclist.c creates a list of integers then prints them out.  
