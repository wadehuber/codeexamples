#lang scheme

; Imperative style:
;   x = something
;   y = change(x)
;   result = calculate(y)

; Functional style:
;   calculate(change(something))

(define x 10)
(define y 20)

"Defining procedures"
(* 3 x)    ; Scheme form
(lambda (x) (* 3 x))  ; unamed procedure
((lambda (x) (* 3 x)) 5)
((lambda (x) (* 3 x)) x)
(define trip   ; define associates a name with a form
  (lambda (x)  ; lambda defines a procedure
    (* 3 x)))  ; thisform associates the name "trip" to the lambda expression
trip
(trip 5)
(trip x)

(newline)
"Define a predicate to check if a value is an atom"
(define atom?
  (lambda (x)
    (and (not (pair? x)) (not (null? x)))))
(atom? 3)
(atom? "Atom")
(atom? 'Atom)
(atom? (cons 1 2))
(atom? (list 1 2 3))

"Define a procedure with 2 paramters"
(define addem
  (lambda (a b)
    (+ a b)))
addem
(addem x y)
(addem 10 (addem 20 30))

"Increment function"
(define increment
  (lambda (x)
    (+ x 1)))
(increment 8)
(increment (increment (increment (increment 0))))

(newline)
"Function as a parameter"
(define do
  (lambda (this that)
    (this that)))
(do increment 10)
(do - 20)
(do trip 27)
(do integer? 8)
(do (lambda (x) (* x (+ x 1))) 3)
;(do 10 20)     ; 10 is not a procedure
;(do addem 1)   ; airity mismatch - addem takes 2 parameters
(do (lambda (x) (addem x 100)) 1)

(newline)
"Conditionals"
(if (> 3 2) 'bigger 'smaller)
(if (< 3 2) 'bigger 'smaller)
(if (= x 10) (+ x 5) (do trip x))
(if (= x 12) (+ x 5) (do trip x))

(define director
  (lambda (k)
    (cond
      ((equal? k "Goodfellas") "Martin Scorsese")
      ((equal? k "Inception") "Christopher Nolan")
      ((equal? k "Rear Window") "Alfred Hitchcock")
      ((equal? k "Aliens") "James Cameron")
      (else "Alan Smithee"))))
(director "Aliens")
(director "CSC240 The Movie")

(newline)
"Factorial"
(define fact
  (lambda (n)
    (if (<= n 1)
        1
        (* n (fact (- n 1))))))
(fact 10)
;(fact 1000)

"Tail-recursive Factorial"
(define fact-tail
  (lambda (n)
    (fact-tail-helper n 1)))
(define fact-tail-helper
  (lambda (n acc)
    (if (<= n 1)
        acc
        (fact-tail-helper (- n 1) (* acc n)))))
(fact-tail 40)