#lang scheme
(define list1 '(1 2 3 4 5 6))
(define list2 '(1 2 3 4 5 6 7))
; Too many things in the same line
(define has-an-odd-wrong
  (lambda (x)
    (cond
      ((null? x) #f)
      ((odd? (car x)) #t (has-an-odd-wrong (cdr x)))
      (else (has-an-odd-wrong (cdr x))))))
(has-an-odd-wrong list1)
(has-an-odd-wrong list2)

; Too many parenthesis in output
(define duplicate-elements-wrong
   (lambda (x)
     (if (null? x)
         '()
         (if (pair? x)
             ((append (duplicate-elements-wrong (car x))
                     (duplicate-elements-wrong (cdr x))))
             (list (x x))))))
(duplicate-elements-wrong list1)
