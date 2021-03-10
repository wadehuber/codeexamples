#lang scheme

(define lst '(1 2 3 4))
lst
(car lst)
(cdr lst)
(car '(a))
(cdr '(a))
(null? lst)
(null? '())

"Do nothing with a list"
(define do-nothing
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (car lst) (do-nothing (cdr lst))))))
(do-nothing lst)
(do-nothing '(8 9 10 11 12))
(do-nothing (list 3 + 'Hello "World" 7.0))

(newline)
"Check if something is a non-empty list"
(define non-empty-list?
  (lambda (lst)
    (not (or (not (list? lst)) (null? lst)))))
(non-empty-list? '())
(non-empty-list? '(a b c d))
(non-empty-list? lst)
(non-empty-list? 'NotAList)
(non-empty-list? (list 3 + 'Hello "World" 7.0))

(newline)
"Duplicate each element of the list"
(define duplicate-list
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (car lst) (cons (car lst) (duplicate-list (cdr lst)))))))
(duplicate-list (list 3 + 'Hello "World" 7.0))
(duplicate-list lst)

(newline)
"rember: Remove an element from a list - The Little Schemer"
;Only remves the *first* occurrence
(define rember
  (lambda (ele lst)
    (cond
      ((null? lst) '())
      ((equal? (car lst) ele) (cdr lst))
      (else (cons (car lst) (rember ele (cdr lst)))))))
(rember 1 lst)
(rember 4 lst)
(rember 1 '(1 1 1 1 1 1))
(rember 'Hello (list 3 + 'Hello "World" 7.0))
(rember + (list 3 + 'Hello "World" 7.0))

(newline)
"Check if something is a list of atoms - from The Little Schemer"
(define atom?
  (lambda (a)
    (and (not (pair? a)) (not (null? a)))))
(atom? 3)
(atom? "Hello")
(atom? 'World)
(atom? '(a b c d))
(atom? lst)
(atom? '())
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

"Return list with only number"
(define only-nums
  (lambda (lst)
    (if (null?)
        '()
        (if (number? (car lst))
            (cons (car lst) (only-nums (cdr lst)))
            (only-nums (cdr lst))))))

"member?"
(define member?
  (lambda (ele lst)
    (cond
      ((null? lst) #f)
      ((equal? (car lst) ele) #t)
      ((member? ele (cdr lst)) #t)
      (else #f))))
(member? 1 lst)
(member? 4 lst)
(member? 5 lst)
(member? '(3 4) '(1 2 (3 4) 5))
(member? 5 '(1 2 (3 4) 5))
(member? 7 '(1 2 (3 4) 5))
(member? 4 '(1 2 (3 4) 5))