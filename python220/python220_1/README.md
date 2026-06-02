# Python 1 - Introduction to Python for Programmers

This module covers fundamental Python concepts, adapted from *Python Crash Course* by Eric Matthes. Examples progress from basic variables and data types through control structures and data collections.

## Core Topics

### Variables

**variables.py**

Covers variable assignment, dynamic typing, and multiple assignment. Python uses no type declarations—types are determined at runtime. A variable can hold different types at different times.

### Data Types

**datatypes.py**

Python data types include integers (arbitrary precision), floats (IEEE 754 double precision), complex numbers (using `j` for the imaginary unit), and booleans.

Key concepts:
- Integers don't overflow like C/Java fixed-size integers
- Floats have the same rounding behavior as other binary floating-point implementations
- Complex numbers support arithmetic: `(3+4j) * (2-3j)`
- Truthiness: values like `0`, `[]`, `""`, and `None` evaluate to `False` in boolean contexts
- Type conversion: `int()`, `float()`, `str()`, `bool()`

### Conditionals

**control.py**

Demonstrates if/elif/else statements, comparison operators, and loop control. Includes:
- Conditional expressions (ternary operator)
- Logical operators: `and`, `or`, `not`
- Input handling with `input()`
- Format strings with `.format()`

### Loops

**control.py**

Two types of loops:
- **For loops**: iterate over ranges or sequences
- **While loops**: repeat while a condition is true
- **Loop control**: `break` to exit early, `continue` to skip to the next iteration

### Lists (Arrays)

**arrays.py**

Lists are ordered, mutable sequences. Python lists:
- Are zero-indexed (like C/Java arrays)
- Can contain mixed data types
- Support iteration and list comprehensions
- Have built-in methods: `append()`, `extend()`, `pop()`, `sort()`, etc.

Covers:
- Creating lists with `[]` or appending items
- Iterating with `for` loops
- Using `len()` to get size
- Summing values with loops

### Strings

**strings.py**

Strings are immutable sequences of characters. Examples include:
- Creating strings with quotes
- String concatenation with `+`
- Joining lists into strings with `.join()`
- String methods: `.upper()`, `.lower()`, `.split()`, etc.
- Iterating character-by-character
- ASCII values with `ord()`
- String length with `len()`

### Functions

**functions.py**

Functions are reusable blocks of code. Examples demonstrate:
- Functions with no return value
- Functions that return values
- Parameters and how they're passed (by reference for objects)
- Working with lists as parameters
- The `enumerate()` function for paired index/value access
- The `if __name__ == "__main__":` pattern

### Classes

**class.py** and **animals.py**

Introduction to object-oriented programming:
- Basic class definition with `__init__()` constructor
- Instance methods and attributes
- Inheritance with `super().__init__()`
- Method overriding
- Polymorphism

**animals.py** demonstrates a complete hierarchy: Animal → Dog, Animal → Cat

### Exception Handling

**exceptions.py**

Covers how to handle errors gracefully:
- `try`/`except` blocks for catching exceptions
- Catching specific exception types (e.g., `ZeroDivisionError`)
- Raising exceptions with custom messages
- Exception chaining with `from`

### File I/O

**fileio.py**

Working with files and command-line arguments:
- Reading files line-by-line with `open()` and iteration
- Generator functions with `yield`
- Using the `argparse` module for command-line arguments
- The `pathlib.Path` type for file paths
- List comprehensions for data transformation

## Quick Reference

| Topic | File | Key Concepts |
|-------|------|--------------|
| Variables | variables.py | Assignment, dynamic typing, multiple assignment |
| Data Types | datatypes.py | Integers, floats, complex, booleans, type conversion |
| Conditionals | control.py | if/elif/else, comparison, logical operators |
| Loops | control.py | for, while, break, continue, range() |
| Lists | arrays.py | Creation, indexing, iteration, methods |
| Strings | strings.py | Concatenation, methods, iteration, formatting |
| Functions | functions.py | Definition, parameters, return values |
| Classes | class.py, animals.py | Constructors, inheritance, methods |
| Exceptions | exceptions.py | try/except, raising exceptions |
| File I/O | fileio.py | Reading files, generators, argparse |

## Running the Examples

Each file can be run directly:

```bash
python variables.py
python datatypes.py
python control.py
python arrays.py
python strings.py
python functions.py
python class.py
python animals.py
python exceptions.py
python fileio.py <filename> [--fahrenheit]
```

The `fileio.py` example requires a text file with numbers (one per line).
