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
(red + 0 '(1 2 3 4))
(red * 1 '(1 2 3 4))

(define sum-all
  (lambda (lst)
    (red + 0 lst)))
(define mult-all
  (lambda (lst)
    (red * 1 lst)))
(sum-all '(1 2 3 4))
(mult-all '(1 2 3 4))

(define double-list
  (lambda (lst)
    (red (lambda (x y) (cons (* 2 x) y)) '() lst)))
(double-list '(1 2 3 4))

(newline)
"length"
(red (lambda (x y) (+ 1 y)) 0 '(1 2 3 4))
"square list"
(red (lambda (x y) (cons (* x x) y)) '() '(1 2 3 4))
"get all odd values"
(red (lambda (x y) (if (= 0 (remainder x 2)) y (cons x y))) '() '(1 2 3 4))
"reverse"
(red (lambda (x y) (append y (list x))) '() '(1 2 3 4))

(define lst '(1 2 3 4 5 6 7 8 9 10 11 12 13))
(define lstn '(0 -1 2 -3 4 -5 6 -7 8 -9 10 -11 12 -13))
(define badlst (list "CGCC" 1 'a + 10 'hello lst '(1 2 3) '(a . b) red 8 6 -3))
