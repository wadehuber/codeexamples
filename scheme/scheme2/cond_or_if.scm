#lang scheme

"Example 1a - 2 conditions using if"
(define half-even-if
  (lambda (n)
    (if (= 0 (remainder n 2))
        (/ n 2)
        n)))

(half-even-if 42)
(half-even-if 45)

"Example 1b - 2 conditions using cond"
(define half-even-cond
  (lambda (n)
    (cond
      ((= 0 (remainder n 2)) (/ n 2))
      (else n))))
(half-even-cond 42)
(half-even-cond 45)

"Example 2a - 3 conditions using cond"
(define example2-cond
  (lambda (n)
    (cond
      ((< n ) (* n -1))
      ((= 1 (remainder n 2)) (+ n 1))
      (else n))))
(example2-cond -10)
(example2-cond 10)
(example2-cond 11)

(newline)
"Example 2a - 3 conditions using if"
(define example2-if
  (lambda (n)
    (if (< n 0)
        (* n -1)
        (if (= 1 (remainder n 2))
            (+ n 1)
            n))))
(example2-if -10)
(example2-if 10)
(example2-if 11)
