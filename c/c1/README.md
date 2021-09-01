# C Data Types, Functions, & User-defined Types

## Introductory examples

### [arrays.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/arrays.c)

[Video](https://youtu.be/PIG-VKPtY9I) (9:47) - *Declaring and initialiing arrays.  Array sizes.  sizeof.*
The important thing to keep in mind about C arrays is that C does not perform any bounds checking.  So you can use an index that is larger than the size of the array!  What happens in that case?  In C the size of the array is the number of bytes allocated for the array, not the number of elements in the array.  So to determine the number of elements in an array you have to divide its size by the size of the type of the element it stores.  One caveat to keep in mind - even the size of the array is lost when you pass the array to a function.  So if you want to write a function that takes an array as a parameter you should include a length parameter as well.

### [strings.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/strings.c)

- [Video - Introduction to C strings](https://youtu.be/4JhnhLb4TBk) (4:05) - *Introduction to strings in C*
- [Video - strings.c](https://youtu.be/TfKL_UhKvKw) (14:07) - *Working with strings in C*

C does not have a string type.  Strings are represented using null-terminated character arrays.  So if you have a valid string (character array) and you change the element where the null-terminator - '\0' - is stored then you no longer have a valid string.  When you perform an operation on a string, including printf, the operation continues until a null-terminator is reached.  This can be a problem if the string is not valid, so when writing functions that work on strings you should always include the length as a parameter.

### [functions.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/functions.c)

[Video](https://youtu.be/4Ha7L_ub8uQ) (13:04) - *Defining & calling functions in C. Paremeter passing*
In C, the compiler has to know the function signature before it is called in the code.  One way to do this is to include a forward declaration, which is just the function signature followed by a semi-colon.  In cases where the parameter is intended to be changed in the function we use pass-by-address: the parameter is preceded by * in the declaration (formal parameter) and when it is called (actual parameter) it is preceded by a &.  If an array is passed as a parameter then the formal parameter does not need to include the length of the array as that is not passed to the function.

### [usertypes.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/usertypes.c)

[Video](https://youtu.be/p127cSHXHs4) (24:47) - *User-defined types in C, including enums, structs, and unions.  typedef.*

## Additional Examples

The videos below are intended to give you additional examples that may come in handy later in the semester

### [countspaces.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/countspaces.c)

[Video](https://youtu.be/Mysm2AS6Inc) (6:55) - *Calling a function with an array pointer.  Getting string input from user using fgets.  Symbolic constants.*
We have to pass the length of the array to the function so the loop will know when to stop.  The fgets() function has 3 parameters - the array you want to fill with the user input, the length of the array, and the file to read from.  The identifier stdin refers to standard input (stdout is output and stderr is for errors).

### [union.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/union.c)

[Video](https://youtu.be/UCDsmTC-FTE) (6:23) - *An example of a union of an int, double & string*

Unions are similar to structures (and identical in how they are declared other than being called unions), but a union will only be allocated enough memory for its *largest* member, whereas a struct will be allocated enough memory for all its members *combined*.  You would use a union if you want to have a variable that can hold differet types at different times.

### [structsize.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/structsize.c)

[Video](https://youtu.be/Llz6LeDT0YU) (13:07) - *Size of structures with similar fields.  Bitfields.*

### [unvssigned.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/unvssigned.c)

[Video](https://youtu.be/fuJwzxuGoeE) (4:33) - *Demonstration of comparisons between signed & unsigned ints*
This is an example of some of the pitfalls of working with signed vs unsigned integers.

### [rwchar.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/rwchar.c)

[Video](https://youtu.be/Az4fBCu8Xg0) (5:51) - *Reading and writing output character-by-character*

## Advanced Videos

The videos below cover topics that are required in CSC220 but which may be skipped in CSC240.

### [stdfiles.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/stdfiles.c)

[Video](https://youtu.be/1vKcUoc7FWU) (3:34) - *Example of stdout & stderr*
This example demonstrates how output can be directed to stdout or to stderr.

### [bitwise.c](https://github.com/wadehuber/codeexamples/blob/master/c/c1/bitwise.c)

[Video](https://youtu.be/8XIK3HlAjg0) (6:11) - *Examples of bitwise operations*
