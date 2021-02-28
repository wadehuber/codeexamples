#lang scheme

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
