#lang scheme

"Currying"
(define subtract
  (lambda (a b)
    (- a b)))
(subtract 13 7)
(subtract 40 6)
(subtract 40 13)

(define subtract-curr
  (lambda (a)
    (lambda (b)
      (subtract a b))))
((subtract-curr 13) 7)
((subtract-curr 40) 6)
((subtract-curr 40) 13)
(define subtract-from-40
  (lambda (x)
    ((subtract-curr 40) x)))
(subtract-from-40 6)
(subtract-from-40 13)
(subtract-from-40 78)

(newline)
"Secret number game"
(define secret-num
  (lambda (secret guess)
    (= secret guess)))
(secret-num 10 5)
(secret-num 10 10)

; secret-num-curr returns a function with only 1 argument - the guess
(define secret-num-curr
  (lambda (secret)
    (lambda (guess)
      (secret-num secret guess))))
(secret-num-curr 10)
(define guessing-game (secret-num-curr 17))
(guessing-game 5)
(guessing-game 10)
(guessing-game 17)

(newline)
"More examples"
(define in-range
  (lambda (min max)
    (lambda (x)
      (and (>= x min) (<= x max)))))
(define lst '(-4 7 1 43 17 12 20 9 26 15 64 8 42 -8))
(filter (in-range 10 50) lst)
(filter (in-range 0 20) lst)

(define increase
  (lambda (n)
    (lambda (x)
      (+ x n))))
(map (increase 10) lst)
(map (increase -1) lst)


(newline)
"Define a polynomial function"
(define quad
  (lambda (a b c)
    (lambda (x)
      (+ (* a x x) (* b x) c))))
(quad 1 1 1)
((quad 1 1 1) 3)
(define f1 (quad 1 1 1))             ; f(x) = x^2 + x + 1
(define f2 (quad 1 2 3))             ; f(x) = x^2 + 2x + 3
(define f3 (quad 2 4 2))             ; f(x) = 2x^2 + 4x + 2
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