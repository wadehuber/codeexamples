#lang scheme

"null"
null
(null? '())
(null? '(1 2 3))
(null? 2)
(null? 0)
(null? #f)
;(null? ())
(null? (+ 4 2))
(null? null)
(null? null?)
"'(a)"
(car '(a))
(cdr '(a))
(null? (car '(a)))
(null? (cdr '(a)))

(newline)
"List procedures"
(define lst '(0 2 3 4))
lst
(car lst)
(cdr lst)
(cons -1 lst)
(car (cons -1 lst))
(cdr (cons -1 lst))
(cons '(a b c) lst)
(append '(a b c) lst)
(append lst lst)
(cons lst lst)
(append lst (cons lst lst))
(cons lst 5)
(append lst 5)
(cons lst (list 5))
(append lst (list 5))

(newline)
"Creating a list"
(define exlst1 (+ 2 3))
(define exlst2 '(+ 2 3 ))
(define exlst3 (list + 2 3))
(define exlst4 (cons '+ (cons 2 '(3))))
(define exlst5 (cons '+ (cons 2 (cons 3 '()))))
(define exlst6 (cons '+ (cons 2 (cons 3 null))))
(define exlst7 (cons + (cons 2 (cons 3 '()))))
(define exlst8 (list 2 (+ 2 1)))
(define exlst9 '(2 (+ 2 1)))
(define exlst10 (quote (2 (+ 2 1))))
(define exlst11 (list 2 3))
(define exlst12 (list list 2 3))
(define exlst13 (list list 2 3 (list + 2 3 ) (+ 2 3)))
(define exlst14 '(list 2 3 (list + 2 3 ) (+ 2 3)))
exlst1
exlst2
exlst3
((car exlst3) 10 20)
exlst4
exlst5
exlst6
exlst7
exlst8
exlst9
exlst10
exlst11
exlst12
exlst13
exlst14

"Length"
exlst2
(length exlst2)
exlst10
(length exlst10)
(length '(1 2 3 4 5 6 7 8 9 10 11))
(length '(1 2 (3 4) (5 6 (7 8) 9) 10 11))

exlst1
exlst2
exlst3
; ((car exlst2) 10 20 30)
((car exlst3) 10 20 30)
;    +             2              3
((car exlst3) (cadr exlst2) (caddr exlst2))










