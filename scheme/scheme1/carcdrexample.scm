#lang scheme
(define lst '(this is (a (scheme list) with (several) (symbols (in (it)))) end))
(car lst)
(car (cdr lst))
"(a (scheme list) with (several) (symbols (in (it))))"
(car (cdr (cdr lst)))
(car (car (cdr (cdr lst))))
(car (car (cdr (car (cdr (cdr lst))))))
(car (cdr (car (cdr (car (cdr (cdr lst)))))))
(car (cdr (cdr (car (cdr (cdr lst))))))
(car (car (cdr (cdr (cdr (car (cdr (cdr lst))))))))
"(symbols (in (it)))"
(car (cdr (cdr (cdr (cdr (car (cdr (cdr lst))))))))
(car (car (cdr (cdr (cdr (cdr (car (cdr (cdr lst)))))))))
(car (car (cdr (car (cdr (cdr (cdr (cdr (car (cdr (cdr lst)))))))))))
(car (car (cdr (car (cdr (car (cdr (cdr (cdr (cdr (car (cdr (cdr lst)))))))))))))
(car (cdr (cdr (cdr lst))))
