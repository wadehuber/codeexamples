#lang scheme

; Recursive list procedures. Every one follows the same pattern:
;   1. Is the list empty?  -> base case
;   2. Otherwise, do something with (car lst) and recur on (cdr lst)

(define lst '(apple banana cherry banana date))

"member? - is an element in the list?"
(define member?
  (lambda (ele lst)
    (cond
      ((null? lst) #f)
      ((equal? (car lst) ele) #t)
      (else (member? ele (cdr lst))))))
(member? 'cherry lst)
(member? 'kiwi lst)

(newline)
"rember - remove the FIRST occurrence of an element - The Little Schemer"
(define rember
  (lambda (ele lst)
    (cond
      ((null? lst) '())
      ((equal? (car lst) ele) (cdr lst))
      (else (cons (car lst) (rember ele (cdr lst)))))))
(rember 'banana lst)
(rember 'kiwi lst)

(newline)
"count-of - how many times does an element appear?"
(define count-of
  (lambda (ele lst)
    (cond
      ((null? lst) 0)
      ((equal? (car lst) ele) (+ 1 (count-of ele (cdr lst))))
      (else (count-of ele (cdr lst))))))
(count-of 'banana lst)
(count-of 'kiwi lst)

(newline)
"Lists can hold any type - including other lists"
(define mixed (list 3 'hello "World" 7.5 '(1 2)))
(member? '(1 2) mixed)
(rember "World" mixed)
