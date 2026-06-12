# C Pointers

Note - I strongly recommend using a static analysis tool such as cppcheck (See [this video](https://youtu.be/oJ8SXVoefaA)) (3:37) when working with pointers to help you avoid common mistakes.  

VIDEO: [Overview of C Pointers](https://youtu.be/w-EykTbqyls) (4:46)

## Introduction to pointers

The following videos introduce pointers and show how they relate to arrays and strings.  

### [pointer.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/pointer.c)

[Video](https://youtu.be/dc8euF3aIVc) (11:02) - *Pointers, referencing & dereferencing, allocating memory, sizeof pointers*
This file has examples of referencing & dereferencing pointers and variables.  malloc allocates a certain number of bytes.  If you want to allocate an array, make sure you allocate the number of elements you want times the size of the type of the array.

### [refderef.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/refderef.c)

A focused review of the two pointer operators: & (the address-of operator) gets the address of a variable, and * (the dereference operator) follows an address to access the value stored there.  Includes an example of changing a variable's value through a pointer.

### [lvaluervalue.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/lvaluervalue.c)

Explains the difference between lvalues (expressions that refer to a location in memory, which can appear on the left side of an assignment) and rvalues (values used in expressions, which cannot be assigned to).  Understanding this distinction helps make sense of compiler error messages.

### [pointerarithmetic.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/pointerarithmetic.c)

[Video](https://youtu.be/pBrCD9A_i_w) (15:06) - *Pointer arithmetic*
This file has examples of how arithmetic with pointers works.

### [arrayvsptr.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/arrayvsptr.c)

[Video](https://youtu.be/DhoPMlB4RiE) (14:09) - *Using array names & pointers*
This file has examples showing the similarities & differences between pointers.  If we declare a variable with type `char *` then it is a pointer.  A variable with type `char[]` is an array.  We can use the *names* of pointers and arrays in the same way (as shown in this example), so in that way they are similar.  However, an array variable has memory allocated for it whereas a pointer variable does not - it only has memory allocated to hold an address.

### [structptr.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/structptr.c)

[Video](https://youtu.be/IgqKL9Nr63A) (12:16) - *Struct pointers*
This file has an example of using a pointer to a struct.

### [arrowvsdot.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/arrowvsdot.c)

Shows when to use the dot operator vs the arrow operator with structs: use the dot operator (s1.id) with a regular struct variable and the arrow operator (ptr->id) with a pointer to a struct.  The arrow operator is shorthand for dereferencing the pointer then using the dot operator.

### [doublepointer.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/doublepointer.c)

[Video](https://youtu.be/P2B1FT8okyc) (10:22) - *Double pointers*

Double pointers are simply pointers that hold the address of a pointer.  This video starts off with a review of pointers then discusses double pointers with an example of a function that takes a double pointer as a parameter.  

### [voidpointer.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/voidpointer.c)

[Video](https://youtu.be/6ahM6eSxgUU) (7:58) - *void pointers*
This file has an example of working with void pointers.

### [alloc.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/alloc.c)

[Video](https://youtu.be/i0N4f2AcAS0) (29:10) - *Examples of allocating memory, including arrays and structs*
malloc, calloc, puts, exit

Note that after the video ended line 33 of alloc.c was changed to ```if(nums == NULL) {``` to correct the variable name.

### [splat.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/splat.c)

[Video](https://youtu.be/mSVhgq2Czqg) (5:51) - *The different ways you can use a star/asterisk/splat in C*

This is to help review how the * is used in C.

### [pointer_review.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/pointer_review.c)

[Video](https://youtu.be/oGiUw35seyE) (23:10) - *Overview of pointer usage in C*
This file has several different examples of using pointers, including an example of using malloc to allocate memory. 

## Strings & Pointers

### [stringvsptr.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/stringvsptr.c)

[Video](https://youtu.be/tymWEU5YHAQ) (18:43) - *Pointers, referencing & dereferencing, allocating memory, sizeof pointers*
This file has examples of referencing & dereferencing pointers and variables.  malloc allocates a certain number of bytes.  If you want to allocate an array, make sure you allocate the number of elements you want times the size of the type of the array.

### [stringfunctions.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/stringfunctions.c)

[Video](https://youtu.be/kiYo4G1XqL4) (29:26) - *Example of writing functions with string parameters & C string functions*
strncpy, strcat, strncmp, sprintf

### [sprintf.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/sprintf.c)

Demonstrates building a string with sprintf and snprintf.  snprintf is usually the safer choice because it receives the size of the destination array, which helps prevent writing past the end of the buffer.  Also shows the C pattern of "returning" a string by having the caller create the array and passing it to a function that fills it.

### [stringsmash.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/stringsmash.c)

A demonstration of what happens when a string operation writes past the end of a character array (a buffer overflow) - the bytes of neighboring variables get overwritten.  This example shows *why* you should always use the length-limited string functions and pass buffer sizes.  Do not try this at home!

## Advanced pointer examples

### [memdump.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/memdump.c)

First, a refresher on [converting hex values to binary](https://youtu.be/EXyDKPDfX8I) (2:20).  We will be looking at hex values for each bytes.  Two hex values represent one byte which is 8 bits.  

[Video](https://youtu.be/cUf0rzF17_M) (10:42) - *Examining memory byte-by-byte*
Example function that will print out memory byte-by-byte using a char pointer.  In this example we use the function to examine the contents of a struct.

### [morearrayptr.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/morearrayptr.c)

[Video](https://youtu.be/XLxG70C3ers) (13:12) - *Two dimensional arrays, accessing elements of an array using a pointer*
This file has an example of a 1D & 2D array and how to access their members.

### [raggedstringarray.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/raggedstringarray.c)

[Video](https://youtu.be/Vos7q5mvZOE) (4:25) - *Example of allocating strings in an array of pointers vs an array of arrays (2D array)*
There are multiple ways of creating an array of strings.  In this example we compare allocating arrays of strings as arrays of pointers and arrays of arrays.

### [memorylocation.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/memorylocation.c)

[Video](https://youtu.be/1ow7JAahG0s) (13:08) - *Examples of allocation of different memory locations*
This file has examples of allocating heap, stack, & static memory.

### [debug.c](https://github.com/wadehuber/codeexamples/blob/master/c/c2/debug.c)

[Video](https://youtu.be/A7wuwnkcGPY) (9:29) - *Using the preprocessor for debugging*
This file has examples of using the preprocessor to allow a file to be compiled to display debugging information.  This is optional, but you may find it helpful to do something similar with your code to help you debug your program.
