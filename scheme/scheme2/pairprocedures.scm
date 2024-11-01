#lang scheme

(define pair1 (cons 1 2))
(define pair2 (cons 'a 'z))
(define pair3 '(car cdr))

(newline)
"pair procedures"
(define in-order-pair?
  (lambda (pr)
    (>= (cdr pr) (car pr))))
(in-order-pair? '(3 . 2))
(in-order-pair? '(2 . 3))
(in-order-pair? '(3 . 3))
(in-order-pair? pair1)

(define raise-to-power
  (lambda (pr)
    (expt (car pr) (cdr pr))))
(raise-to-power '(3 . 2))
(raise-to-power '(2 . 3))
(raise-to-power '(3 . 3))
(raise-to-power pair1)

(define multiply-by
  (lambda (pr)
    (if (null? (car pr))
        '()
        (cons (* (car (car pr)) (cdr pr)) (multiply-by (cons (cdr (car pr)) (cdr pr)))))))