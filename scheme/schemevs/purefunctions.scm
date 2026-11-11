#lang scheme

; Pure functions & referential transparency

"A pure function - same input, same output, no side effects"
(define square
  (lambda (x)
    (* x x)))
(square 5)
(square 5)              ; always 25, no matter when or how often we call it

; Referential transparency: we can replace (square 5) with 25 anywhere
(+ (square 5) (square 5))
(* 2 (square 5))        ; same answer - the algebra works

(newline)
"An IMPURE function - for comparison only (set! is not functional!)"
; set! changes the value of an existing name. This is a side effect,
; and you should never use it in your assignments for this class.
(define count 0)
(define f
  (lambda (x)
    (set! count (+ count 1))
    (+ x count)))

(+ (f 10) (f 10))       ; 11 + 12 = 23
(* 2 (f 10))            ; 2 * 13 = 26  -- the algebra is broken. Even starting
                        ; over from count = 0 it would be 2 * 11 = 22, not 23
(f 10)                  ; 14 - same input, different output every time

(newline)
"Side effects make the ORDER of evaluation matter"
; Racket evaluates arguments left to right, so this is 15 - 16 = -1.
; Standard Scheme does not promise an order; right to left would give 1.
(- (f 10) (f 10))

(newline)
"The functional fix - make the hidden state an explicit parameter"
(define f-pure
  (lambda (x count)
    (+ x count)))
(+ (f-pure 10 1) (f-pure 10 1))
(* 2 (f-pure 10 1))     ; equal again
