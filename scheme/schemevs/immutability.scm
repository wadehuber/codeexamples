#lang scheme

; Immutability - we never change a list, we build a new one.
;
; In Racket's #lang scheme (the language used throughout this course), pairs
; made with cons are IMMUTABLE - there is no set-car! or set-cdr!. Racket keeps
; mutable pairs as a separate type (mcons). Standard Scheme (R5RS/R7RS) is
; different: its ordinary pairs CAN be changed with set-car! and set-cdr!.

(define lst '(1 2 3 4 5))

"Double each element - returns a NEW list"
(define double-list
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (* 2 (car lst)) (double-list (cdr lst))))))
(double-list lst)
lst                              ; the original is untouched

(newline)
"Adding to the front with cons - also a new list"
(define lst2 (cons 0 lst))
lst2
lst                              ; still (1 2 3 4 5)

(newline)
"Structural sharing - the new list REUSES the old one"
; lst2 doesn't copy lst. Its cdr IS lst - the same pairs in memory.
; That is only safe because nobody can ever change lst (in this dialect).
(eq? (cdr lst2) lst)

(newline)
"Insert into a sorted list - returns a new sorted list"
(define insert-sorted
  (lambda (n lst)
    (cond
      ((null? lst) (list n))
      ((<= n (car lst)) (cons n lst))
      (else (cons (car lst) (insert-sorted n (cdr lst)))))))
(insert-sorted 3 '(1 2 4 5))
(insert-sorted 0 lst)
(insert-sorted 9 lst)
lst                              ; still (1 2 3 4 5)
