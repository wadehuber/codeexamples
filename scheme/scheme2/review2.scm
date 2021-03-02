#lang scheme

"Review"
10
"CSC240"
'Wanda

(define a 1)
(define b 2)
(define c (- a b))
a
b
c

(* -1 c)
(- c)
(- (- c))

(newline)
"Defining functions"
(define opposite
  (lambda (x)
    (- x)))
(opposite 10)
(opposite -10)
(opposite (opposite c))
(opposite (opposite (opposite c)))

"Tail-recursive fibonacci implementation"
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

"Example cond (switch) statement"
(define return-something
  (lambda (x)
    (cond
      ((not (number? x)) 'NotANumber)
      ((> x 11) 10)
      ((= (remainder x 2) 0) 2)
      ((> x 5) 5)
      (#t 0))))
(return-something 20)
(return-something 8)
(return-something 7)
(return-something 3)
(return-something 'SymbolInput)

(define what-is-it?
  (lambda (x)
    (cond
      ((not (number? x)) "Not a number!")
      ((< x 0) 'Negative)
      ((= x 0) 'Zero)
      ((> x 0) 'Positive)
      (else 'Unknown))))
(what-is-it? "BadInput")
(what-is-it? 2)
(what-is-it? -3)
(what-is-it? (- (* 3 3) 9))
