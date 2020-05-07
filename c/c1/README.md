
### arrays.c
*Declaring and initialiing arrays.  Array sizes.  sizeof.*
The important thing to keep in mind about C arrays is that C does not perform any bounds checking.  So you can use an index that is larger than the size of the array!  What happens in that case?  In C the size of the array is the number of bytes allocated for the array, not the number of elements in the array.  So to determine the number of elements in an array you have to divide its size by the size of the type of the element it stores.  One caveat to keep in mind - even the size of the array is lost when you pass the array to a function.  So if you want to write a function that takes an array as a parameter you should include a length parameter as well.

### strings.c
*String handling in C.  Initializing strings vs character arrays.*
C does not have a string type.  Strings are represented using null-terminated character arrays.  So if you have a valid string (character array) and you change the element where the null-terminator - '\0' - is stored then you no longer have a valid string.  When you perform an operation on a string, including printf, the operation continues until a null-terminator is reached.  This can be a problem if the string is not valid, so when writing functions that work on strings you should always include the length as a parameter.

### functions.c
*Defining & calling functions in C. Passing paremeters by pointer (reference).  Forward declarations.*
In C, the compiler has to know the function signature before it is called in the code.  One way to do this is to include a forward declaration, which is just the function signature followed by a semi-colon.  In cases where the parameter is intended to be changed in the function we use pass-by-address: the parameter is preceded by * in the declaration (formal parameter) and when it is called (actual parameter) it is preceded by a &.  If an array is passed as a parameter then the formal parameter does not need to include the length of the array as that is not passed to the function.

### countspaces.c
*Calling a function with an array pointer.  Getting string input from user using fgets.  Symbolic constants.*
We have to pass the length of the array to the function so the loop will know when to stop.  The fgets() function has 3 parameters - the array you want to fill with the user input, the length of the array, and the file to read from.  The identifier stdin refers to standard input (stdout is output and stderr is for errors). 

### usertypes.c
*User-defined types in C, including enums, structs, and unions.  typedef.*

### stuructsize.c
*Size of structures with similar fields.  Bitfields.*

