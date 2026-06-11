#lang scheme

; Define a list of numbers to work with.
(define lst '(4 8 15 16 23 42 16))

; car gives the first item in a list
(car lst)

; cdr gives the rest of the list
(cdr lst)

; cons creates a new list by adding one item to the front
(cons 'lost lst)

; This procedure replaces all occurrences of old with new in a list.
;   Base case: If the list is empty, return an empty list.
;   Recursive case: If the first item is old, replace it with new and
;                   recursively process the rest of the list. Otherwise,
;                   keep the first item and recursively process the rest.
(define replace
  (lambda (lst old new)
    (cond
      ((empty? lst) '())
      ((= (car lst) old)
         (cons new (replace (cdr lst) old new)))
      (else
         (cons (car lst) (replace (cdr lst) old new))))))

(newline)
"replace testing"
(replace lst 16 26)
(replace lst -1 10)