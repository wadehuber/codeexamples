#lang scheme

"Currying"
(define secret-num
  (lambda (secret guess)
    (= secret guess)))
(secret-num 10 5)
(secret-num 10 10)

; secret-num-curr returns a function with only 1 arguement (the guess)
(define secret-num-curr
  (lambda (secret)
    (lambda (guess)
      (= secret guess))))
(secret-num-curr 10)
(define guessing-game (secret-num-curr 10))
guessing-game
(guessing-game 5)
(guessing-game 10)

(define in-range
  (lambda (min max)
    (lambda (x)
      (and (>= x min) (<= x max)))))
(filter (in-range 10 20) '(1 8 43 17 9 12 20 26 64 15))

(define increase
  (lambda (n)
    (lambda (x)
      (+ x n))))
(map (increase 10) '(1 2 3 4))

(newline)
"Define a polynomial"
(define quad
  (lambda (a b c)
    (lambda (x)
      (+ (* a x x) (* b x) c))))
(quad 1 1 1) 3
((quad 1 1 1) 3)
(define f1 (quad 1 1 1))   ; f(x) = x^2 + x + 1
(define f2 (quad 1 2 3))   ; f(x) = x^2 + 2x + 3
(define f3 (quad 2 4 2))   ; f(x) = 2x^2 + 4x + 2
(define f4 (quad 1 (/ 1 2) (/ 1 4))) ; f(x) = x^2 + 1/2 x + 1/4
f1
(f1 2)
(f1 -2)
(f2 2)
(f2 -2)
(f3 2)
(f3 -2)
(f4 2)
(f4 -2)
