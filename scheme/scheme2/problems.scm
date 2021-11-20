#lang scheme

(define list1 '(1 2 3 4 5 6))
(define list2 '(1 2 3 4 5 6 7))
list1
list2

(newline)
"count-up-to"
(define count-up-to
  (lambda (x)
    (if (= x 0)
        '()
        ; (cons (count-up-to (- x 1)) x)))) ; cons makes a pair
        ; (append (count-up-to (- x 1)) x)))) ; append takes a list
        (append (count-up-to (- x 1)) (list x)))))
(count-up-to 5)

(newline)
"has-an-even-wrong"
(define has-an-even-wrong
  (lambda (x)
    (if (null? x)
        #f
        (if (even? (car x))
            ; #t)   Bad parenthesis
            #t
            (has-an-even-wrong (cdr x))))))
(has-an-even-wrong list1)
(has-an-even-wrong list2)

(newline)
"has-an-odd-wrong"
(define has-an-odd-wrong
  (lambda (x)
    (cond
      ((null? x) #f)
      ;((odd? (car x)) #t (has-an-odd-wrong (cdr x))) ; the #t gets ignored
      ((odd? (car x)) #t)
      (else (has-an-odd-wrong (cdr x))))))
(has-an-odd-wrong list1)
(has-an-odd-wrong list2)

(newline)
"has-an-odd-wrong"
(define duplicate-elements-wrong
   (lambda (x)
     (if (null? x)
         '()
         (if (pair? x)
             ;((append (duplicate-elements-wrong (car x)))  ; extra parenthesis 
             (append (duplicate-elements-wrong (car x)) 
                     (duplicate-elements-wrong (cdr x)))
             ; (list (x x))))))   ; tries to evaluate (x x)
             ; (quote (x x))))))  ; does not evaluate x
             (list x x)))))       ; makes a list with the value of x
(duplicate-elements-wrong list1)
(duplicate-elements-wrong list2)
(duplicate-elements-wrong '(1 (2 3) (4 (5) 6)))

