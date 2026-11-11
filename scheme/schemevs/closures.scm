#lang scheme

; Closures & currying - functions that RETURN functions.
; The returned function "remembers" the values it was created with.

"make-adder - returns a new function each time it is called"
(define make-adder
  (lambda (n)
    (lambda (x)
      (+ x n))))
(define add5 (make-adder 5))
(define add100 (make-adder 100))
(add5 10)
(add100 10)
((make-adder 3) 4)                       ; create and call in one step
(map (make-adder 1) '(1 2 3))

(newline)
"Strict currying - a chain of one-argument functions"
(define add
  (lambda (a)
    (lambda (b)
      (+ a b))))
((add 3) 4)

(newline)
"Partial application - filter a list for numbers in a range"
(define valid-number
  (lambda (n x y)
    (and (>= n x) (<= n y))))

; filter needs a ONE-parameter function, so we fix the range now and
; supply n later. The course notes call this currying; strictly speaking it
; is PARTIAL APPLICATION, because x and y are supplied together rather than
; one at a time. Fully curried would be (lambda (x) (lambda (y) (lambda (n) ...))).
(define valid-number-curr
  (lambda (x y)
    (lambda (n)
      (valid-number n x y))))
(filter (valid-number-curr 0 20) '(-10 -5 0 5 10 15 20 25 30))
(filter (valid-number-curr -5 5) '(-10 -5 0 5 10 15 20 25 30))

(newline)
"Generating polynomial functions - f(x) = ax^2 + bx + c"
(define quad
  (lambda (a b c)
    (lambda (x)
      (+ (* a x x) (* b x) c))))
(define f1 (quad 1 2 3))                 ; x^2 + 2x + 3
(define f2 (quad 2 0 -8))                ; 2x^2 - 8
(f1 2)
(f2 2)
(map f1 '(0 1 2 3 4))

(newline)
"compose - combine two functions into a new one"
(define compose2
  (lambda (f g)
    (lambda (x)
      (f (g x)))))
(define square-then-add5 (compose2 add5 (lambda (x) (* x x))))
(square-then-add5 3)                     ; 3*3 + 5 = 14
