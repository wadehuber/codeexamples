# C Pointers

Note - I strongly recommend using a static analysis tool such as cppcheck (See [this video](https://youtu.be/oJ8SXVoefaA)) (3:37) when working with pointers to help you avoid common mistakes.  

VIDEO: [Overview of C Pointers](https://youtu.be/w-EykTbqyls) (4:46)

## Introduction to pointers

The following videos introduce pointers and show how they relate to arrays and strings.  

### pointer.c

[Video](https://youtu.be/woUn-BuAvEg) (11:02) - *Pointers, referencing & dereferencing, allocating memory, sizeof pointers*
This file has examples of referencing & dereferencing pointers and variables.  malloc allocates a certain number of bytes.  If you want to allocate an array, make sure you allocate the number of elements you want times the size of the type of the array.

### pointerarithmetic.c

[Video](https://youtu.be/DpMnOg1Roj4) (15:05) - *Pointer arithmetic*
This file has examples of how arithmetic with pointers works.

### arrayvsptr.c

[Video](https://youtu.be/qa3xXcoI7z0) (14:08) - *Using array names & pointers*
This file has examples showing the similarities & differences between pointers.  If we declare a variable with type `char *` then it is a pointer.  A variable with type `char[]` is an array.  We can use the *names* of pointers and arrays in the same way (as shown in this example), so in that way they are similar.  However, an array variable has memory allocated for it whereas a pointer variable does not - it only has memory allocated to hold an address.

### structptr.c

[Video](https://youtu.be/60qUR7uJa_I) (12:15) - *Struct pointers*
This file has an example of using a pointer to a struct.

### doublepointer.c

[Video](https://youtu.be/P2B1FT8okyc) (10:22) - *Double pointers*

Double pointers are simply pointers that hold the address of a pointer.  This video starts off with a review of pointers then discusses double pointers with an example of a function that takes a double pointer as a parameter.  

### voidpointer.c

[Video](https://youtu.be/QEQot5CqdYs) (7:57) - *void pointers*
This file has an example of working with void pointers.

### alloc.c

[Video](https://youtu.be/4pjzT5sfCHU) (29:09) - *Examples of allocating memory, including arrays and structs*
malloc, calloc, puts, exit

Note that after the video ended line 33 of alloc.c was changed to ```if(nums == NULL) {``` to correct the variable name.

### pointer_review.c

[Video](https://youtu.be/xQAoSUNrGq4) (23:09) - *Overview of pointer usage in C*
This file has several different examples of using pointers, including an example of using malloc to allocate memory.  T

## Strings & Pointers

### stringvsptr.c

[Video](https://youtu.be/oysI9kgp0Cg) (18:42) - *Pointers, referencing & dereferencing, allocating memory, sizeof pointers*
This file has examples of referencing & dereferencing pointers and variables.  malloc allocates a certain number of bytes.  If you want to allocate an array, make sure you allocate the number of elements you want times the size of the type of the array.

### stringfunctions.c

[Video](https://youtu.be/5gqW7nP47fMco) (29:25) - *Example of writing functions with string parameters & C string functions*
strncpy, strcat, strncmp, sprintf

## Advanced pointer examples

### memdump.c

[Video](https://youtu.be/xdrX_RDj5_0) (10:42) - *Examining memory byte-by-byte*
Example function that will print out memory byte-by-byte using a char pointer.  In this example we use the function to examine the contents of a struct.

### morearrayptr.c

[Video](https://youtu.be/UsR9A3o7DFM) (13:11) - *Two dimensional arrays, accessing elements of an array using a pointer*
This file has an example of a 1D & 2D array and how to access their members.

### raggedstringarray.c

[Video](https://youtu.be/LDM-3__LixI) (4:49) - *Example of allocating strings in an array of pointers vs an array of arrays (2D array)*
There are multiple ways of creating an array of strings.  In this example we compare allocating arrays of strings as arrays of pointers and arrays of arrays.

### memorylocation.c

[Video](https://youtu.be/d9y3u1j5b1A) (13:07) - *Examples of allocation of different memory locations*
This file has examples of allocating heap, stack, & static memory.

### debug.c

[Video](https://youtu.be/lsEcaRfpRuE) (9:28) - *Using the preprocessor for debugging*
This file has examples of using the preprocessor to allow a file to be compiled to display debugging information.  This is optional, but you may find it helpful to do something similar with your code to help you debug your program.
