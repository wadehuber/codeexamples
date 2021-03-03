#lang scheme

"Sum the elements of a list"
(define sumlist
  (lambda (lst)
    (if (null? lst)
        0
        (+ (car lst) (sumlist (cdr lst))))))
(sumlist lst)
(sumlist '(-1 2 3 -4 7 -3 9 -4))

"Double each element of the list"
(define double
  (lambda (x)
    (* x 2)))
(define doublelist
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (double (car lst)) (doublelist (cdr lst))))))
(doublelist lst)
(doublelist '(-1 2 3 -4 7 -3 9 -4))

"The sum of the double of each element in the list"
(define sumdoublelist
  (lambda (lst)
    (if (null? lst)
       0
       (+ (double (car lst)) (sumdoublelist (cdr lst))))))
(sumdoublelist lst)
(sumdoublelist '(-1 2 3 -4 7 -3 9 -4))

"Using methods we have written before"
(define better-sumdoublelist
  (lambda (lst)
    (sumlist (doublelist lst))))
(better-sumdoublelist lst)
(better-sumdoublelist '(-1 2 3 -4 7 -3 9 -4))

"Add two lists of numbers"
(define addlists
  (lambda (lst1 lst2)
    (cond
      ((null? lst1) lst2)
      ((null? lst2) lst1)
      (else (cons (+ (car lst1) (car lst2)) (addlists (cdr lst1) (cdr lst2)))))))
(addlists '(1 2 3 4) '(10 20 30 40))
(addlists '(1 2 3 4 5 6) '(1 1 1 1))
(addlists '(1 2 3 4) '(1 1 1 1 1 1 1))

"Generate a listof numbers up to n"
(define numlist
  (lambda (n)
    (if (< n 1)
        '()
        (append (numlist (- n 1)) (list n)))))
(numlist 10)