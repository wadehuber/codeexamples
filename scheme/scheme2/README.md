# Scheme Module2

You must understand recursion for this module.  The two videos below go over how recursion works & tail recursion.

- [VIDEO: Thinking recursively video](https://youtu.be/OpX214pT6D0) (2:59): *Walkthrough of recursive solutions to several problems*
- [VIDEO: Tail recursion](https://youtu.be/mFiRdTmbs3E) (10:40) *Introduction to tail recursion*

## [review2.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/review2.scm) - Review of Module 1 content

[Video](https://youtu.be/IMJNNLLM99U) (9:05): *Review of atoms, define, cond, and defining functions*

## [cond_or_if.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/cond_or_if.scm)

[Video](https://youtu.be/7T7cRF_gkkg) (2:35): *Using if vs using cond in Scheme*

## [recursivearithmetic.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/recursivearithmetic.scm)

[Video](https://youtu.be/uyER4B3q9ag) (6:43): *Example of recursively defining addition & subtraction*

## [listprimitives.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/listprimitives.scm)

[Video](https://youtu.be/slotKodkA-U) (15:32): *Overview of null, car, cdr, cons, append, and length in preparation for writing list procedures*

## [listprocedures1.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/listprocedures1.scm)

[Video](https://youtu.be/a8tulokZSk8) (14:54): *Introduction to writing list procedures in Scheme*

This video introduces writing recursive list procedures in Scheme, including a method that does nothing but go through a list (leaving it alone) to demonstrate the general structure of a recursive list procedure.  The video also walks through the `rember` procedure from *The Little Schemer* that removes the first occurence of an element, a procedure to remove non-numeric values from a list, the procedure `lat?` from *The Little Schemer* that checks that all elements of a list are atoms, and finally a `member?` predicate.

## [listprocedures2.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/listprocedures2.scm)

[Video](https://youtu.be/9PninqTenfU) (11:34): *List procedures that combine the elements of a list*

Examples include summing the elements of a list, doubling each element of a list, summing the double of each element in the list, and adding two lists together in a pairwise fashion.

## [listprocedures3.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/listprocedures3.scm)

[Video](https://youtu.be/2JkRNjOmbRs) (7:37): *Additional examples of writing recursive list procedures in Scheme*

This video features examples of writing a procedure recursively generating a list and of writing procedures that return a modified version of the list.  

## [listprocedures4.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/listprocedures4.scm)

[Video](https://youtu.be/Y7NQD9hABfI) (6:26): *Even more examples of writing recursive list procedures in Scheme*

This video features examples of writing a procedure that combines the elements of a list, searching lists, and working with nested lists (lists that contain other lists).

## [replaceinlist.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/replaceinlist.scm)

A review of car, cdr, & cons followed by a recursive procedure that replaces all occurrences of a value in a list.  A good example of the standard recursive list procedure structure: a base case for the empty list, a case that processes the first element, and a recursive call on the rest of the list.

## [pairs.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/pairs.scm)

[Video](https://youtu.be/lML7RaSldkI) (15:16): *Introduction to Scheme pairs*

Includes difference between pairs & lists, using pairs, and writing functions that work with pairs

## [pairprocedures.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/pairprocedures.scm)

[Video](https://youtu.be/RjxklP-5eMs) (4:08): *Writing Scheme procedures with a pair as a parameter*

This video features examples of writing procedures that have a pair as one of the paramters, including a case where a list is one of the elements in the pair.

## [problems.scm](https://github.com/wadehuber/codeexamples/blob/master/scheme/scheme2/problems.scm)

[Video](https://youtu.be/EYgBVkSe4S4) (8:43) *Some common mistakes when working with recursive list procedures*
