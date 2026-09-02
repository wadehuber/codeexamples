# Debugging Examples and Tips

This directory contains debugging notes, common error explanations, and small examples for several programming languages. It is intended as a quick reference when a program does not compile, produces an error message, or behaves differently than expected.

## Contents

| Resource | Description |
| --- | --- |
| [General Debugging Tips](general_tips.md) | General strategies for finding and fixing programming errors. |
| [C Debugging Tips](c_debugging.md) | Common C compiler/runtime problems and debugging guidance. |
| [C++ Debugging Tips](cpp_debugging.md) | Common C++ compiler and linker errors, with explanations and fixes. |
| [Java Debugging Tips](java_debugging.md) | Common Java and Eclipse errors and suggestions for resolving them. |
| [Prolog Debugging Hints](prolog_debugging.md) | Common Prolog errors such as instantiation, predicate, and syntax problems. |
| [Scheme Debugging Tips](scheme_debugging.md) | Common Scheme errors such as contract violations, arity mismatches, and syntax problems. |
| [C Error Examples](c_errors/) | Small C programs/examples that demonstrate common errors. |
| [C++ Error Examples](cpp_errors/) | Small C++ programs/examples that demonstrate common errors. |
| [Images](images/) | Images used by the debugging documentation. |

## How to Use These Notes

When you encounter a problem:

1. **Read the complete error message.** The first error is often the most useful; later errors may simply be consequences of the first one.
2. **Start with the language-specific guide.** Search the appropriate Markdown file for a distinctive part of the error message.
3. **Compare with the examples.** For C and C++, check the corresponding error-example directory for small programs demonstrating common mistakes.
4. **Fix one issue at a time.** Recompile or rerun the program after each meaningful change.
5. **Reduce the problem.** If the cause is unclear, simplify the program until the smallest version that still reproduces the problem remains.

## General Debugging Workflow

A useful debugging process is:

```text
Reproduce the problem
        |
        v
Read the first useful error/message
        |
        v
Identify the file and line involved
        |
        v
Form a small hypothesis
        |
        v
Make one change
        |
        v
Compile/run again
        |
        +---- fixed? ---- yes ---> done
        |
        no
        |
        v
Inspect values / simplify / repeat
```

### Compile errors

Compiler errors usually point to a syntax, type, declaration, or definition problem. Fix errors from the top of the compiler output downward, since one early mistake can cause many additional messages.

### Linker errors

For C and C++, linker errors often mean that something was declared or referenced but the required definition was not linked into the final program. Check that all required source files are included in the compile command and that function or method definitions match their declarations.

### Runtime errors

If a program compiles but crashes or produces incorrect output:

- Identify the smallest input that reproduces the problem.
- Print or inspect important variable values.
- Check array/list indexes, pointers/references, loop conditions, and recursive base cases.
- Verify assumptions immediately before the code where the failure occurs.

### Logic errors

When a program runs without reporting an error but gives the wrong answer, trace a small example by hand and compare the expected values with the program's actual intermediate values.

## Language Notes

### C

See [c_debugging.md](c_debugging.md) and [c_errors/](c_errors/).

Pay particular attention to compiler warnings, pointer use, array bounds, format strings, declarations, and memory-related errors.

### C++

See [cpp_debugging.md](cpp_debugging.md) and [cpp_errors/](cpp_errors/).

In addition to C-style problems, C++ programs may produce errors involving classes, constructors, namespaces, method definitions, templates, and linking. If a large number of compiler errors appears, begin with the first one.

### Java

See [java_debugging.md](java_debugging.md).

Check package declarations, imports, class structure, method placement, and IDE error messages. In Eclipse, hovering over an error marker can provide more detail about the problem.

### Prolog

See [prolog_debugging.md](prolog_debugging.md).

Common issues include variables that are not sufficiently instantiated, incorrect predicate arity, misplaced punctuation, and confusion between queries and program clauses.

### Scheme

See [scheme_debugging.md](scheme_debugging.md).

Common issues include incorrect types, calling a value as though it were a procedure, incorrect argument counts, unquoted lists, and parenthesis errors.

## Tips for Asking for Help

If you still cannot identify the problem, include the following when asking someone for help:

- The exact error message.
- The smallest code example that reproduces the problem.
- The command used to compile or run the program.
- What you expected to happen.
- What actually happened.
- What you have already tried.

Avoid posting only a screenshot when the error and source code can be copied as text. Text is easier to search, quote, test, and diagnose.
