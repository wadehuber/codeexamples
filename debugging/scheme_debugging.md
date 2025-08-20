# Scheme Debugging Tips

## General hints

- Keep your functions short.  Short functions are easier to debug.  Complex functions composed of smaller functions can be tested piece by piece.

## Contract violation

```(text)
+: contract violation
expected: number?
given: A
```

This means Scheme was expecting a form of a certain type but was given a different type.  Something like `(+ 3 "String")` where the 2nd element is a string, not a number as expected.  This is also common when you try to do a list operation on an atom.  The first line will indicate what function gave the error, the second line (`expected:`) will let you know what type was expected and the final line (`given:`) will indicate what input you passed.

## Application not a procedure

```(text)
application: not a procedure;
```

This happens when you ask Scheme to evaluate something where the first item in the form is not a procedure.  A common place where this occurs is when you forget to quote a list, like `(car (1 2 3 4))`.  In this case, `(1 2 3 4)` is not a list.

## Arity mismatch

```(text)
my-defined-function: arity mismatch;
the expected number of arguments does not match the given number
 expected: 2
 given: 1
 arguments…;
```

This error is given when you pass the wrong number of arguments to a function.  The expected number of arguments will be listed along with how many arguments you passed.  To resolve, you need to find where the function call is with the wrong number of parameters.  This is a common error with recursive functions.  Check that both recursive calls have the correct number of parameters.

```(scheme)
(define (my-function)
  (lambda (x y)
    (+ x y)))

. . my-function: arity mismatch;
 the expected number of arguments does not match the given number
  expected: 0
  given: 2
  arguments...:
```

This error is likely the result of having an extraneous pair of parenthesis around the name of the function, such as in the case above.  Removing the parenthesis around my-function will solve the problem.

## Multiple expressions after identifier

```(text)
define: bad syntax (multiple expressions after identifier) in: (define add (lambda x y) (+ x y)
```

This error is the result of a missing opening parenthesis before the x parameter following the lambda.  The correct defintion for that procedure is as follows (note the added parenthesis before the x parameter and at the end of the definiton):

```(lisp)
(define add (lambda (x y) (+ x y)))
```
