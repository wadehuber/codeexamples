#lang scheme

"Recursive arithmetic"

(define increment
  (lambda (x)
    (+ x 1)))
(define decrement
  (lambda (x)
    (- x 1)))
(increment 10)
(decrement 10)

(newline)
"Define addition recursively"
(define recursive-add
  (lambda (x y)
    (if (zero? y)
        x
        (recursive-add (increment x) (decrement y)))))
(recursive-add 9 5)
(recursive-add 7 22)
(recursive-add 0 6)


(newline)
"Define multiplication recursively"
(define recursive-mult
  (lambda (x y)
    (if (zero? y)
        0
        (recursive-add x (recursive-mult x (decrement y))))))
(recursive-mult 9 5)
(recursive-mult 7 22)
(recursive-mult 0 6)
(recursive-mult 5 0)