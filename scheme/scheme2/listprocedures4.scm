#lang scheme

(define lst '(2 4 6 8 10 12))

"add-half-squares"
(define half-square
  (lambda (x)
    (/ (* x x) 2)))
(define add-half-squares
  (lambda (lst)
    (if (null? lst)
        0
        (+ (half-square (car lst)) (add-half-squares (cdr lst))))))
(add-half-squares lst)
(add-half-squares '(-1 2 -3 4 -5 6 -7 8 -9 10))

(newline)
"where-is"
(define where-is
  (lambda (lst n)
    (where-is-helper lst n 1)))
(define where-is-helper
  (lambda (lst n loc)
    (cond
      ((null? lst) -1)
      ((equal? (car lst) n) loc)
      (else (where-is-helper (cdr lst) n (+ loc 1))))))

(newline)
"same-structure?"
(define same-structure?
  (lambda (lst1 lst2)
    (if (and (pair? lst1) (pair? lst2))
        (and (same-structure? (car lst1) (car lst2))
             (same-structure? (cdr lst1) (cdr lst2)))
        (if (or (pair? lst1) (pair? lst2))
            #f
            #t))))
(same-structure? '(a b c d) '(1 2 3 4))
(same-structure? '(a (b . c) (d e f)) '(1 (2 . 3) (4 5 6)))
(same-structure? '(a b (c . d)) '(1 2 (3 4)))
(same-structure? '(a b c d) '(1 2 3 4 5))







