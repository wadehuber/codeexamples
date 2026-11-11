#lang scheme

; Towers of Hanoi - move n disks from source to destination, one at a time,
; never placing a larger disk on a smaller one.
;
; This version is PURE: it does not print anything. It RETURNS a list of
; moves, and whoever calls it decides what to do with that list.

"Hanoi - returns a (nested) list of moves"
; Requires n >= 1. The base case is n = 1, so (hanoi 0 ...) would recur on
; -1, -2, ... and never stop. The flat version below stops at n <= 0, so it
; also accepts 0 (and returns the empty list of moves) and cannot run away
; on a negative number.
(define hanoi
  (lambda (n source center destination)
    (if (= n 1)  ; stopping condition
        (list 'Move source destination)
        (list
         (hanoi (- n 1) source destination center)
         (hanoi 1 source center destination)
         (hanoi (- n 1) center source destination)))))
(hanoi 2 'red 'middle 'blue)
(hanoi 3 'red 'middle 'blue)

(newline)
"A flat version - each move is one list, appended together"
(define hanoi-moves
  (lambda (n source center destination)
    (if (<= n 0)
        '()
        (append
         (hanoi-moves (- n 1) source destination center)
         (list (list source destination))
         (hanoi-moves (- n 1) center source destination)))))
(hanoi-moves 3 'red 'middle 'blue)

(newline)
"Because the result is a value, we can compute with it"
(length (hanoi-moves 3 'red 'middle 'blue))      ; 2^3 - 1 = 7
(length (hanoi-moves 10 'red 'middle 'blue))     ; 2^10 - 1 = 1023
(car (hanoi-moves 4 'red 'middle 'blue))         ; just the first move
