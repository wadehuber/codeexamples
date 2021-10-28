#lang scheme

"Equality checking in Scheme"
(define lstx '(1 2 3))
(define lsty '(1 2 3))
(define empty-list '())
(define hstr "Hello")

"="
(= 3 3)
(= 9 8)
(= 6 (* 2 3))
(= 6 '6)
;(= 6 "6")

(newline)
"eq?"
(eq? 1 1)
(eq? '2 2)
(eq? 1 "1")
(eq? '1 (car '(1 2 3)))
(eq? '(2 3) (cdr '(1 2 3)))
(eq? lstx lsty)
(eq? empty-list '())
(eq? empty-list '())
(eq? "Hello" (symbol->string 'Hello))

(newline)
"string=?"
(string=? "Hello" "World")
(string=? hstr "Hello")
(string=? "World" "World")
(string=? "Hello" (symbol->string 'Hello))
;(string=? "Hello" 'World)

(newline)
"equal?"
(equal? 3 3)
(equal? 9 8)
(equal? 6 (* 2 3))
(equal? 1 "1")
(equal? '1 (car '(1 2 3)))
(equal? '(2 3) (cdr '(1 2 3)))
(equal? lstx lsty)
(equal? empty-list '())
(equal? "Hello" (symbol->string 'Hello))
(equal? '(1 . 2) '(1 . 2))
(equal? '() (cdr '(1)))
(equal? '(1 2 (3 (4 5) 6) 7) '(1 2 (3 (4 5) 6) 7))
(equal? '(1 2 (3 (4 5) 6) 7) '(1 2 3 4 5 6 7))
