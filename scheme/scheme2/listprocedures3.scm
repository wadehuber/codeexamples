#lang scheme

"gen-number-list"
(define gen-number-list
  (lambda (start end)
    (if (>= start end)
        (list start)
        (cons start (gen-number-list (+ start 1) end)))))
(gen-number-list 1 10)
(gen-number-list 100 120)
(gen-number-list 50 40)

(newline)
"triple-list"
(define triple-list
  (lambda (lst)
    (if (null? lst)
        '()
        (cons (* (car lst) 3) (triple-list (cdr lst))))))
(triple-list '(1 2 3 4 5))
(triple-list (gen-number-list 45 50))
(triple-list '(-20 37 934 84 32 734))

(newline)
"grade->letter"
(define letter-grade
  (lambda (grade)
    (cond
      ((>= grade 900) 'A)
      ((>= grade 800) 'B)
      ((>= grade 700) 'C)
      ((>= grade 600) 'D)
      (else 'F))))

(define grade->letter
  (lambda (gradelst)
    (if (null? gradelst)
        '()
        (cons (letter-grade (car gradelst)) (grade->letter (cdr gradelst))))))
(grade->letter '(848 939 777 896 620 957 1032 893))