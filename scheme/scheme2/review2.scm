#lang scheme

"Review"
(define a 1)
(define b a)
(define c (+ a b))
a
b
c

(* -1 c)
(- c)
(- (- c))

(define opposite
  (lambda (x)
    (- x)))
(opposite 10)
(opposite -10)
(opposite (opposite 10))
(opposite (opposite -10))

(newline)
"Tail-recursive Fibonacci implementation"
(define fib-tail
  (lambda (x)
    (fib-tail-acc x 0 1)))
(define fib-tail-acc
  (lambda (x f2 f1)
    (if (<= x 2)
        (+ f1 f2)
        (fib-tail-acc (- x 1) f1 (+ f1 f2)))))
(fib-tail 10)
(fib-tail 20)

(newline)
"Conditional statements"
(define what-is-it?
  (lambda (x)
    (cond
      ((not (number? x)) "Not a number")
      ((< x 0) "Negative")
      ((= x 0) "Zero")
      (else "Positive"))))
(what-is-it? 2)
(what-is-it? +)
(what-is-it? -4)

(define return-something
  (lambda (x)
    (cond
      ((> x 11) 10)
      ((= (remainder x 2) 0) 2)
      ((> x 5) 5)
      (#t 0))))
(return-something 20)
(return-something 8)
(return-something 7)
(return-something 3)