#lang scheme

; A Scheme form is something that you as Scheme to evaluate

1
"Hello, world!"
(+ 1 2)
(+ 1 2 3 4)
(- 1 (- 3 2) (+ -4 5))

; Comments start with a semicolon
#; (Comment out an entire form)
#; (define i-am-ignored
     (lambda(x)
       (* x 0)))

(define mynumber 10)
(define myname "Wade")
(+ mynumber 6)
(string? myname)
(define 1#$#&%FV 5)
(+ 1#$#&%FV 10)

(newline)
"Data Types"
1              ; integer
3.4            ; real numbers
"Hello, World" ; string
*              ; primative
#t             ; boolean
#f             ; boolean
#\A            ; characters

(newline)
"Symbols & Strings"
(symbol? "Hello")
(symbol? 'World)
(string? "Hello")
(string? 'World)
(symbol->string 'hello)
(string->symbol "World")
(symbol? 5)
(symbol? '5)
(symbol? '1TwoIII)

(newline)
"Numeric data types:"
3              ; integer
#b101          ; binary
#o101          ; octal
#x101          ; hexidecimal
12.3           ; real
7/3            ; fractions
4+2i           ; imaginary

(newline)
"Number predicates"
(integer? 3)
(integer? 3.0)
(integer? 3.1)
(integer? (* 3 1/3))
(integer? (* 3 (/ 1 3)))

"Real"
(real? 3)
(real? 3.0)
(real? 2+i)
(real? 2+0i)

"Other"
(rational? 1/3)
(complex? 2+i)
(complex? 2+0i)
(complex? 2)
(rational? 2+0i)
(number? 3)
(number? 2+i)
(number? (car '(8 10 5)))
(number? "One")
(number? 'Two)
(number? '3)

(newline)
"Math"
(+ 10 10)
(* 10 10)
(+ 1 2)
(* 3 4)
(- 1)
(- -1)
(+ 1 2 3 4 5 7 8 9 10)
(* 1 2 3 4 5 7 8 9 10)
(- 1 2 3 4 5 7 8 9 10)
(/ 100 2 5)
(* (/ (* 7 (- 8 2)) (/ (* 6 3) (* 2 3 2 (/ 1 2)))) 2)
(sqrt 9)
(sqrt 20)
(sqrt -1)
(/ 17 3)
(/ 17 3.0)
(quotient 17 3)
(remainder 17 3)
(* 143843843 28432843284328 4382423843284328432 48324243432432432432423432432423414419938384328)

(newline)
"Define x, y, z"
(define x 10)
(define y 20)
(define (z) 30)
x
y
z
(z)
(+ 2 x)
(+ x 2)
(* x (/ y 6))
(= x 12)
(< x 12)
(= 30 (z))
(= x (+ 15 -5))
(> x (* y 3))

(newline)
"Checking equality"
(define num 8)
"="
(= 32 32)
(= 32 (* 4 num))
(= 8 num)
"eq?"
(eq? 32 32)
(eq? 32 (* 4 num))
(eq? 8 num)
(eq? 'Hello 'Hello)
(eq? "World" "World")
(eq? "CSC" (symbol->string 'CSC))
(eq? '(1 2 3) '(1 2 3))
(eq? 8 (+  2 3 3))
(eq? num (+  2 3 3))
"equal?"
(equal? 32 32)
(equal? 32 (* 4 num))
(equal? 8 num)
(equal? 'Hello 'Hello)
(equal? "World" "World")
(equal? "CSC" (symbol->string 'CSC))
(equal? '(1 2 3) '(1 2 3))
(equal? 8 (+  2 3 3))
(equal? num (+  2 3 3))