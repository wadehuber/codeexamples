#lang scheme

(define increment (lambda (x) (+ x 1)))

"Higher-order Functions"
"Functions as parameters"
(define hof-example1
  (lambda (func param)
    (func param)))
(hof-example1 increment 7)
(hof-example1 symbol->string 'HigherOrderFunction)
(hof-example1 even? 8)

(define hof-example2
  (lambda (func param1 param2)
    (func param1 param2)))
(hof-example2 + 23 19)
(hof-example2 max 421 65000)
(hof-example2 cons 'higher 'order)
(hof-example2 (lambda (x y) (- (* x x) y)) 5 4)

(define hof-example3
  (lambda (x)
    (lambda (y)
      (+ x y))))
(hof-example3 10)
((hof-example3 10) 5)
(define add10 (hof-example3 10))
(add10 24)

(define hof-example4
  (lambda (y)
    (lambda (x)
      (cons x y))))
(hof-example4 '(1 2 3))
((hof-example4 '(1 2 3)) 0)
((hof-example4 '(1 2 3)) 'a)
(define make-list (hof-example4 '()))
(make-list 'a)
(make-list '(1 2 3))