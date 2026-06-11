
; namedprocedures.scm
;
; In Scheme, procedures are first-class values.
; That means procedures can be:
;   - stored in names
;   - passed as arguments
;   - returned from other procedures
;
; A lambda expression creates a procedure.
; define gives a name to a value.

(define square
  (lambda (x)
    (* x x)))

(define double
  (lambda (x)
    (* x 2)))

(display (square 5))
(display (double 10))

; There is a shorter "named procedure" form. It means essentially the same thing as:
;   (define add-one
;     (lambda (x)
;       (+ x 1)))
; This form is convenient, but the lambda form makes it clearer
; that a procedure is a value being assigned to a name.
(define (add-one x)
  (+ x 1))

; This procedure takes another procedure as an argument.
; That helps show that procedures are first-class values.
(define apply-twice
  (lambda (f x)
    (f (f x))))

(display (add-one 7))
(display (apply-twice square 3))
(display (apply-twice double 4))
(display (apply-twice add-one 10))
