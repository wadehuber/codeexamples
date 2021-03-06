#lang scheme

"Advanced topics - not required for project or final"
"case-lambda"
(define hello
  (case-lambda
    (() "Hello, world!")
    ((name) (string-append "Hello, " name))))
(hello)
(hello "John")

(newline)
"match"
(list (remainder 20 2) (remainder 20 5))
(list (remainder 15 2) (remainder 15 5))
(list (remainder 17 2) (remainder 17 5))
(list (remainder 8 2) (remainder 8 5))
(define multiple-of-2-and-5
  (lambda (n)
    (match (list (remainder n 2) (remainder n 5))
      ((list 0 0) "Divisible by 2 and 5")  ; both remainders are 0
      ((list 0 _) "Divisible only by 2")   ; only divisible by 2
      ((list _ 0) "Divisible only by 5")   ; only divisible by 5
      (_ "Not divisible by 2 or 5"))))
(multiple-of-2-and-5 20)
(multiple-of-2-and-5 15)               
(multiple-of-2-and-5 17)
(multiple-of-2-and-5 8)
