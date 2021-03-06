#lang scheme

"Scope"
(define a 100)
a
(+ 7 a)

(let
    ((a 4)
     (b 3))
  (+ a b))

(let ((a 4)
      (b (+ a 1)))    ; a comes from the global scope
  (+ a b))

(let ((a 4))
  (let
      ((b (+ a 1)))   ; a comes from the outer scope
    (+ a b)))

; You can make things confusing
(let
    ((x 9))
  (let
      ((x 3)
       (y (* 5 x)))
    (+ x y)))

(let
    ((cdr car)
     (car cdr))
  (list (car '(1 2 3 4)) (cdr '(1 2 3 4))))

(define let-test
  (lambda (x)
    (let
        ((a (* 2 x x))
         (b (+ 1 x))
         (c 5))
      (+ a b c))))
(let-test 10)

; calculates the volume of material in a cylindrical shell
(define cylinder-material
  (lambda (height radius thickness)
    (let
        ((pi 3.14159265))
      (let
          ((cylinder-vol (lambda (h r)
                           (* h (* pi (* r r))))))
        (- (cylinder-vol height radius)
           (cylinder-vol (- height (* 2 thickness)) (- radius thickness)))))))
(cylinder-material 20 7 1)

(let
    ((+ 10)
     (- 4)
     (* -))
  (* + -))

(newline)
"lambda->let, let->lambda"
(let
    ((a 4)
     (b 5))
  (+ a b))
((lambda (a b) (+ a b)) 4 5)

((lambda (x y) (+ (* x x) (* y y))) 3 4)
(let
    ((x 3)
     (y 4))
  (+ (* x x) (* y y)))
