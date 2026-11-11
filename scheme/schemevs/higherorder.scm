#lang scheme

; Higher-order functions - functions that take functions as parameters.
; map, filter, and foldl capture common loop patterns so we don't write the loop.

(define lst '(-4 7 -2 5 10 -9 3))
(define square (lambda (x) (* x x)))

"map - apply a function to every element"
(map square lst)
(map abs lst)
(map (lambda (x) (* x 10)) lst)         ; an anonymous function made on the spot

(newline)
"filter - keep only the elements that pass a test"
(filter positive? lst)
(filter even? lst)
(filter (lambda (x) (> x 4)) lst)

(newline)
"foldl - combine all elements into one value"
(foldl + 0 lst)                          ; sum
(foldl max (car lst) lst)                ; largest value

(newline)
"apply vs foldl - NOT the same thing"
; apply calls the function once with every element as an argument: (- 1 2 3)
; foldl calls it once per element, as (f element accumulator):     (- 3 (- 2 (- 1 0)))
(apply - '(1 2 3))                       ; -4
(foldl - 0 '(1 2 3))                     ; 2

(newline)
"Combining them - sum of the squares of the positive numbers"
(foldl + 0 (map square (filter positive? lst)))

; read it inside-out: filter -> map -> fold
(define sum-pos-squares
  (lambda (lst)
    (foldl + 0 (map square (filter positive? lst)))))
(sum-pos-squares lst)
(sum-pos-squares '(1 2 3))

(newline)
"Functions are values - we can store them in a list and map over THAT"
(define operations (list square abs (lambda (x) (+ x 100))))
(map (lambda (op) (op -5)) operations)

(newline)
"Writing our own higher-order function"
(define apply-twice
  (lambda (f x)
    (f (f x))))
(apply-twice square 3)
(apply-twice (lambda (s) (string-append s "!")) "Hello")
