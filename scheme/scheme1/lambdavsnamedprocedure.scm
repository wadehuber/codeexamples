#lang scheme

; lambda - evaluates to a function - x & y are formal parameters
(lambda (x y) (+ (* x x) (* y y)))

; using a lambda with actual parameters 4 & 7
((lambda (x y) (+ (* x x) (* y y))) 4 7)

; we want to use that function again, so we give it a name with define
; now it is a named function with the name "sum-of-squares"
(define sum-of-squares
  (lambda (x y)
    (+ (* x x ) (* y y))))

; evaluating our named function with actual parameters 4 & 7
(sum-of-squares 4 7)
