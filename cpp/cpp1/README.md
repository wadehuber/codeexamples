# Introduction to C++ & OOP

## cppio.cpp

[Video](https://youtu.be/DrTNMjeosZ8)
*C++ input & output - cout, cin, & getline*

This file has examples of using stream input & output in C++.

## overview.cpp

[Video](https://youtu.be/qJ_LcjbN8fI)
*Introduction to C++ syntax*

This file has examples of variable declarations, initilaizations, auto, constants, a vector, and pointers in C++.

## strings.cpp

[Video](https://youtu.be/95yj6NZmL_Y)
*C++ string examples*

C++ includes a string type.  Several examples of different string functions.

## animals.cpp

[Video 1](https://youtu.be/zvgwLT4FSQg) *Inheritance with C++, pointers & references*

[Video 2](https://youtu.be/TB50U8UoA78) *Polymorphism, virtual, non-virtual, & pure virtual methods*

This file includes examples of inheritance, polymorphism, and virtual and pure-virtual methods.

## virtualfunctions.cpp

[Video](https://youtu.be/ZnV4gXitoz0)
*Virtual & pure virtual methods*

This file contains a simplified example of how non-virtual, virtual, & pure-virtual methods work.

## defaultargs.cpp

[Video](https://youtu.be/2VTzfl7Aidc)
*Default arguments*

This file contains an example of using default arguments in C++ functions.

## staff

[Video](https://youtu.be/ZwDR84yAB4E)
*Payroll example*  This is a long video, so timestamps are included.

Example of inheritance, polymorporphism, virtual vs non-virtual methods, C++ header (.hpp) files, and writing a makefile for a larger multi-file program.  We use a vector to store a list of pointers to StaffMembers.  We will cover vectors in a later module.  I left a lot of the compile errors and some design changes in the video so that you can see the thought process behind it.

This program contains the following class heirarchy:

- StaffMember (staffmember.cpp / staffmember.hpp)
  - Volunteer (volunteer.hpp - no cpp file needed)
  - Employee (employee.cpp / employee.hpp)
    - Hourly (hourly.cpp / hourly.hpp)
    - Salaried (salaried.cpp / salaried.hpp)

**NOTE**: You may notice in the video I started to make pay non-virtual when I added the bonus method.  Since the bonus method takes a parameter and pay doesn't, I could have still called it pay since it would have overloaded, not overridden, then virtual pay method.  Also, it probably would have been better to use variables for the 4 StaffMembers to avoid memory allocation.  
