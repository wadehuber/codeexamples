# Python 2 - Programming for Engineers

This module covers Python tools and techniques for engineering applications. Topics progress from advanced data structures and functions through practical file processing, text parsing, and command-line scripting.

## Data Structures & Algorithms

### Lists, Tuples & Dictionaries

**liststuplesdictionaries.py**

Comprehensive coverage of Python's core data structures:

- Lists: creation, operations, slicing, iteration
- Tuples: immutable sequences, unpacking, use as dictionary keys
- Dictionaries: key-value pairs, methods, nested structures
- Practical examples: shopping carts, student grades, word frequency counting

### Recursion

**recursion.py**

Demonstrates recursive function design:

- Naive and optimized (tail-recursive) implementations
- Fibonacci sequence calculation
- Array searching with recursion
- Understanding base cases and recursive calls

### Advanced Functions

**advancedfunctions.py**

Function parameter techniques:

- Positional-only parameters (/)
- Keyword arguments with defaults
- Variable-length argument lists (*args)
- Keyword-only parameters (*)
- Practical examples with statistical functions

## Comprehensions

**comprehensionsintro.py**

[VIDEO](https://youtu.be/p-U-iPKaVFo) (8:56): Concise syntax for creating collections:

- List comprehensions for transforming sequences
- Set comprehensions for unique elements
- Dictionary comprehensions for key-value pairs
- Filtering with conditional expressions
- Nested comprehensions for complex operations

## Text Processing

### Advanced Strings

**strings_advanced.py**

Essential string methods for engineering scripts:

- String methods: strip(), upper(), lower(), replace()
- Checking content: startswith(), endswith(), isdigit()
- Splitting and joining: split(), join()
- String formatting: f-strings, .format(), alignment
- Extracting data from structured text
- Finding and locating substrings

### Regular Expressions

**regex.py**

Pattern matching and text extraction:

- Basic pattern matching with re.search()
- Extracting numbers and codes from text
- Email validation patterns
- Finding all matches with re.findall()
- Replacing with patterns using re.sub()
- Splitting text on patterns
- Pattern syntax: \d, \w, [a-z], +, *, ?, {n,m}

## Data Files

### CSV Files

**csv_files.py**

Reading and writing comma-separated data:

- Reading CSV with csv.reader()
- Dictionary access with csv.DictReader()
- Filtering and extracting specific columns
- Writing CSV files with csv.DictWriter()
- Handling different delimiters (semicolon, tab)
- Aggregating and summarizing CSV data

### File I/O

**fileio_engineering.py**

File operations for engineering workflows:

- Writing files with open() and write()
- Reading entire files and line-by-line processing
- Appending to existing files
- Filtering file contents
- Processing structured data from files
- Working with file metadata and directories

## Error Handling & Scripting

### Error Handling

**error_handling.py**

Writing robust scripts with exception handling:

- try/except for handling specific exceptions
- ValueError, FileNotFoundError, TypeError
- Multiple exception types in one script
- Else and finally clauses
- Raising custom exceptions
- Exception chaining with "from"
- Handling bad data in loops gracefully

### Command-Line Arguments

**commandline_engineering.py**

Making scripts flexible with arguments:

- Accessing command-line arguments (sys.argv)
- Processing required and optional arguments
- Common patterns for argument handling
- Usage messages and error checking
- Examples: file analyzer, unit converter
- Introduction to argparse for complex scripts

## Quick Reference

| Topic | File | Key Concepts |
|-------|------|--------------|
| Data Structures | liststuplesdictionaries.py | Lists, tuples, dicts, operations, unpacking |
| Recursion | recursion.py | Base cases, recursive calls, optimization |
| Advanced Functions | advancedfunctions.py | *args, keyword args, default values |
| Comprehensions | comprehensionsintro.py | List, set, dict comprehensions, filtering |
| String Methods | strings_advanced.py | strip, split, replace, find, format |
| Regular Expressions | regex.py | Pattern matching, extraction, validation |
| CSV Files | csv_files.py | Reading, writing, filtering, aggregation |
| File I/O | fileio_engineering.py | Reading, writing, appending, processing |
| Error Handling | error_handling.py | try/except, exception types, robustness |
| Command-Line Args | commandline_engineering.py | sys.argv, argument processing, usage |

## Running the Examples

Each file can be run directly:

```bash
python liststuplesdictionaries.py
python recursion.py
python advancedfunctions.py
python comprehensionsintro.py
python strings_advanced.py
python regex.py
python csv_files.py
python fileio_engineering.py
python error_handling.py
python commandline_engineering.py
```

Some examples create temporary files during execution and clean them up automatically.

## Common Workflows

### Processing a data file

1. Read the file (fileio_engineering.py)
2. Parse each line (strings_advanced.py)
3. Handle errors gracefully (error_handling.py)
4. Aggregate results (liststuplesdictionaries.py)

### Extracting structured data

1. Use regex patterns (regex.py)
2. Process with comprehensions (comprehensionsintro.py)
3. Store in dictionaries (liststuplesdictionaries.py)
4. Write results to CSV (csv_files.py)

### Building command-line tools

1. Accept arguments (commandline_engineering.py)
2. Validate input (error_handling.py)
3. Process files (fileio_engineering.py)
4. Handle exceptions gracefully (error_handling.py)
