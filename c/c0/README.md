# Introduction to C

The examples below are intended to give you a fast introduction to C.  If you are coming from Java, some of the examples, such as control.c, should look familiar.

## Introductory examples

This section examples go over programming basics in C

### [hello.c](https://github.com/wadehuber/codeexamples/blob/master/c/c0/hello.c)

[Video](https://youtu.be/_-pZgDV7vFk) (2:20) - *A hello world example.*

Editing, compiling, & running a C program.  The #include statement brings in the forward declaration for the printf function.

### [c_overview.c](https://github.com/wadehuber/codeexamples/blob/master/c/c0/c_overview.c)

[Video](https://youtu.be/6loLv3xSBmo) (19:45) - *Summary of C features*

This file goes over many of the features of C you will need to know, including data types, printf, structures, calling functions, and arrays.  All of the material in this video is covered in more detail in the videos below.

### [inputoutput.c](https://github.com/wadehuber/codeexamples/blob/master/c/c0/inputoutput.c)

[Video](https://youtu.be/EmxakpZJv1o) (3:22) - *Getting user input in C using scanf.*

Note that scanf is not the best way to do it, but will suffice at first.  The scanf function takes a pointer to a variable as its parameter so we need to pass the address (&) of the variable.  We will go into more detail later in the course.

### [printf.c](https://github.com/wadehuber/codeexamples/blob/master/c/c0/printf.c)

[Video](https://youtu.be/xkL6KTnslkU) (6:58) - *Examples of using printf in C*

This video starts with an overview of editing, compiling, & running C programs using Ubuntu on Windows.  It then goes over printf control sequences, including printing integer values as decimal, octal, and hexidecmial values, formatting floating point numbers, escape sequences for tabs & newlines, & printing in columns.  Most of this material is available in other examples, but is presented here to give a dedicated overview.

### [datatypes.c](https://github.com/wadehuber/codeexamples/blob/master/c/c0/datatypes.c)

[Video](https://youtu.be/10ewFOh8pKQ) (19:47) - *Examples of different data types built in to C and how we can work with them.*

Multiple examples of declaring and printing different data types.  The variable declarations have multiple examples of different types of literals (a token that represents a fixed value).  The printf statement allows you to include values in the output string through the use of control sequences.  The control sequences are replaced by the expression(s) that follows the output string.  Note that whatever expression you try to print will be implicitly converted to the type declared in the control sequence.  That can cause confusion when you print a negative number using the %u control sequence, so if you get unexpected output always check that you are using the correct control sequence for the variable.  Additional control sequences are listed in the C notes.

## Control structures

The videos in this section go in to some more detail into control structures in C.  For the most part, there isn't much difference between C and Java, so you can skip these if you would like.

### [control.c](https://github.com/wadehuber/codeexamples/blob/master/c/c0/control.c)

[Video](https://youtu.be/liSw02tckLQ) (18:39) - *Control structures in C such as loops, conditional statements, and controling loop execution.*

The syntax in this file should look familiar to you since, other than the input and output statements, almost every line of code is valid Java syntax.  The scanf function gets input and stores it at the address given - the & operator gets the address of a variable.  We will discuss that operator more when we discuss pointers.

### [switch.c](https://github.com/wadehuber/codeexamples/blob/master/c/c0/switch.c)

[Video](https://youtu.be/rqop-rnbiRk) (7:00) - *Switch vs if-else*

This file contains an example of two different if-else structures replaced with switch statements.

## Example Programs

The two files below are examples for CSC220.  CSC240 students may still find them interesting and countlines.c is similar to what you will do on the first C practice.

### [countlines.c](https://github.com/wadehuber/codeexamples/blob/master/c/c0/countlines.c)

[Video](https://youtu.be/0pKn8HOwW9Q) (5:41) - *Count the number of lines in a file.*

This example shows how to read input from stdin character by character.

### [temps.c](https://github.com/wadehuber/codeexamples/blob/master/c/c0/temps.c)

[Video](https://youtu.be/3kQz0KsnDz4) (4:17) - *Fahrenheit to Celcius conversion.*

Create a table of Fahrenheit to Celcius conversion.
