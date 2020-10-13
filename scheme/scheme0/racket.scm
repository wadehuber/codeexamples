#lang scheme

(define a 1)
(define b 2)

(define double
  (lambda (x)
    (* 2 x)))

(double a)
(double 10)