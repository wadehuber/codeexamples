#lang scheme

; examples of prefix notation
(+ 3 4)
(* 20 42)

(define add
  (lambda (x y)
    (+ x y)))

(add 19 63)
(add 326 599)