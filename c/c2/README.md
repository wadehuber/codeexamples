# C Pointers

## pointer.c

[Video](https://youtu.be/woUn-BuAvEg) - *Pointers, referencing & dereferencing, allocating memory, sizeof pointers*
This file has examples of referencing & dereferencing pointers and variables.  malloc allocates a certain number of bytes.  If you want to allocate an array, make sure you allocate the number of elements you want times the size of the type of the array.

## pointerarithmetic.c

[Video](https://youtu.be/DpMnOg1Roj4) - *Pointer arithmetic*
This file has examples of how arithmetic with pointers works.

## arrayvsptr.c

[Video](https://youtu.be/qa3xXcoI7z0) - *Using array names & pointers*
This file has examples showing the similarities & differences between pointers.  If we declare a variable with type `char *` then it is a pointer.  A variable with type `char[]` is an array.  We can use the *names* of pointers and arrays in the same way (as shown in this example), so in that way they are the similar.  However, an array variable has memory allocated for it whereas a pointer variable does not - it only has memory allocated to hold an address.

## stringvsptr.c

[Video](https://youtu.be/oysI9kgp0Cg) - *Pointers, referencing & dereferencing, allocating memory, sizeof pointers*
This file has examples of referencing & dereferencing pointers and variables.  malloc allocates a certain number of bytes.  If you want to allocate an array, make sure you allocate the number of elements you want times the size of the type of the array.

## structptr.c

[Video](https://youtu.be/60qUR7uJa_I) - *Struct pointers*
This file has an example of using a pointer to a struct.

## voidpointer.c

[Video](https://youtu.be/QEQot5CqdYs) *void pointer*
This file has an example of working with void pointers.

## alloc.c

[Video](https://youtu.be/4pjzT5sfCHU) - *Examples of allocating memory, including arrays and structs*
malloc, calloc, puts, exit

Note that after the video ended line 33 of alloc.c was changed to ```if(nums == NULL) {``` to correct the variable name.

## morearrayptr.c

[Video](https://youtu.be/UsR9A3o7DFM) - *Two dimensional arrays, accessing elements of an array using a pointer*
This file has an example of a 1D & 2D array and how to access their members.

## raggedstringarray.c

[Video](https://youtu.be/LDM-3__LixI) - *Example of allocating strings in an array of pointers vs an array of arrays (2D array)*
There are multiple ways of creating an array of strings.  In this example we compare allocating arrays of strings as arrays of pointers and arrays of arrays.

## stringfunctions.c

[Video](https://youtu.be/5gqW7nP47fMco) - *Example of writing functions with string parameters & C string functions*
strncpy, strcat, strncmp, sprintf

## memorylocation.c

[Video](https://youtu.be/d9y3u1j5b1A) - *Examples of allocation different memory locations*
This file has examples of allocating heap, stack, & static memory.

## debug.c

[Video](https://youtu.be/lsEcaRfpRuE) - *Using the preprocessor for debugging*
This file has examples of using the preprocessor to allow a file to be compiled to display debugging information.  This is optional, but you may find it helpful to do something similar with your code to help you debug your program.  

## pointer_review.c

[Video](https://youtu.be/xQAoSUNrGq4) - *Overfiew of pointer usage in C*
This file has several different examples of using pointers, including an example of using malloc to allocate memory.
