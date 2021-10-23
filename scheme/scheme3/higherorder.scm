#lang scheme
(define increment (lambda (x) (+ x 1)))
(define add (lambda (x y) (+ x y)))
(define lst '(1 2 3 4 5 6 7 8 9 10 11 12 13))
(define lstn '(0 -1 2 -3 4 -5 6 -7 8 -9 10 -11 12 -13))
(define badlst (list "CGCC" 1 'a + 10 'hello lst '(1 2 3) '(a . b) increment 8 6 -3))

"Higher-order function"
(define hord-example
  (lambda (func param)
    (func param)))
(hord-example increment 7)
(hord-example symbol->string 'HigherOrderFTW)
(hord-example even? 8)

(define hord-example2
  (lambda (func param1 param2)
    (func param1 param2)))
(hord-example2 + 23 19)
(hord-example2 max 421 65000)
(hord-example2 cons 'higher 'order)

(newline)
"Higher-order functions - apply"
(apply + lst)
(apply + lstn)
(apply * lst)
(apply * lstn)

(newline)
"Higher-order functions - map"
(map increment lst)
(map increment lstn)
(map (lambda (x) (* x x)) lst)
(map (lambda (x) (* x x)) lstn)
(map (lambda (x) (if (> x 0) x (* -1 x))) lstn)
(map (lambda (x) (if (>= x 0) #t #f)) lstn)
(map pair? badlst)
(map string? badlst)

(newline)
"Higher-order functions - filter"
(filter pair? badlst)
(filter string? badlst)
(filter number? badlst)
(filter (lambda (x) (if (>= x 0) #t #f)) lstn)
(filter (lambda (x) (not (pair? x))) badlst)

(newline)
"combining higher-order functions)"
(map (lambda (x) (* x x)) (filter number? badlst))
(apply + (map (lambda (x) (* x x)) (filter number? badlst)))

; function to calculate the sum of the squares of numbers in a list
(define sum-num-square
  (lambda (lst)
    (apply + (map (lambda (x) (* x x)) (filter number? lst)))))
(sum-num-square lst)
(sum-num-square badlst)