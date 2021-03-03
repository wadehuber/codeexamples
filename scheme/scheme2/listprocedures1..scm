#lang scheme

(newline)
"Defining List Procedures"
(car '(a))
(cdr '(b))
(car '(1 2 3))
(cdr '(1 2 3))
(null? '(1 2 3))
(null? '())
lst

"Check if a list is non-empty"
(define non-empty-list?
  (lambda (lst)
    (not (or (not (list? lst)) (null? lst)))))
(non-empty-list? '())
(non-empty-list? '(1 2 3 4))
(non-empty-list? lst)
(non-empty-list? 'NotAList)

"Do nothing with a list"
(define do-nothing
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (car lst) (do-nothing (cdr lst))))))
(do-nothing '(8 9 10 11 12))
(do-nothing (list 3 + 'Hello "World" 7))
(do-nothing lst)

"Duplicate each element of the list"
(define duplicate-list
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (car lst) (cons (car lst) (duplicate-list (cdr lst)))))))
(duplicate-list lst)
(duplicate-list (list 2 * '(1 2 3) 7 'Hello))

"Remove an element from a list - The Little Schemer"
;Only remves the *first* occurrence
"rember"
(define rember
  (lambda (ele lst)
    (cond
      ((null? lst) '())
      ((eq? (car lst) ele) (cdr lst))
      (else (cons (car lst) (rember ele (cdr lst)))))))
(rember 2 '(1 2 3 4))
(rember 3 '(1 2 3 4))
(rember 4 '(1 2 3 4))

"Return list with only number"
(define only-nums
  (lambda (lst)
    (if (null? lst)
        '()
        (if (number? (car lst))
            (cons (car lst) (only-nums (cdr lst)))
            (only-nums (cdr lst))))))
(only-nums lst)
(only-nums (list 2 * '(1 2 3) 7 'Hello))
(only-nums '(a b c))

"Check if something is a list of atoms - from The Little Schemer"
(define atom?
  (lambda (a)
    (and (not (pair? a)) (not (null? a)))))
"lat?"
(define lat?
  (lambda (lst)
    (cond
      ((null? lst) #t)
      ((atom? (car lst)) (lat? (cdr lst)))
      (else #f))))
(lat? '(8 9 10 11 12))
(lat? (list 3 + 'Hello "World" 7))
(lat? (list lst '(a b c)))
(lat? lst)

"member?"
(define member?
  (lambda (ele lst)
    (cond
      ((null? lst) #f)
      ((equal? (car lst) ele) #t)
      ((member? ele (cdr lst)) #t)
      (else #f))))
(member? 3 '(1 2 3 4))
(member? 5 '(1 2 3 4))
(member? 4 '(1 2 (3 4) 5))
(member? '(3 4) '(1 2 (3 4) 5))
(member? 5 '(1 2 (3 4) 5))
(member? 7 '(1 2 (3 4) 5))