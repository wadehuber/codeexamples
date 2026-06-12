# Scheme Module 3 - Higher-Order Functions & Scope

## [review3.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/review3.scm)

[VIDEO](https://youtu.be/vBaToXTnCH4) (9:58): *Scheme Review*

This file contains a review of defining names & functions, conditionals, and recursion

## [listpairreview.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/listpairreview.scm)

Another review file covering lists & pairs: building lists with `list` & `quote`, list operations (car, cdr, cadr, cons, append), the difference between cons & append, and writing recursive list procedures.

## [module.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/module.scm) (includes [fibonacci.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/fibonacci.scm))

[VIDEO](https://youtu.be/x2ujbDeF-ug) (4:19): *Modules*

Example of including a Scheme module in another file (`provide`/`require`).  The fibonacci.scm module contains both a naive recursive and a tail-recursive Fibonacci implementation, but only provides the tail-recursive version.

## [reduce.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/reduce.scm)

[VIDEO](https://youtu.be/pRoTDsVKkDw) (9:47): *Reduce*

## Higher-order Functions

### [higherorderuser.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/higherorderuser.scm)

[VIDEO](https://youtu.be/V3lxZfO6guk) (5:26): *Writing higher-order functions*

### [higherorder.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/higherorder.scm)

[VIDEO](https://youtu.be/ATonPhARJ5g) (6:43): *Apply, map & filter*

### [mapapplyfilter.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/mapapplyfilter.scm)

[VIDEO](https://youtu.be/cqrj0rQn3Ag) (7:15): *Recursively implementing map, apply & filter*

This is an optional video showing how the higher-order functions from the previous video can be implemented recursively

## [currying.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/currying.scm)

[VIDEO](https://youtu.be/kOT44AC-x7s) (14:41): *Currying*

Introduction to Currying.  Creating a secret number game generating function.  Using Currying with higher-order functions (filtering a list of numbers in a range, increasing each element by a certain amount), creating polynomial functions using Currying.

## [letscope.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/letscope.scm)

[VIDEO](https://youtu.be/y25-KYfviEw) (9:18): *Scope (let structures)*

## [advancedtopics.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/advancedtopics.scm)

[VIDEO](https://youtu.be/3dfEXUz0NTg) (4:45): *Advanced topics: case-lambda & match*

## [database.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme3/database.scm) - Example of using pairs to build a table

[Video](https://youtu.be/TSAk5CMxp4E) (6:51): *Setting up a table of values using Scheme pairs*
