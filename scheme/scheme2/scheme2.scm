#lang scheme

"Review"
(define a 1)
(define b a)
(define c (+ a b))
a
b
c

(* -1 c)
(- c)
(- (- c))

(define opposite
  (lambda (x)
    (- x)))
(opposite 10)
(opposite -10)
(opposite (opposite 10))
(opposite (opposite -10))

(newline)
"Tail-recursive Fibonacci implementation"
(define fib-tail
  (lambda (x)
    (fib-tail-acc x 0 1)))
(define fib-tail-acc
  (lambda (x f2 f1)
    (if (<= x 2)
        (+ f1 f2)
        (fib-tail-acc (- x 1) f1 (+ f1 f2)))))
(fib-tail 10)
(fib-tail 20)

(newline)
"Conditional statements"
(define what-is-it?
  (lambda (x)
    (cond
      ((not (number? x)) "Not a number")
      ((< x 0) "Negative")
      ((= x 0) "Zero")
      (else "Positive"))))
(what-is-it? 2)
(what-is-it? +)
(what-is-it? -4)

(define return-something
  (lambda (x)
    (cond
      ((> x 11) 10)
      ((= (remainder x 2) 0) 2)
      ((> x 5) 5)
      (#t 0))))
(return-something 20)
(return-something 8)
(return-something 7)
(return-something 3)

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
(null? 3)
(null? 0)
;(null? ())
(null? (+ 5 2))
(null? null)
(null? null?)
(null? (car '(1)))
(null? (cdr '(1)))

(newline)
"List procedures"
(define lst '(1 2 3 4))
(car lst)
(cdr lst)
(cons 0 '(1 2 3 4))
(car (cons 0 lst))
(cdr (cons 0 lst))
(cons '(a b c) lst)
(append '(a b c) lst)
(append lst lst)
(cons lst lst)
(append lst (cons lst lst))
(cons lst 5)
(cons lst (list 5))
(append lst (list 5))

(newline)
"Creating a list"
(define exlst0 (+ 2 3))
(define exlst1 '(+ 2 3))
(define exlst2 (list + 2 3))
(define exlst3 (list (+ 2 3 )))
(define exlst4 (list '(+ 2 3 )))
(define exlst5 (cons '+ (cons 2 '(3))))
(define exlst6 (cons '+ (cons 2 (cons 3 '()))))
(define exlst7 (cons '+ (cons 2 (cons 3 null))))
(define exlst8 (list 2 (+ 2 1)))
(define exlst9 (list list 2 3))
(define exlst10 (list list 2 3 (list + 2 3) (+ 2 3)))
(define exlst11 '(list 2 3 (list + 2 3) (+ 2 3)))
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
exlst11
(newline)
exlst2
exlst4

(length exlst4)
(length (car exlst4))
(car exlst4)
(cdr exlst4)
;((car exlst1) 10 20 30)
((car exlst2) 10 20 30)
;    +             2              3
((car exlst2) (cadr exlst2) (caddr exlst2))


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

(newline)
"Pair"
(cons 1 '(2))
(cons 1 2)
(list? (cons 1 '(2)))
(list? (cons 1 2))
(pair? (cons 1 '(2)))
(pair? (cons 1 2))
(car '(1 . 2))
(cdr '(1 . 2))

(define pair1 (cons a b))     ; (a . b)
(define pair2 (cons a '()))   ; (a . ())
(define pair3 (cons a '(b)))  ; (a . (b . ()))
pair1
pair2
pair3

(pair? '(1 2 3))
(pair? '(1))
(pair? '())
(list? '())
(car pair1)
(cdr pair1)
(cons 'a 'b)
(cons 'a '())
(cons 'a (cons 'b '()))

;examples
'(30 . 90)      ; latitude / longitude
'(neworleans . (30 . 90))


