# C++ Memory Management

## [destructor.cpp](https://github.com/wadehuber/codeexamples/blob/master/cpp/cpp2/destructor.cpp)

[Video](https://youtu.be/QJZsHWZ3xS4) (6:06): *Example of a destructor*

This video shows an example of what a destructor is and when it is called.  For the particular class in question we do not explicitly need a destructor - the intention is just to show what a destructor is, how to declare one, and when a destructor gets called.  The next video goes into more detail about why destructors are needed with more advanced examples.  

## [whydestructors.cpp](https://github.com/wadehuber/codeexamples/blob/master/cpp/cpp2/whydestructors.cpp)

[Video](https://youtu.be/M48fMs8LAkg) (20:44): *Example of destructor & copy constructor*

Examples of constructor, destructor, and copy constructor.  The output here is pretty verbose because the intention is to understand when the different functions get called.  In general, constructors, destructors, and copy constructors (and *especially overloaded operators*) should avoid output to stdout.

## [headers](https://github.com/wadehuber/codeexamples/tree/master/cpp/cpp2/headers)

[Video](https://youtu.be/JVFjEJidilE) (15:14): *Example of using C++ header files and review of Inheritance*

This example walks through using C++ header files.  It also reviews inheritance, polymorphism, & virtual methods and discusses the use of the override & explicit keywords.

The headers directory contains a Shape class hierarchy split across header (.hpp) and implementation (.cpp) files, plus a makefile:

- shape.hpp - the abstract base class
  - circle.cpp / circle.hpp
  - rectangle.cpp / rectangle.hpp
    - square.cpp / square.hpp (Square derives from Rectangle)
  - triangle.cpp / triangle.hpp
- headers.cpp - the main program that works with the shapes polymorphically

## [structvsclass.cpp](https://github.com/wadehuber/codeexamples/blob/master/cpp/cpp2/structvsclass.cpp)

[Video](https://youtu.be/PyGxAl4sfK0) (13:52): *Comparing Structs & Classes in C++*

Differences and similarities between Structs & Classes in C++.  Also an example of using a char pointer to view memory contents.

## [memory.cpp](https://github.com/wadehuber/codeexamples/blob/master/cpp/cpp2/memory.cpp)

[Video](https://youtu.be/rlAHJFy3zH4) (26:28): *More complete example of memory management and the rule of 3*  

Demonstrates using delete vs delete[], value & reference semantics, copy constructors, and overloading the = operator.  
