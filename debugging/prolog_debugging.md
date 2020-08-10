# Prolog Debugging Hints

## Instantiation errors

```(text)
ERROR: Arguments are not sufficiently instantiated
```

Instantiation errors are very common and have many causes.

- Ignoring singleton variable warnings
- Using predicates that expect ground parameters before the variables are ground.  For example:  `Num1 is Num + 1` requires `Num` to be ground before it can calculate Num1.
- Queries do not belong in your `.pl` file!  A query such as `thing(X,Y).` will unify at the command line.  But if you add it to your `.pl` file you will get an instantiation error.

## No permission to modify or cannot redefine errors

```(text)
ERROR: No permission to modify static procedure '(,)/2'
```

or

```(text)
ERROR: Full stop in clause-body?  Cannot redefine ,/2
```

This is typically the result of accidentally adding a `.`  in the middle of a rule or failing to terminate a rule with `.`.

## Undefined procedure

```(text)
'<meta-call>'/1: Undefined procedure: myrule/5
```

You don’t have a procedure called `myrule` with 5 parameters.  If `myrule` exists, then you likely called it with the wrong number of parameters.

## Operator priority clash

```(text)
Syntax error: Operator priority clash
```

One cause of this error is a missing body of a rule, for example, in the following code note how there is no body in the first rule (the base case):

```(text)
do_something([],[]) :-
do_something([H|T],[T1]) :- H = 2, !, do_something(T, T1).
do_something([H|T],[T1]) :- do_something(T, T1).
```

## Strange string output

```(text)
X = [72, 101, 108, 108, 111, 44, 32, 119, 111|...].
```

SWI-Prolog treats double quoted strings as a list of character codes.  (This behavior is configurable.  The solution is to use single quoted strings which SWI-Prolog treats as an atom.  

```(text)
?- same("Hello, world!",X).
X = [72, 101, 108, 108, 111, 44, 32, 119, 111|...].
?- same('Hello, world!',X).
X = 'Hello, world!'.
```
