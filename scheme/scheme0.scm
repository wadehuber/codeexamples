#lang scheme

; Comments start with a semi-colon

; Clicking "Run" in DrRacket will evaluate your program

; Literals
"Hello, World"   ; String
10               ; Integer
3.14             ; Real
'HelloWorld      ; Symbol

; Scheme uses prefix notation: the operator comes first
(+ 1 2)
(sqrt (+ (* 3 3) (* 4 4)))   ; square root of (3 * 3) + (4 * 4)

; Associate the value 5 with the name "x"
(define x 5)
(* 2 x)

; Define a new function
(define half-it
  (lambda (x)
    (/ x 2)))
(half-it 4)

; Lists
(list 1 2 3 4)
(define lst '(1 2 3 4))  ; The quote tells Scheme not to evaluate what is in parenthesis
lst
(append (list 1 2 3) '(a b c))

