# C Debugging Tips

## Execution issues

If your program exists without output, check for the following:

1. The program crashes before any output is generated
2. If you are running in an IDE or OS that opens a console for execution the program may run an exit before you see output.  Run the code from the command line or add a user input statement to the end.
3. Verify you are printing to `stdout`, not `stderr` or some other file and that you aren’t redirecting output (with | or >, etc.)

## Compile issues

### No such file or directory

If you get a `No such file or directory` error there are a few possibilities:

- You may not be in the correct directory.  Make sure you are in the same directory where your .c or .cpp files are.  
- If the error is coming from the flags (`std`, `pedantic`, or `Wall`), make sure you have a dash in front of the command with no spaces between the dash and the flag. Your flags should be:
    `gcc –std=c11 –pedantic –Wall filename.c`
- Make sure you entered the filename of your .c file correctly
- If you get this when you try to run, make sure you are issuing the correct command.  Depending on your platform, the compiler may generate a file called a.out (Linux, Mac,  Bash) or a.exe (Cygwin). If you used the -o option then you would have that name instead of “a”.  Make sure you use the correct filename.  Also, to run the file you should indicate that it is in the current directory, so put a ./ first (no spaces).  For example:

```(bash)
./a.exe
```

or

```(bash)
./a.out
```

### Undefined reference

```(text)
Undefined reference
```

This is typically the result of an error during the linking phase.  Make sure you are compiling all the C files you need (you can add more than one C file to your compile command).

### C++ style comments not allowed

```(text)
error: C++ style comments are not allowed in ISO C90
This is due to compiling with a C standard prior to C99.  C++ style comments - // - instead of C-style comments /* */ - are not allowed in C90 an earlier (the -ansi flag).  Remove the -ansi flag from your compile statement.
```

### Stray '\223' in program

```(text)
myprogram.c:4:5: error: stray '\223' in program
myprogram.c:4:5: error: stray '\224' in program
myprogram.c:8:11: warning: missing terminating " character [enabled by default]
myprogram.c:8:3: error: missing terminating " character
myprogram.c:9:1: error: expected expression before '}' token
myprogram.c:9:1: error: expected ';' before '}' token
```

The likely cause is that you did a copy & paste from a program that uses smart quotes (such as MS Word or Google Docs).  Double check each quote in your program to be sure you have an actual single/double quote and NOT a smart quote.

### Expected declaration or statement

```(text)
error: expected declaration or statement at end of input
```

Typically, this error is the result of unmatched braces or some other grouping symbol (parenthesis, quotes, etc.).

### Assignment to expression with array type

```(text)
error: assignment to expression with array type
```

This typically happens when you assign a string literal to a character array.  If you want to fill a character array (even if using it as a string), you have to initialize it to what you want or use strncpy().

### Implicit declaration of function

```(text)
warning: implicit declaration of function 'my_function'
```

There is no forward declaration for my_function().  Either include the appropriate header file or add a forward declaration before you use my_function.

### Control reaches end of non-void function

```(text)
warning: control reaches end of non-void function
```

You forgot to add a return statement.

### Code compiles with warnings, but crashes

Fix the warnings – especially if they are pointer-related.

### non-ASCII characters are not allowed

```(text)
error: non-ASCII characters are not allowed outside of literals and identifiers
```

This likely means you are compiling code Word, a web page, or another program that used non-ASCII characters.  The most common issues are due to “double smart quotes” and ‘single smart quotes’.  Note how the smart quotes are not the same character – they are oriented in a different direction.  This is because the ASCII quote character (value 34) is not used as the quote character.

### Undefined reference to main

This can show up differently in different environments.

#### Cygwin

```(text)
/usr/lib/gcc/i686-pc-cygwin/7.3.0/../../../libcygwin.a(libcmain.o): In function `main':
/usr/src/debug/cygwin-2.10.0-1/winsup/cygwin/lib/libcmain.c:37: undefined reference to `WinMain@16'
collect2: error: ld returned 1 exit status
```

#### Linux

```(text)
/usr/lib/gcc/x86_64-linux-gnu/4.8/../../../x86_64-linux-gnu/crt1.o: In function `_start':
(.text+0x20): undefined reference to `main'
collect2: error: ld returned 1 exit status
```

#### MacOS

```(text)
Undefined symbols for architecture x86_64:
  "_main", referenced from:
     implicit entry/start for main executable
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1
```

This indicates that you are compiling a file(s) without a main() function.  If you are building a module, you can use the -c option to build an object file to avoid this error.  Or make sure you include all the files used by your project in the compile command.

### Multiple definions

```(text)
basiclist.o:basiclist.c:(.text+0x0): multiple definition of 'list_add'
polynomial.o:polynomial.c:(.text+0x0): first defined here
collect2: error: ld returned 1 exit status
make: *** [makefile:5: all] Error 1
```

Assuming you don’t actually have the function/variable defined in multiple places, this is likely due to having an include (.h) file that does not have appropriate guards.  *Any* header file should include the lines:

```(text)
#ifndef HEADERFILENAME_H
#define HEADERFILENAME_H
/* Stuff for header file */
#endif
```

If you have accidentally defined something in multiple places then the error would point you to the line numbers where the duplicate definitions are located.

### Multi-character character constant

```(text)
warning: multi-character character constant [-Wmultichar]
    8 |            scanf ('%u', &number);
```

The string in scanf should have double quotes :
scanf ("%u", &number);

### printf makes pointer from integer without a cast

```(text)
myprog.c: In function ‘main’:
myprog.c:35:27: warning: passing argument 1 of ‘printf’ makes pointer from integer without a cast [-Wint-conversion]
   35 |                   printf(x);
      |                          ~^~~
      |                           |
      |                           int
In file included from myprog.c:1:
/usr/include/stdio.h:200:13: note: expected ‘const char * restrict’ but argument is of type ‘int’
  200 | int printf (const char *__restrict, ...)
      |             ^
```

The first paramter of a `printf` call should be a control sequence.  Since x is an int, then the correct code will be;

```(c)
printf("%d", x);
```

## Output Issues

If you get random characters as part of your output, typically one of the following is to blame:

- You are using the wrong control sequence in your printf statement.  For example, if you want to print an int, printf will let you use %d, %x, %c, %s, or %f.  Usually you will want to print ints with either %d or %f (or sometimes %c), so if you accidentally use %s or %f then you will get unexpected output.  Always double check that you are using the correct control sequence!  
- If you are printing out a string using a character pointer, make sure the pointer is pointing to valid memory.  For example, if you return a character pointer from a function that was pointing to a local variable that memory may be reallocated by the time you print it.  Also, make sure that you actually point the pointer to memory!  
