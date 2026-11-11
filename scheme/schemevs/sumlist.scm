#lang scheme

; Summing a list - the same problem three ways.
; Notice that no variable is ever changed. There is no loop counter and no running total.

(define lst '(4 8 15 16 23 42))

"Recursive sum - defined the way you would define it in math"
; the sum of an empty list is 0
; the sum of a non-empty list is the first item plus the sum of the rest
(define sum
  (lambda (lst)
    (if (null? lst)
        0
        (+ (car lst) (sum (cdr lst))))))
(sum lst)
(sum '())

(newline)
"Tail-recursive sum - the running total is passed as a parameter"
; The recursive call is the LAST thing the function does, so Scheme
; reuses the stack frame. This runs like a loop without being one.
(define sum-acc
  (lambda (lst total)
    (if (null? lst)
        total
        (sum-acc (cdr lst) (+ total (car lst))))))
(sum-acc lst 0)

(newline)
"Higher-order sum - let a built-in function do the walking"
(apply + lst)
(foldl + 0 lst)

(newline)
"The original list is unchanged"
lst
