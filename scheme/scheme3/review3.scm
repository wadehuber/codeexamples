#lang scheme

(define (increment a) (+ a 1))  ; note that a has local scope
((lambda (x) (+ x 1)) 10)       ; unnamed procecure
(define increment-lambda        ; name an unnamed procedure
  (lambda (x)
    (+ x 1)))

(define x 10)
(increment 10)
(increment x)
(increment-lambda 10)

(define do
  (lambda (this that)
    (this that)))
(do increment (+ x 3))
(do (lambda (x) (* x 2)) x)

; multi-conditional procedure
(define day-of-week
  (lambda (n)
    (cond
      ((equal? 'Sunday n) 1)
      ((equal? 'Monday n) 2)
      ((equal? 'Tuesday n) 3)
      ((equal? 'Wednesday n) 4)
      ((equal? 'Thursday n) 5)
      ((equal? 'Friday n) 6)
      ((equal? 'Saturday n) 7)
      (else 0))))
(day-of-week 'Sunday)
(day-of-week 'Friday)
(define Thursday 10)
Thursday
(day-of-week 'Thursday)
(day-of-week Thursday)

(define grade
  (lambda (n)
    (cond
      ((>= n 900) 'A)
      ((>= n 800) 'B)
      ((>= n 700) 'C)
      ((>= n 550) 'D)
      (else 'F))))
(grade 100)
(grade 899)
(grade (+ 810 91))

(define hanoi
  (lambda (n source center destination)
    (if (= n 1)    ; base case
        (list 'Move source destination)
        (list
           (hanoi (- n 1) source destination center)
           (hanoi 1 source center destination)
           (hanoi (- n 1) center source destination)
         ))))
(hanoi 4 'red 'yellow 'blue)

(newline)
"Including a module"
(require "scheme3inc.scm")
(fib-tail 10)
;(fib 10)    ; Not provided by scheme3inc.scm