# C5 - System calls, more C I/O, and review

## system.c

[Video](https://youtu.be/c7-tReUyBIc) (6.44) - example of using the system() call in C to execute a shell command.

## popen.c

[Video](https://youtu.be/3bAAYel7L9o) (3:57) - An example of using a popen to execute a shell command, which allows the program to read the output.  There is also an example of using the ```sed``` command.

## getsfgets.c

[Video](https://youtu.be/UoysSe194EE) (3:57) - Demonstrates why you should not use the C library function " gets() ".

## guess.c

[Video](https://youtu.be/MrOLG-6OFVQ) (4:20) - has an example of using compile-time symbolic constants to affect the way a program is built.

## readfile.c

[Video](https://youtu.be/UJ9FHescot4) (17:09) - another example of reading a file in a C program.  This file reads in a file containing numbers and generates the total.  Includes examples of using errno & strtok.

## bits.c

[Video](https://youtu.be/Ppjg-OVbA-Q) (20:16) - more examples of working with bits operations.  Includes examples of counting the bits in a byte of memory & using bit shifts to calculate powers of 2.

## stringappend.c

[Video](https://youtu.be/ztFcSBMWgSQ) (8:54) - Example of writing a string function that will append two strings into a new string.

## execve.c & userscript.sh

[Video](https://youtu.be/iq7puCxsgHQ) (10:04) - Using the execve() system call to replace the existing process with another program.  The file *userscript.sh* is a bash script that is used to demonstrate how execve() works.

## env1.c

[Video](https://youtu.be/wJ2ZPdc-5uw) (8:21) - Accessing Linux environment variables using getenv, envp, & environ

## env2.c

[Video](https://youtu.be/uYb89zsJHE4) (5:26) - Modifying Linux environment variables using setenv & putenv

## gdbtest.c

[Video](https://youtu.be/8AHT8uJX38k) (6:48) - Demonstration of using gdb.  
