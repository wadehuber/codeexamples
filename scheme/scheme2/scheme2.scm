#lang scheme

(newline)
"Recursive arithmetic"
(define increment
  (lambda (x)
    (+ 1 x)))
(define decrement
  (lambda(x)
    (- x 1)))
(increment 10)
(decrement 10)

"Recursive addition"
(define recursive-add
  (lambda (x y)
    (if (zero? y)
        x
        (recursive-add (increment x) (decrement y)))))
(recursive-add 10 5)
(recursive-add 23 7)
(recursive-add 0 5)

"Recursive multiplication"
(define recursive-mult
  (lambda (x y)
    (if (zero? (decrement y))
        x
        (recursive-add x (recursive-mult x (decrement y))))))
(recursive-mult 10 5)
(recursive-mult 23 7)
(recursive-mult 0 5)

(newline)
"null"
null
(null? '())
(null? 2)
(null? -1)
;(null? ())
(null? (+ 4 2))
(null? null)
(null? null?)
(null? (car '(0)))
(null? (cdr '(0)))

(newline)
"List procedures"
(define lst '(0 2 3 4))
(car lst)
(cdr lst)
(cons -1 '(1 2 3 4))
(car (cons -1 lst))
(cdr (cons -1 lst))
(cons '(a b c) lst)
(append '(a b c) lst)
(append lst lst)
(cons lst lst)
(append lst (cons lst lst))
(cons lst 4)
(cons lst (list 4))
(append lst (list 4))

(newline)
"Creating a list"
(define exlst-1 (+ 2 3))
(define exlst0 '(+ 2 3))
(define exlst1 (list + 2 3))
(define exlst2 (list (+ 2 3 )))
(define exlst3 (list '(+ 2 3 )))
(define exlst4 (cons '+ (cons 2 '(3))))
(define exlst5 (cons '+ (cons 2 (cons 3 '()))))
(define exlst6 (cons '+ (cons 2 (cons 3 null))))
(define exlst7 (list 2 (+ 2 1)))
(define exlst8 (list list 2 3))
(define exlst9 (list list 2 3 (list + 2 3) (+ 2 3)))
(define exlst10 '(list 2 3 (list + 2 3) (+ 2 3)))
exlst-1
exlst0
exlst1
exlst2
exlst3
exlst4
exlst5
exlst6
exlst7
exlst8
exlst9
exlst10
(newline)
exlst1
exlst3

(length exlst3)
(length (car exlst3))
(car exlst3)
(cdr exlst3)
;((car exlst0) 10 20 30)
((car exlst1) 10 20 30)
;    +             1              3
((car exlst1) (cadr exlst2) (caddr exlst2))


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

"Remove an element from a list - The Little Schemer"
;Only remves the *first* occurrence
"rember"
(define rember
  (lambda (ele lst)
    (cond
      ((null? lst) '())
      ((eq? (car lst) ele) (cdr lst))
      (else (cons (car lst) (rember ele (cdr lst)))))))
(rember 3 '(1 2 3 4))
(rember 4 '(1 2 3 4))
(rember 5 '(1 2 3 4))

"Duplicate each element of the list"
(define duplicate-list
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (car lst) (cons (car lst) (duplicate-list (cdr lst)))))))
(duplicate-list lst)
(duplicate-list (list 2 * '(1 2 3) 7 'Hello))

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
