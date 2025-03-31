#lang scheme

(define check-it
  (lambda (a b)
    (if (>= a b)
        #t
        #f)))

"Testing check-it"
(check-it 10 20)
(check-it 20 10)

(newline)
(define return-it
  (lambda (a b)
    (>= a b)))

"Testing return-it"
(return-it 10 20)
(return-it 20 10)


(newline)
(define return-not
  (lambda (a b)
    (not (>= a b))))

"Testing return-not"
(return-not 10 20)
(return-not 20 10)