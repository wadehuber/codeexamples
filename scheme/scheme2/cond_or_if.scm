#lang scheme

(define half-even-if
  (lambda (n)
    (if (= 0 (remainder n 2))
        (/ n 2)
        n)))

(half-even-if 42)
(half-even-if 45)

(define half-even-cond
  (lambda (n)
    (cond
      ((= 0 (remainder n 2)) (/ n 2))
      (else n))))
(half-even-cond 42)
(half-even-cond 45)

(define example2-if
  (lambda (n)
    (if (< n 0)
        (* n -1)
        (if (= 1 (remainder n 2))
            (+ n 1)
            n))))
(half-even-cond -10)
(half-even-cond 10)
(half-even-cond 11)