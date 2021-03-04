#lang scheme

(define lst '(1 2 3 4))
(define lst2 '(-1 2 -3 4 -5 6 -7 8 -9 10))
(define lst3 '( -1 2 3 -4 7 -3 9 -4))

"Sum the elements of a list"
(define sumlist
  (lambda (lst)
    (if (null? lst)
        0
        (+ (car lst) (sumlist (cdr lst))))))
(sumlist lst)
(sumlist lst2)
(sumlist lst3)

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
(doublelist lst2)
(doublelist lst3)

"The sum of the double of each element in the list"
(define sumdoublelist
  (lambda (lst)
    (if (null? lst)
        0
        (+ (double (car lst)) (sumdoublelist (cdr lst))))))
(sumdoublelist lst)
(sumdoublelist lst2)
(sumdoublelist lst3)

"Summing the doubles of a list using methods we've already written"
(define better-sumdoublelist
  (lambda (lst)
    (sumlist (doublelist lst))))
(better-sumdoublelist lst)
(better-sumdoublelist lst2)
(better-sumdoublelist lst3)

"Add two lists together (pairwise)"
(define addlists
  (lambda (lst1 lst2)
    (cond
      ((null? lst1) lst2)
      ((null? lst2) lst1)
      (else (cons (+ (car lst1) (car lst2)) (addlists (cdr lst1) (cdr lst2)))))))
(addlists '(1 2 3 4) '(10 20 30 40))
(addlists '(1 2 3 4 5 6) '(1 1 1 1))
(addlists '(1 2 3 4) '(1 1 1 1 1 1 1 1))

"Generate a list of numbers up to n"
(define numlist
  (lambda (n)
    (if (< n 1)
        '()
        (append (numlist (- n 1)) (list n)))))
(numlist -2)
(numlist 9)
(numlist 20)
