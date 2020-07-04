# C++ Language Information

Example [group project from a previous CSC220 class](https://github.com/CGCC-CS/nmbr220)

## C++ Compiler Flags (g++)

You should compile your programs with the following command to ensure you are using the correct C++ standard.

```bash
g++ --std=c++17 -pedantic -Wall filename.cpp
```

or on the older class VMs

```bash
g++ --std=c++11 -pedantic -Wall filename.cpp
```

Note that the c++11 standard will cover most of what we cover this semester, so that will be acceptable in most cases in place of c++17.

## C++ Tutorial

- Google has a nice [C++ Tutorial](https://developers.google.com/edu/c++/)
- This 10 hour [C++ Programming All-in-One Tutorial](https://www.youtube.com/watch?v=_bYFu9mBnr4) goes over most of the topics we will cover this semester.  

## C++ References

In general, [cppreference.com](http://cppreference.com) is a reliable C++ reference.

## C++ Style Guides and Coding Recommendations

- [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md) (from Bjarne Stroustrup & Herb Sutter)
- Recommendations for [C++ programming from Intel](https://software.intel.com/content/www/us/en/develop/articles/the-ultimate-question-of-programming-refactoring-and-everything.html)
- [The Evil Within the Comparison Functions](https://www.viva64.com/en/b/0391/) goes over some common mistakes when doing comparisons in C++.  This is an ad for a company that sells a tool to find the mistakes, but many of the ones they list are fairly common.  They also have a good list of pitfalls you can run into when writing comparisons in your code.  
- [A guide to Using C++ effectively on small systems](https://www.embedded.com/objects-no-thanks-using-c-effectively-on-small-systems/)

## C++ Features & Topics

### Vectors

- [Vector information](http://en.cppreference.com/w/cpp/container/vector)

### Strings

- Some good information about different [implementations of std:: string](http://shaharmike.com/cpp/std-string/)

### Operator Overloading

- A [list of operators you can overload](http://en.cppreference.com/w/cpp/language/operators)

### Lvalues & RValues

- [Understanding lvalues & rvalues in C & C++](https://eli.thegreenplace.net/2011/12/15/understanding-lvalues-and-rvalues-in-c-and-c/)
- [A Brief Introduction to Rvalue References](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2006/n2027.html#Move_Semantics)

### const

- [The C++ const Declaration: Why & How](http://duramecho.com/ComputerInformation/WhyHowCppConst.html)
- [Const Correctness](https://isocpp.org/wiki/faq/const-correctness) from the ISO C++ website
- [Const/volatile/mutable](http://en.cppreference.com/w/cpp/language/cv)

### Other Topics

- [getline](http://en.cppreference.com/w/cpp/string/basic_string/getline)
- [Overriding non-virtual methods](https://stackoverflow.com/questions/11067975/overriding-non-virtual-methods)

### Rule of Three (or 5 or Zero)

In C++ there is the idea of the "Rule of Three" - for classes that use heap memory you should implement a destructor, copy constructor, or copy assignment operator.  If you want to continue in C++ it is essential knowledge.  

- Video: [Rule of Three in C++: Overloaded Assignment, Copy Constructor, Destructor](https://www.youtube.com/watch?v=F-7Rpt2D-zo)
- [C++ Made Easier: The Rule of Three](https://www.drdobbs.com/c-made-easier-the-rule-of-three/184401400)
- [The Rule of three/five/zero](https://en.cppreference.com/w/cpp/language/rule_of_three) from [cppreference.com](https://en.cppreference.com/w/)
- [C++ Core Guidelines: The Rule of Zero, Five, or Six](https://www.modernescpp.com/index.php/c-core-guidelines-constructors-assignments-and-desctructors)

### Move Semantics

- [C++ moves for people who don't knjow or care what rvalues are](https://medium.com/@winwardo/c-moves-for-people-who-dont-know-or-care-what-rvalues-are-%EF%B8%8F-56ee122dda7)
- [Copy vs Move semantics](https://www.modernescpp.com/index.php/copy-versus-move-semantic-a-few-numbers)
- [What is a move constructor in C++?](https://www.educative.io/edpresso/what-is-a-move-constructor-in-cpp)
- [Move Constructors and move assignment](https://www.learncpp.com/cpp-tutorial/15-3-move-constructors-and-move-assignment/) from learncpp.com
- Microsoft's introduction to [Move Constructors and Move Assignment Operators (C++)](https://docs.microsoft.com/en-us/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=vs-2019)

## Copy constructor vs Assignment operator (=operator)

In C++, you need to be aware of what underlying operation is occurring when you set a variable.
In the following case, m3 is set using =operator:

```C++
Matrix m3;
m3 = m1 + m2;
```

In the next case below, m3 is initialized using the copy constructor

```C++
Matrix m3 = m1 + m2;
```

You don't necessarily need the overloaded assignment operator, but adding ones let you do things like:

```C++
Matrix matrix1(3,4);
Matrix matrix2(3,4);
Matrix matrix3(3,4);
matrix3 = matrix1 + matrix2
```

To avoid using the copy assignment operator:

```C++
Matrix matrix1(3,4);
Matrix matrix2(3,4);
Matrix matrix3 = matrix1 + matrix2
```

## Static Analysis

It is always a good idea to run static analyzer on your code.  A static analyzer is a program that analyzes your source code (without running it) and looks for potential problems.  In the case of C++, it can catch many array overflows and memory management issues.  They don't catch all issues (for example if a loop variable used as an array index it can still have an invalid value), so don't rely on them exclusively.

[Why you should really care about C/C++ static analysis](https://medium.com/hackernoon/why-you-should-really-care-about-c-c-static-analysis-db13f4463b2d)

One C++ static analyzer is cppcheck.  Once your code compiles, you can run it on your code by typing:

```bash
cppcheck filename.cpp
```

## Advanced C++

- VIDEO: [The Care and Feeding of C++'s Dragons](https://www.youtube.com/watch?v=JSjoCisIHcM) is a talk about some of tools Google uses to help with simplicity in C++.  It isn't really a tutorial, but it touches on a lot of issues that come up in industry.  
A discussion of some [obscure C++ features](http://madebyevan.com/obscure-cpp-features/)
- [C++ Annotations](http://www.icce.rug.nl/documents/cplusplus) is an online book with a focus on differences between C & C++.   It goes well beyond what we will cover this semester, but it has a lot of good information.
- VIDEO: [C9 Lectures: Stephan T. Lavavej - Standard Templiate Library](https://channel9.msdn.com/Series/C9-Lectures-Stephan-T-Lavavej-Standard-Template-Library-STL-/C9-Lectures-Introduction-to-STL-with-Stephan-T-Lavavej) has several videos covering the STL
- John Carmack on [functional programming in C++](https://www.gamasutra.com/view/news/169296/Indepth_Functional_programming_in_C.php)
- A list of recommended [advanced C++ books](https://www.fluentcpp.com/2017/07/28/what-books-to-read-to-get-better-at-c/)
- CPPCon notes (most of the talks are available on YouTube):
  - [2014](https://github.com/CppCon/CppCon2014)
  - [2015](https://github.com/CppCon/CppCon2015)
  - [2016](https://github.com/CppCon/CppCon2016)
  - [2017](https://github.com/CppCon/CppCon2017)
  - [2018](https://github.com/CppCon/CppCon2018)
  - [2019](https://github.com/CppCon/CppCon2019)

## C++ Standards

### C++ 11

- Bjarne Stroustrup's [C++ 11 FAQ](http://www.stroustrup.com/C++11FAQ.html)
- The Biggest [Changes in C++ 11](https://blog.smartbear.com/development/the-biggest-changes-in-c11-and-why-you-should-care/)
- C++11 [Move Constructor & Move Assignment Operator Tutorial](https://blog.smartbear.com/c-plus-plus/c11-tutorial-introducing-the-move-constructor-and-the-move-assignment-operator/)

### C++ 17

- Examples of [changes in C++ 17](https://github.com/tvaneerd/cpp17_in_TTs/blob/master/ALL_IN_ONE.md)
- An [online book about C++ 17](https://bfilipek.us8.list-manage.com/subscribe?u=e93417593cbf4da3dba03d672&id=a2dd686b21).  Or if you want more detail - [leanpub.com/cpp17](https://leanpub.com/cpp17)
- C++ 17 lets you [specify memory alignment](https://www.bfilipek.com/2019/08/newnew-align.html)

### C++ 20

- [Notes](https://www.reddit.com/r/cpp/comments/au0c4x/201902_kona_iso_c_committee_trip_report_c20/) from the final C++ 20 standards meeting

### Other

- This [blog post](https://www.bfilipek.com/2018/12/c-at-end-of-2018.html) has a summary of what features of which standards have been implemented in different C++ compilers.  
- C++ standards [support in gcc](https://gcc.gnu.org/projects/cxx-status.html#cxx1z)
- An interview with Bjarne Stroustrup about [his opinions of future plans for C++](https://www.theregister.co.uk/2018/06/18/bjarne_stroustrup_c_plus_plus/)

## Modern C++

- Using Modern C++ ideas [with older C++ standards](https://www.fluentcpp.com/2018/08/31/modern-cpp-fake-it-until-you-have-it/)
- This author describes his [attempt to learn C++ in 2018](https://vishnubharathi.codes/blog/learning-cpp-2018/)
- [What does Modern C++ mean?](https://www.meetingcpp.com/blog/items/what-does-modern-c-really-mean.html)
- VIDEO: [Easing into Modern C++ (7 Features of C++ You Can Adopt Today)](https://www.youtube.com/watch?v=8wnj6M-jj9c)
- VIDEO: [How to Adopt Modern C++17 into Your C++ Code](https://www.youtube.com/watch?v=UsrHQAzSXkA) from Build 2018
- [A Guide to Modern C++ for C Programmers](https://berthub.eu/articles/posts/c++-1/) (there are multiple parts, the link is to the first one)

### CPPcon 2019 Back to Basics Talks

Cppcon 2019 had several good “Back to Basics” talks about a wide variety of C++ topics.

- [exception handling in C++](https://www.youtube.com/watch?v=W6jZKibuJpU) and making your code exception safe
- [RAII & the Rule of Zero](https://www.youtube.com/watch?v=7Qgd9B1KuMQ) This talk goes over destructors and what you need to be aware of when implementing C++ objects that allocate resources (eg. memory)
- [Object Oriented Programming](https://www.youtube.com/watch?v=32tDTD9UJCE)
- [Smart Pointers](https://www.youtube.com/watch?v=xGDLkt-jBJ4)
- Move Semantics (2 parts):
  - [Part 1](https://www.youtube.com/watch?v=St0MNEU5b0o)
  - [Part 2](https://www.youtube.com/watch?v=pIzaZbKUw2s)
- [Const as a promise](https://www.youtube.com/watch?v=NZtr93iL3R0)
- [Understanding Value Categories](https://www.youtube.com/watch?v=XS2JddPq7GQ)
- [Lambdas](https://www.youtube.com/watch?v=3jCOwajNch0)

## Interesting C++ Articles/Blog Posts/Papers

- If you are interested in networking, here is a [Guide to Implementing Communication Protocols in C++](https://arobenko.gitbooks.io/comms-protocols-cpp/content/)

## C++ in the Real World

- [A GameBoy emulator](https://github.com/Dooskington/GameLad)
