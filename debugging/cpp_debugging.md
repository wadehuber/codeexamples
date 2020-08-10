# C++ Debugging Tips

You should also review the C debuggging tips as some errors C & C++ have in common.

Note: if you get a lot of compile errors/warnings, resolve them from first to last.  C++ can generate a lot of errors and warnings, many of which are not particuarly helpful.  

## Compile Errors

## undefined references

```(text)
undefined reference to `std::ostream::operator<<(std::ostream)'
undefined reference to `std::cout'
```

This can happen if you use gcc instead of g++ to compile your C++ program

## string does not name a type

```(text)
myfile.hpp:32:5: error: 'string' does not name a type; did you mean 'stdin'?
    string mystr;
```

This indicates that the compiler doesn’t know what namespace “string” is in.  Use `std::string` or add `using namespace std` to the top of the file.

## default argument given for parameter

```(text)
error: default argument given for parameter
```

This happens when you have default parameters on both the declaration & definition.  Only one or the other can have defaults.

## Undefined symblols for architecture x86_64

```(text)
Undefined symbols for architecture x86_64:
  "MyClass::myMethod()", referenced from:
      _main in myprog-32196b.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

Notice from the error that it doesn’t know what `myMethod()` is.  This means it is declared or used without being defined.  Usually, this is a result of one of the following:

- The cpp file `with myMethod()`’s definition (likely `myclass.cpp`)  is not included in the compile line.  
`gcc --std=c++17 myprog.cpp myclass.cpp`
- The method `myMethod` is not properly defined anywhere.  This is usually the result of defining the method without the scope resolution operator to indicate which class it belongs to.

## class has no member

```(text)
error: ‘class myClass has no member named 'someThing'
```

myClass does not have a `someThing` defined.  Either you forgot to add `someThing`, the object isn’t of the correct type, or you have a typo in the name of the variable.

## no operator found which taxes a right-hand operand of type

```(text)
error C2679: binary '<<': no operator found which takes a right-hand operand of type 'Movie'
```

You can’t print a user-defined class using cout `<<` unless you override the `<<` operator [`operator<<`].  You can also print each individual field using cout.

## expected ; before string constant

```(text)
program.cpp: In member function 'void MyClass::print()':
program.cpp:87:19: error: expected ';' before string constant
              cout "R = " << r << ": ";
```

This is because there is no << before the cout.
