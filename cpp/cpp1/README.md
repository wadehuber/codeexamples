# Introduction to C++ & OOP

## cppio.cpp

[Video](https://youtu.be/DrTNMjeosZ8) (5:57): *C++ input & output - cout, cin, & getline*

This file has examples of using stream input & output in C++.

## overview.cpp

[Video](https://youtu.be/qJ_LcjbN8fI) (9:24): *Introduction to C++ syntax*

This file has examples of variable declarations, initilaizations, auto, constants, a vector, and pointers in C++.

## strings.cpp

[Video](https://youtu.be/95yj6NZmL_Y) (11:42): *C++ string examples*

C++ includes a string type.  Several examples of different string functions.

## boolean.cpp

[Video](https://youtu.be/61Ti3L05CuU) (10:00) *Example of using bool type and ternary operator*

## references.cpp

[Video](https://youtu.be/j1HiuaUt1MU) (11:12) *Examples of C++ references*

Demonstration of how to work with references, including a function that returns a reference.

## defaultargs.cpp

[Video](https://youtu.be/2VTzfl7Aidc) (4:32): *Default arguments*

This file contains an example of using default arguments in C++ functions.

## constmethod.cpp

[Video](https://youtu.be/_F5emVR-jd4) (8:02): *Example of const member methods*

## OOP Examples

The next three videos feature examples of virtual/non-virtual functions, inheritance, and polymorphism.  The are included in increasing order of complexity, but if you are new to OOP you may find the first animals.cpp to be easier to understand at first.  

### virtualfunctions.cpp

[Video](https://youtu.be/ZnV4gXitoz0) (17:24): *Virtual & pure virtual methods*

This file contains a simplified example of how non-virtual, virtual, & pure-virtual methods work.  You may want to review the animals.cpp videos first if you want to get a review of inheritance first or a more specific explaination of how each of the types of functions work.  

UPDATE: Line 29 has changed from the video.  The string was changed to "SUB: nonVirtual2" to reflect that this was part of the derrived class.

### animals.cpp

[Video 1](https://youtu.be/zvgwLT4FSQg) (7:34): *Inheritance with C++, pointers & references*

[Video 2](https://youtu.be/TB50U8UoA78) (13:07): *Polymorphism, virtual, non-virtual, & pure virtual methods*

This file includes examples of inheritance, polymorphism, and virtual and pure-virtual methods.  

### staff

[Video](https://youtu.be/ZwDR84yAB4E) (43:12): *Payroll example*  

Example of inheritance, polymorporphism, virtual vs non-virtual methods, C++ header (.hpp) files, and writing a makefile for a larger multi-file program.  We use a vector to store a list of pointers to StaffMembers.  We will cover vectors in a later module.  I left a lot of the compile errors and some design changes in the video so that you can see the thought process behind it.

This program contains the following class heirarchy:

- StaffMember (staffmember.cpp / staffmember.hpp)
  - Volunteer (volunteer.hpp - no cpp file needed)
  - Employee (employee.cpp / employee.hpp)
    - Hourly (hourly.cpp / hourly.hpp)
    - Salaried (salaried.cpp / salaried.hpp)

In the loop where the paystubs are printed in staff.cpp the StaffMember print method is called since print is not virtual.  This is as intended - the only thing that should be printed is the name/address/phone of the employee, not additional things such as SSN.  To print that information we would need to use a variable or pointer of the derrived class type.

**NOTE**: You may notice in the video I started to make pay non-virtual when I added the bonus method.  Since the bonus method takes a parameter and pay doesn't, I could have still called it pay since it would have overloaded, not overridden, then virtual pay method.  Also, it probably would have been better to use variables for the 4 StaffMembers to avoid memory allocation.  
