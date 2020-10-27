#lang scheme
; Introduction to Scheme Pairs

(define a 5)
(define b 6)

"Pairs"
(cons 0 2)
(cons 'a 'b)
(cons a b)
'(10 . 20)
(quote (x . y))
(pair? (cons 0 2))
(pair? '(a . b))

(newline)
"Parts of a pair"
(car (cons 'a 'b))
(cdr (cons 'a 'b))
(car '(3 . 4))
(cdr '(3 . 4))

(newline)
"Pairs vs Lists"
(cons 'a '())
(cons 'a (cons 'b '()))
'(a . ())
(pair? '(a . ()))
(list? '(a . ()))
(pair? (cons 0 2))
(pair? (cons 0 '(2)))
(list? (cons 0 2))
(list? (cons 0 '(2)))
(pair? '())
(list? '())
(pair? '(1 2 3))

(cons 1 (cons 2 (cons 3 '()))) ; (1 2 3)

(define pair0 (cons a b))        ; (a . b)
(define pair1 (cons a '()))      ; (a . ())
(define pair2 (cons a (list b))) ; (a . (b)) -> (a . (b . ())
pair0
pair1
pair2
(car pair0)
(cdr pair0)
(car pair1)
(cdr pair1)
(car pair2)
(cdr pair2)

"Applications of pairs"
'(30 . 90)   ; latitude & longitude
'(neworleans . (30 . 90))
'(phoenix . (33 . 122))
'(chicago . (42 . 87))
(define cities '((neworleans . (30 . 90)) (phoenix . (33 . 122)) (chicago . (42 . 87))))
(define city-location
  (lambda (x)
    (cdr x)))
(define city-latitude
  (lambda (x)
    (cadr x)))
(define city-longitude
  (lambda (x)
    (cddr x)))

(define city-info
  (lambda (cities city)
    (if (null? cities)
        '()
        (if (eq? (caar cities) city)
            (city-location (car cities))
            (city-info (cdr cities) city)))))

