#lang scheme
(define x 10)
(define y 17)
(define z 15)

"and"
(and #f #f)
(and #t #f)
(and #f #t)
(and #t #t)

(newline)
"or"
(or #f #f)
(or #t #f)
(or #f #t)
(or #t #t)

(newline)
"xor"
(xor #f #f)
(xor #t #f)
(xor #f #t)
(xor #t #t)

(newline)
"not"
(not #f)
(not #t)

(newline)
"Using boolean operators in Scheme"
(and (> x 8) (< y 20))
(and (< x 8) (< y 20))
(and (> x 8) (< y 20) (= 0 (remainder z 3)))
(and (> x 8) (< y 20) (= 0 (remainder z 3)) #f)
(and (> x 8) (< y 20) (= 0 (remainder z 3)) #t)
(or (> x 8) (< y 20))
(or (< x 8) (< y 20))