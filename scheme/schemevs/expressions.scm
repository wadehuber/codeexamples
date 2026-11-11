#lang scheme

; Almost everything in Scheme is an expression that evaluates to a value.
; There are no statements - even if and cond produce values.
; (define is the one exception: it names a value instead of producing one.)

"Prefix notation - the operator comes first"
(+ 3 4)
(* (+ 2 3) (- 10 4))
(- 14 (* 2 6))        ; no precedence rules needed - the parentheses say it all

(newline)
"if is an expression - it evaluates to a value"
(define x -7)
(if (> x 0) x (- x))                        ; absolute value of x
(* 10 (if (> x 0) x (- x)))                 ; so we can use it anywhere a value goes

(newline)
"cond is an expression too"
(define grade
  (lambda (score)
    (cond
      ((>= score 90) 'A)
      ((>= score 80) 'B)
      ((>= score 70) 'C)
      (else 'F))))
(grade 95)
(grade 72)
(list (grade 88) (grade 91) (grade 40))     ; the result of cond can go straight into a list

(newline)
"Composition - the output of one function is the input to the next"
(define square (lambda (n) (* n n)))
(define add1 (lambda (n) (+ n 1)))
(define half (lambda (n) (/ n 2)))

; No temporary variables - values flow from the inside out
(half (square (add1 5)))                    ; (6 * 6) / 2 = 18

(newline)
"Careful - / on integers gives an EXACT rational in Scheme"
(half 3)                                    ; 3/2, not 1 (Java and C++ give 1)
(half 3.0)                                  ; 1.5
