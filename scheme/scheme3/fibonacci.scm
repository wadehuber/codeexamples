#lang scheme

(provide fib-tail)
(provide xyz)

; Recursive Fibonacci function
(define fib
  (lambda (x)
    (if (<= x 2)
        1
        (+ (fib (- x 2)) (fib (- x 1))))))

; Tail-recursive Fibonacci 
(define fib-tail
  (lambda (x)
    (fib-tail-acc x 0 1)))
(define fib-tail-acc
  (lambda (x f2 f1)
    (if (<= x 0)
        f2
        (fib-tail-acc (- x 1) f1 (+ f1 f2)))))

(define abc 20)
(define xyz 30)

"fibonacci.scm"
"defined names"
abc
xyz
"functions"
(fib 10)
(fib-tail 10)