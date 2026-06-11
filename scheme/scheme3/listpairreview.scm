#lang scheme
(define x 5)

(newline)
"Lists"

; Lists are built from pairs.
; The empty list is written as '().

(list 1 2 3 4)
(quote (a b c d))

; x is evaluated, but 'a is quoted.
; + evaluates to the addition procedure.
(list 'a x +)

; Here the whole list is quoted, so nothing inside is evaluated.
(quote (a x +))

; List operations
(define lst (list 1 2 3 4 5))

(car lst)       ; first item
(cdr lst)       ; rest of the list
(cadr lst)      ; same as (car (cdr lst))

(cons 0 lst)    ; add one item to the front

; Cons vs append
(cons '(a b c) '(1 2 3))
(append '(a b c) '(1 2 3))


(newline)
"Pairs"

; cons creates a pair.
; Lists are a special case where the second part (cdr) is another list.

(cons 1 2)

(define pr '(a . b))

(car pr)
(cdr pr)

; A one-item list is a pair whose cdr is the empty list.
(cons 3 '())

; This creates a list because the second argument is already a list.
(cons 'm '(n o p q))

(newline)
"Example list procedures"

; Add all numbers in a list.
(define add-list
  (lambda (x)
    (if (null? x)
        0
        (+ (car x)
           (add-list (cdr x))))))

(add-list '(10 37 39))
(add-list lst)

; Build a new list where each number is divided by 2.
(define halve-each-element
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (/ (car lst) 2)
              (halve-each-element (cdr lst))))))
(halve-each-element '(37 89 42 28))