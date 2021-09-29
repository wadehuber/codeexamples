#lang scheme

(define increment
  (lambda (x)
    (+ x 1)))

(define triple
  (lambda (x)
    (* x 3)))

"Original lists"
(define lst1 '(1 2 3 4 5 6 7 8 9 10))
(define lst2 '(4 8 15 16 23 42))
(define lst3 '(7 -12 33 17 -8 45 9 -73 -3 8 99))
lst1
lst2
lst3

(newline)
"Implementing Map"
(define map-r
  (lambda (fun lst)
    (if (null? lst)
        '()
        (cons (fun (car lst)) (map-r fun (cdr lst))))))

"testing map"
(map triple lst1)
(map increment lst2)
(map (lambda (x) (if (> x 0) x (- x))) lst3)

"testing map-r"
(map-r triple lst1)
(map-r increment lst2)
(map-r (lambda (x) (if (> x 0) x (- x))) lst3)

(newline)
"Implementing Apply"
(define apply-r
  (lambda (fun lst)
    (cond
      ((= (length lst) 1) (car lst))
      ((> (length lst) 1) (fun (car lst) (apply-r fun (cdr lst)))))))
      
"testing apply"
(apply + lst1)
(apply + lst2)
(apply + lst3)
(apply * lst1)
(apply * lst2)
(apply * lst3)

"testing apply-r"
(apply-r + lst1)
(apply-r + lst2)
(apply-r + lst3)
(apply-r * lst1)
(apply-r * lst2)
(apply-r * lst3)

(newline)
"Implementing Filter"

(define filter-r
  (lambda (fun lst)
    (cond
      ((null? lst) '())
      ((fun (car lst)) (cons (car lst) (filter-r fun (cdr lst))))
      (else (filter fun (cdr lst))))))

"testing filter"
(filter even? lst1)
(filter positive? lst2)
(filter (lambda (x) (> x 10)) lst3)


"testing filter-r"
(filter-r even? lst1)
(filter-r positive? lst2)
(filter-r (lambda (x) (> x 10)) lst3)