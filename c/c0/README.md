### hello.c
*A hello world example.*
The #include statement brings in the forward declaration for the printf function.

### c_overview.c
*Example of several different C features*
Video - https://youtu.be/uUtQIEIxvWY 
This file goes over many of the features of C you will need to know, including data types, printf, structures, calling functions, and arrays.

### inputoutput.c
*Getting user input in C using scanf.*
Note that scanf is not the best way to do it, but will suffice at first.  The scanf function takes a pointer to a variable as its parameter so we need to pass the address (&) of the variable.  We will go into more detail later in the course.

### control.c
*Control structures in C such as loops, conditional statements, and controling loop execution.*
The syntax in this file should look familiar to you since, other than the input and output statements, almost every line of code is valid Java syntax.  The scanf function gets input and stores it at the address given - the & operator gets the address of a variable.  We will discuss that operator more when we discuss pointers. 

### datatypes.c
*Examples of different data types built in to C and how we can work with them.*
Multiple examples of declaring and printing different data types.  The variable declarations have multiple examples of different types of literals (a token that represents a fixed value).  The printf statement allows you to include values in the output string through the use of control sequences.  The control sequences are replaced by the expression(s) that follows the output string.  Note that whatever expression you try to print will be implicitly converted to the type declared in the control sequence.  That can cause confusion when you print a negative number using the %u control sequence, so if you get unexpected output always check that you are using the correct control sequence for the variable.  Additional control sequences are listed in the C notes.


