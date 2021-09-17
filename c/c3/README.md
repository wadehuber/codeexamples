# C3 - Multi-file programs, linked lists, constants, & recursion

## recursion.c

[Video](https://youtu.be/apSfrXPSRNg) (16:15) - *Recursion examples*
This file uses the Fibonacci function to demonstrate a loop-based implemenation, an naive recursive implemenatation, and a tail-recursive implenation.  

Additional videos on recursion (also part of Scheme 2 for CSC240):

- [Thinking recursively video](https://youtu.be/zDJXVpHASuI) (3:33): *Walkhrough of recursive solutions to several problems*
- [Tail Recursion](https://youtu.be/zvoFWNNC99s) (10:40) goes over tail recursion using examples in Java & Python but which are both applicable to C

## constants.c

[Video](https://youtu.be/svbqz77Fox4) (8:48) - *Using constants in C*
This file has examples of symbolic & enumeration constants as well as constant variables.  It also shows how the value of a "constant" variable can be changed.  A constant variable is different from a symbolic constant since the constant variable will have memory allocated to it and we can have pointers to it, we just can't change it directly.  

## macros.c

[Video](https://youtu.be/aoV31pjY_2Y) (12:03) - *Using macros in C*
This file has examples of using macros to define symbolic constants and macro functions.  

## headers.c

[Video](https://youtu.be/dtlTKLIupgs) (9:00) - *Example of how header files work*

The intention of this video & example is to show how header files are included into a C source file.  We use the -E flag so that gcc will run the preprocessor but not compile the file since header files affect the C code that gets compiled.  We also discuss how to write guards and demonstrate what their purpose is.  See the multifile & multifile2 examples below for more information on writing header files and C programs with more than one C source file.

## mystuff_originial.c / multifile

 *Multifile C program example*
This example deomonstrates how to create a module (.h + .c files) from some macros and functions in the mystuff_original.c file that we may want to save for reuse later.  

- [Video](https://youtu.be/lJdCQPuFiOE) (11:16) - Creating the module
- [makefile video](https://youtu.be/rnPmx6-AiOs) (4:52) - A more indepth video about creating a makefile
- [Reusing modules video](https://youtu.be/TwjgmNYi2II) (5:55) - a video where we reuse the module created above

## multifile2

[Video](https://youtu.be/lGfscPcDegY) (19:29) - *A second multfile example*
Includes more examples of working with the preprocessor.  Also includes examples of inline functions.

## basiclist

[Video - Overview of Linked Lists](https://youtu.be/tDTx50zsji0) (11:34) for those of you who are rusty on your CSC205 material.

[Video](https://youtu.be/yBF8AxoSO6I) (22:44) - *Simple example of a linked list in C*
The basicilist.h is the header file that contains the struct definition and forward declarations for our linked list functions.  We use a node_t pointer to point to the first element in our linked list.  In the basiclist.c file, the list_add function takes a double pointer to the list (since it will add the new element to the front of the list) and a pointer to the data.  Since we don't know what type of data we are adding to the list, we use a void *.  The user of the code will need to handle casting back to the correct type.  The list_remove_first funtion frees the memory associated with the first element then points the list to the 2nd element.  There is also a test main function that will be compiled if you use the -DTEST flag.  The main method in basiclist.c creates a list of integers then prints them out.  

## structwithptr.c

[Video](https://youtu.be/x_fEDTaEmBk) (8:35) - *Example of allocating memory for a pointer to a struct*

If you have a structure that contains pointers, if you create a pointer to that structure you need to allocate memory for the structure itself, and also for the pointers it contains.
