#lang scheme

(define x 10)
(define y 20)
(define (z) 30)

(define double
  (lambda (x)
    (* x 2)))

(newline)
"Lists"
(list x y z)
(list 'x 'y 'z)
'(x y z)
(quote (x y z))
(define lst '(a b c))
(define lst2 (list 'a 2 "hello" 'world / #f + double 10 x 'y 'a #\H '(1 2 3) (+ 3 1)))
(define lst3 (quote ('a 2 "hello" 'world / #f + double 10 x 'y 'a #\H '(1 2 3) (+ 3 1))))
(define oplist (list + - * /))
lst
lst2
lst3
oplist

(newline)
"quote vs list)"
(+ 1 2)          ; evaluate the operator + on the operands 1 & 2
'(+ 1 2)         ; do not evaluate, treat like a list
(quote (+ 1 2))  ; same as the above
(list + 1 2)     ; create a list with the elements + (the addition operator), 1, and 2

(newline)
"List operations"
lst
(car lst)
(cdr lst)
(car (cdr lst))
(cdr (cdr lst))
(car (cdr (cdr lst)))
(cdr (cdr (cdr lst)))
"Other examples"
(cdr '(1))
(car '((4 5 6)))
(cdr '((4 5 6)))
(car (car '((4 5 6))))
(cdr (car '((4 5 6))))
(car (cdr '(a b c)))
(cadr '(a b c))
(caddr '(a b c))

(newline)
"List with size 1"
(car '(1))
(cdr '(1))

(newline)
"Fun with car & cdr"
(define lst4 '((1 2) (3 4 (5 6)) (7 8)))
lst4
(car lst4)
(cdr lst4)
(car (car lst4))
(cdr (car lst4))
(car (cdr lst4))
(cdr (cdr lst4))
(car (car (cdr lst4)))
(cdr (car (cdr lst4)))
(car (cdr (car (cdr lst4))))
(cdr (cdr (car (cdr lst4))))
(car (cdr (cdr (car (cdr lst4)))))
(cdr (cdr (cdr (car (cdr lst4)))))
(car (car (cdr (cdr (car (cdr lst4))))))
(cdr (car (cdr (cdr (car (cdr lst4))))))
(car (cdr (car (cdr (cdr (car (cdr lst4)))))))
(cdr (cdr (car (cdr (cdr (car (cdr lst4)))))))

(newline)
"Cool example"
oplist
(car oplist)   ; + operator
((car oplist) 1 2 3 4) ; +
((cadr oplist) 1 2 3 4) ; -
((car (cdr (cdr oplist))) 10 11 12) ; *


