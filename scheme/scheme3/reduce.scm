#lang scheme

"Multiply-all"
(define multiply-all
  (lambda (lst)
    (if (null? lst)
        1
        (* (car lst) (multiply-all (cdr lst))))))
(multiply-all '(1 2 3 4))

(newline)
"Reduce"
(define red
  (lambda (operator base-case lst)
    (if (null? lst)
        base-case
        (operator (car lst) (red operator base-case (cdr lst))))))
"Apply + or * to the list"
(red + 0 '(1 2 3 4))
(red * 1 '(1 2 3 4))

"Map square to each member of the list"
(define square (lambda (x) (* x x)))
(red (lambda (ca rcd) (cons (square ca) rcd)) '() '(1 2 3 4))

"Filter for odd"
(define odd? (lambda (x) (= 1 (remainder x 2))))
(red (lambda (x y) (if (odd? x) (cons x y) y)) '() '(1 2 3 4))

(newline)
"Define procedures using reduce"
"sum-all & mult-all"
(define sum-all
  (lambda (lst)
    (red + 0 lst)))
(define mult-all
  (lambda (lst)
    (red * 1 lst)))
(sum-all '(1 2 3 4))
(mult-all '(1 2 3 4))

"Double each element in a list"
(define double-list
  (lambda (lst)
    (red (lambda (x y) (cons (* 2 x) y)) '() lst)))
(double-list '(1 2 3 4))

(newline)
"Length of a list"
(red (lambda (x y) (+ 1 y)) 0 '(1 2 3 4 5 6))
"Reverse"
(red (lambda (x y) (append y (list x))) '() '(a b c d e))