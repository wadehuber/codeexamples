# C

## Compiling C with gcc

We will be using [gcc](https://gcc.gnu.org/) for CSC240.  Always compile your code using the following command line options to ensure you are writing standard C code:

```bash
gcc --std=c11 -pedantic -Wall filename.c
```

then to run the code in Ubuntu, other Linux distros, WSL, or MacOS

```bash
./a.out
```

or under Cygwin

```bash
./a.exe
```

Not using gcc with these compile flags may hide errors that result in a grade of 0 on your project!
Also, you should use gcc version 4.7 or later.  Earlier versions may be missing some features you will need for this class.

### More gcc flags

The flags above are required, bug gcc has a lot of other flags you may want to use to help you find potential bugs in your code.

- [Recommended gcc flags](https://stackoverflow.com/questions/154630/recommended-gcc-warning-options-for-c?noredirect=1&lq=1) on Stack Overflow
- This [blog post](https://kristerw.blogspot.com/2017/09/useful-gcc-warning-options-not-enabled.html) mentions some other warning flags you may want to enable to help you avoid common mistakes (applies to gcc & g++).

## C Notes & Tutorials

- A quick video walking through the [C basics in 25 minutes](https://www.youtube.com/watch?v=3lQEunpmtRA)
- [Essential C](http://cslibrary.stanford.edu/101/) from The Stanford CS Education Library has an excellent summary of the C language.  It covers most of what we will discuss about C this semester.  There are also PDFs about [pointers](http://cslibrary.stanford.edu/102/), [linked lists](http://cslibrary.stanford.edu/103/), and [binary trees](http://cslibrary.stanford.edu/110/) in C.
- The [C FAQ](http://c-faq.com/) has a great discussion of [pointers vs. arrays](http://c-faq.com/aryptr/aryptrequiv.html).
- [Beej's Guide to C Programming](http://beej.us/guide/bgc/)
- If you are looking for a C book, here is StackOverflow's [Definitive C Book Guide & List](https://stackoverflow.com/questions/562303/the-definitive-c-book-guide-and-list)
- A guide to [building (compiling) programs with gcc](http://seenaburns.com/building-c-programs/)
- The [right-left rule](http://cseweb.ucsd.edu/~ricko/rt_lt.rule.html) for deciphering C declarations.
- [A C Reference Manual](https://www.bell-labs.com/usr/dmr/www/cman.pdf) from Bell Labs (by Dennis Ritchie)
- [C Operator Precedence](https://en.cppreference.com/w/c/language/operator_precedence)
- [The Descent to C](https://www.chiark.greenend.org.uk/~sgtatham/cdescent/) is a nice intro to C for Java programmers
- If you need to split up a string in to words (tokens) you can use ```strtok```.  [Here is a tutorial](https://onebyezero.blogspot.com/2018/12/string-tokenization-in-c.html)
- [Efficient String Operations in C](https://developers.redhat.com/blog/2019/08/12/efficient-string-copying-and-concatenation-in-c/) - specifically copying & concatenation
- VIDEO: [What Are Pointers](https://www.youtube.com/watch?v=iChalAKXffs) is an excellent introduction to pointers.  The video uses C++ but the first half of the video is applicable to C as well.
- A video on [Pointers](https://www.youtube.com/watch?v=5BpYD7TxvKU&list=PL6gx4Cwl9DGAKIXv8Yr6nhGJ9Vlcjyymq&index=42) that is part of a C programming tutorial.  There are several other videos on pointer topics in the playlist following this video.

## Advanced C Tutorials/Examples

The links below go far more in depth into C than we will in this class, but if you are interested in C you may find them interesting.

- [Inside the C Standard Library](https://begriffs.com/posts/2019-01-19-inside-c-standard-lib.html)
- I don’t have strong opinions about coding style, other than your code should be clear & consistently formatted.  But you may want to review the [Linux coding standards](https://www.kernel.org/doc/html/v4.10/process/coding-style.html)
- A list of [obscure C features](https://multun.net/obscure-c-features.html)(that you should probably avoid, but you may see out in the wild)
- [Back to Basics](https://www.joelonsoftware.com/2001/12/11/back-to-basics/) discusses how C strings and malloc work and why it is important to know it.
- [Signal handling](https://publications.gbdirect.co.uk//c_book/chapter9/signal_handling.html) in C

## Static Analysis

See the [C++ Information page](./cpp_information.md) for information about `cppcheck` which is the static analyzer I'll be using on your C & C++ assignments.

- [Splint](http://splint.org/) is a static analyzer for security vulnerabilities and general coding issues

## Memory Usage & Data Alignment

- [Recursion, Runtime Environment, & the Call Stack](http://www.cs.tau.ac.il/~efif/courses/Software1_Summer_04/lectures/lecture7_2.php) shows how function calls work in C
- Some lecture notes about [how C uses memory](http://web.eecs.utk.edu/~huangj/cs360/360/notes/Memory/lecture.html)(Unix oriented, but the first section is applicable anywhere)
- We will talk in class about how C structs sometime waste space due to word alignment.  [The Lost Art of Structure Packing](http://www.catb.org/esr/structure-packing/?src=yc) is a good article about how rearranging your structs can wind up saving a lot of space in your program.  There are a few things we probably won't cover about in the article, but you should know enough C by the end to understand most of it.
- A [bug report](http://pzemtsov.github.io/2016/11/06/bug-story-alignment-on-x86.html) related to how data is aligned in memory

## Macros and Multi-file Programs

- There is some good files & the pre-processor in the [GNU libc manual](http://www.gnu.org/software/libc/manual/html_node/Header-Files.html) and the [gcc manual](https://gcc.gnu.org/onlinedocs/cpp/Header-Files.html#Header-Files)
- To prevent a file from being included multiple times in the same program, we add

```C
#ifndef __PERSONNEL_H__
#define __PERSONNEL_H
```

to the beginning of the file and

```C
#endif
```

to the end of the file.

## Threads

- [Introduction to C11 Threads](https://stdin.top/posts/c11-threads/)

## Why Learn C

- [Learn C programming and the rest will come](https://zeroequalsfalse.com/posts/learn-c-programming/)

## The History & Development of C

- A great video of the roots of C, going back to the first electronic computers, is Olve Maundal’s talk [History & Spirit of C](https://www.youtube.com/watch?v=xGVRF-Y--hI)
- An article on how the [C language has evolved over the years](http://www.electronicdesign.com/dev-tools/what-s-difference-between-c-now-and-then)

## C Standards

- An overview of [5 C standards](https://opensourceforu.com/2017/04/different-c-standards-story-c/)
- A series of blog posts on the [differences between C90 & C99](http://www.simplyembedded.org/archives/battle-of-the-standards-round1/)
- [C11 The new standard](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3631.pdf)

## ANSI C vs C11

For Loops: In ANSI C (C89) you cannot declare the loop variable in the for loop - you have to declare it before the for statement like this:

```C
int ii;
for (ii=0;ii<10;ii++) {
  /* loop stuff */
}
```

 NOT like this:

```C
for (int ii=0;ii<10;ii++) {
  /* loop stuff */
}
```

## Problems with C's Design

- [The Most Expensive One-Byte Mistake](https://queue.acm.org/detail.cfm?id=2010365) about is null-terminated strings.
- [Tony Hoare](https://en.wikipedia.org/wiki/Tony_Hoare) calls null references/pointers a [Billion Dollar Mistake](https://www.infoq.com/presentations/Null-References-The-Billion-Dollar-Mistake-Tony-Hoare/).
- [Conflating pointers with arrays](https://www.drdobbs.com/architecture-and-design/cs-biggest-mistake/228701625) is another thing that causes confusion.
- [C's array notation is a lie](https://blog.feabhas.com/2016/12/a-convenient-untruth/)
- [So you think you know C?](https://hackernoon.com/so-you-think-you-know-c-8d4e2cd6f6a6#.w115kcmbi) is a short quiz that points out some places where undefined behavior pops up in C.
- [Defining the Undefinededness of C](http://fsl.cs.illinois.edu/FSL/papers/2015/hathhorn-ellison-rosu-2015-pldi/hathhorn-ellison-rosu-2015-pldi-public.pdf) has some interesting discussion about undefined behavior (focused more on C11).
- [A list of breaking changes in C11](https://stackoverflow.com/questions/6399615/what-breaking-changes-are-introduced-in-c11) has information about features in ANSI C that no longer work in C11.
- [Why C & C++ Are Awful Programming Languages](https://www.radford.edu/ibarland/Manifestoes/whyC++isBad.shtml) is written from a teaching perspective, but has some interesting points about both C & C++.
- The paper [The Case for Writing Network Drivers in High-Level Programming Languages](https://www.net.in.tum.de/fileadmin/bibtex/publications/papers/the-case-for-writing-network-drivers-in-high-level-languages.pdf) argues that network drivers should be written in higher level languages
- [C11 Defects - C threads are not realizable with POSIX threads](https://gustedt.wordpress.com/2012/10/14/c11-defects-c-threads-are-not-realizable-with-posix-threads/)

## Object-Oriented Programming with C

[Axel-Tobias Schreiner](https://www.cs.rit.edu/~ats/) has written a book on *Object Oriented Programming in C* (available for download under the "books" link).  The book touches on some advanced topics we will likely not have time for this semester, but it is interesting if only for the fact that there is no "++" at the end of the book title.  While we will discuss many programming language paradigms CSC240, it is important to keep in mind that you can take the techniques from any paradigm and apply them to your language of choice.

## Articles about C

- Rob Pike's [Notes on Programming in C](http://www.lysator.liu.se/c/pikestyle.html).  [His 5 Rules for Programming](http://users.ece.utexas.edu/~adnan/pike.html) are also worth reading.
- [C Puzzles](http://www.gowrikumar.com/c/index.php) has some interesting (very advanced) examples of C programs with surprising output.
- [Is C still relevant in the 21st Century?](https://insights.dice.com/2014/12/08/c-still-relevant-21st-century/) has some good points, though it glosses over C's use in embedded systems and microcontrollers which is probably where the bulk of future C programming will happen.
- [f() vs f(void) function declarations in C & C++](https://nickdesaulniers.github.io/blog/2019/05/12/f-vs-f-void-in-c-vs-c-plus-plus/)
- [The Top 10 Ways to Get Screwed by the C Programming Language](http://tsemba.org/c/topten.html) (though most of these are the result of poor style or practice on the part of the programmer!)
- [What Every Programmer Should Know About Undefined Behavior in C](http://blog.llvm.org/2011/05/what-every-c-programmer-should-know.html) (and [part 2](http://blog.llvm.org/2011/05/what-every-c-programmer-should-know_14.html) & [part 3](http://blog.llvm.org/2011/05/what-every-c-programmer-should-know_21.html)).  
- [A Guide to Undefined Behavior in C](https://blog.regehr.org/archives/213)
- [An interview with Ken Thompson](https://www.drdobbs.com/open-source/interview-with-ken-thompson/229502480) who was one of the developers of UNIX and who was involved in C in the early days.
- [D as a better C](https://dlang.org/blog/2017/08/23/d-as-a-better-c/) - The D language was developed to address some of the shortcomings of C.  This article compares C with a subset of D.  Some interesting things (from a programming language theory standpoint) are addressed in this article.
- [C the Immortal Language](https://embeddedgurus.com/barr-code/2018/02/c-the-immortal-programming-language/) - C is still the dominant language in embedded systems
- Some [principles for programming in C](https://drewdevault.com/2017/03/15/How-I-learned-to-stop-worrying-and-love-C.html).  A lot of these apply to any language.
- An [implementation of the movie Inception in C](https://github.com/karthick18/inception)
- A [Proposal for a Friendly Dialect of C](https://blog.regehr.org/archives/1180) suggests some features that would make C program safer.
- Don’t write your code like this, but the [International Obfuscated C Contest](http://ioccc.org/) has some interesting examples of valid C code.
- [How C array sizes became part of the binary interface of a library](https://developers.redhat.com/blog/2019/05/06/how-c-array-sizes-become-part-of-the-binary-interface-of-a-library/)

## Real-world C examples

- The Python compiler is written in C.  This [online class on the CPython compiler/runtime](http://pgbovine.net/cpython-internals.htm) has some excellent examples of using C.
- The [DOOM source code](https://github.com/id-Software/DOOM) is available on GitHub.
- [SQLite](https://www.sqlite.org/index.html) is a very small database engine that is included as a library in a lot of languages, including Python and Java.  [This code walk through](http://cppdepend.com/blog/?p=214) touches points out some good programming practices that show up in the source code.
- A guide to [low-level programming in C on the Raspberry Pi](http://www.pieter-jan.com/node/15).
- [String-matching using C & Assembly](https://trent.me/is-prefix-of-string-in-table/)
- VIDEO [Programming A Chess Engine in C](https://www.youtube.com/watch?v=bGAfaepBco4) (the first video in a series)

## Bugs & Exploits

- A few years ago Cloudflare reported a bug (found by Google) that exposed memory locations which contained data that had gone out of scope.  The C related description starts in the “Root cause of the bug” section.
- Leaving braces off a single line loop is usually not a good idea.  Doing that let to the [Apple SSL/TLS bug](https://www.imperialviolet.org/2014/02/22/applebug.html) from a few years ago
- [Manual Control Flow Guards](https://nullprogram.com/blog/2017/01/21/) are a Windows feature that help avoid buffer overflow exploit.

## C Coding Tips

- Some good [C Programming Tips](http://www.pgbovine.net/c-programming-tips.htm) from Philip Guo who taught the Python source code class listed above.
- [How to shoot yourself in the foot with C](https://www.viva64.com/en/b/0644/)
