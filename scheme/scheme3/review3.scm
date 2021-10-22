#lang scheme

"Names & scope"
(define x 10)

(define (increment x) (+ x 1))   ; note that x has local scope
((lambda (x) (+ x 1)) 3)         ; unnamed procedure
(define increment-lambda         ; associate a name to unnamed procedure
  (lambda (x)
    (+ x 1)))
(increment x)
(increment 3)
(increment-lambda x)
(increment-lambda 3)

(newline)
"Defining procedures"
(define do
  (lambda (this that)
    (this that)))
(do increment (+ 3 x))
(do (lambda (x) (* x 2)) x)
(do (lambda (x) (* x 2)) 3)

; multi-conditional procedure
"Days of the week"
(define day-of-the-week
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
(day-of-the-week 'Sunday)
(day-of-the-week 'Friday)
(define Thursday 10)
Thursday
(day-of-the-week Thursday)
(define Wednesday 'Wednesday)
(day-of-the-week Wednesday)

"Grade"
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

(newline)
"Towers of Hanoi"
(define hanoi
  (lambda (n source temp destination)
    (if (= n 1)   ; base case
        (list 'Move source destination)
        (list
            (hanoi (- n 1) source destination temp)
            (hanoi 1 source temp destination)
            (hanoi (- n 1) temp source destination)))))
(hanoi 3 'redpeg 'yellowpeg 'bluepeg)
(hanoi 4 'pegA 'pegB 'pegC)
