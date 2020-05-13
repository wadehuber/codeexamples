# Introduction to C

The examples below are intended to give you a fast introduction to C.  If you are coming from Java, some of the examples, such as control.c, should look familiar.

## hello.c

[Video](https://youtu.be/_-pZgDV7vFk) - *A hello world example.*

The #include statement brings in the forward declaration for the printf function.

## c_overview.c

[Video](https://youtu.be/uUtQIEIxvWY) - *Example of several different C features*

This file goes over many of the features of C you will need to know, including data types, printf, structures, calling functions, and arrays.

## inputoutput.c

[Video](https://youtu.be/EmxakpZJv1o) - *Getting user input in C using scanf.*

Note that scanf is not the best way to do it, but will suffice at first.  The scanf function takes a pointer to a variable as its parameter so we need to pass the address (&) of the variable.  We will go into more detail later in the course.

## control.c

*Control structures in C such as loops, conditional statements, and controling loop execution.*

The syntax in this file should look familiar to you since, other than the input and output statements, almost every line of code is valid Java syntax.  The scanf function gets input and stores it at the address given - the & operator gets the address of a variable.  We will discuss that operator more when we discuss pointers.

## datatypes.c

[Video](https://youtu.be/10ewFOh8pKQ) - *Examples of different data types built in to C and how we can work with them.*

Multiple examples of declaring and printing different data types.  The variable declarations have multiple examples of different types of literals (a token that represents a fixed value).  The printf statement allows you to include values in the output string through the use of control sequences.  The control sequences are replaced by the expression(s) that follows the output string.  Note that whatever expression you try to print will be implicitly converted to the type declared in the control sequence.  That can cause confusion when you print a negative number using the %u control sequence, so if you get unexpected output always check that you are using the correct control sequence for the variable.  Additional control sequences are listed in the C notes.

## countlines.c

[Video](https://youtu.be/0pKn8HOwW9Q) - *Count the number of lines in a file.*

This example shows how to read input from stdin character by character.  

## temps.c

[Video](https://youtu.be/3kQz0KsnDz4) - *Fahrenheit to Celcius conversion.*

Create a table of Fahrenheit to Celcius conversion.
