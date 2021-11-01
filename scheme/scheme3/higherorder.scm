#lang scheme

(define increment (lambda (x) (+ x 1)))
(define lst '(1 2 3 4 5 6 7 8 9 10 11 12 13))
(define lstn '(0 -1 2 -3 4 -5 6 -7 8 -9 10 -11 12 -13))
(define badlst (list "CGCC" 1 'a + 10 'hello lst '(1 2 3) '(a . b) increment 8 6 -3))

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
(map (lambda (x) (if (> x 0) x (* -1 x))) lstn)
(map (lambda (x) (if (odd? x) (* x x) (/ x 2))) lstn)
(map even? lst)
(map (lambda (x) (if (>= x 0) #t #f)) lst)
(map (lambda (x) (if (>= x 0) #t #f)) lstn)

(newline)
"Higher-order functions - filter"
(filter even? lst)
(filter negative? lstn)
(filter string? badlst)
(filter pair? badlst)
(filter number? badlst)
(filter (lambda (x) (if (>= x 0) #t #f)) lst)
(filter (lambda (x) (if (>= x 0) #t #f)) lstn)
(filter (lambda (x) (not (pair? x))) badlst)

(newline)
"Combining higher-order functions"
(map (lambda (x) (* x x)) (filter number? badlst))
(apply + (map (lambda (x) (* x x)) (filter number? badlst)))

; function to calculate the sum of the squares of numbers in a list
(define sum-num-square
  (lambda (lst)
    (apply + (map (lambda (x) (* x x)) (filter number? lst)))))
(sum-num-square lst)
(sum-num-square badlst)
(sum-num-square '(a b 3 4 "blah" 'CSC240 17 99 + 18))