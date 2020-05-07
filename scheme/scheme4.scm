#lang scheme

; More Scheme examples

"Division"
(/ 30 7)     ; rational division
(/ 30 7.0)   ; real division
(quotient 20 8)  
(quotient 20 8.0)
"Modulo vs remainder: 20 % 8"
(modulo 20 8)
(remainder 20 8)
"Modulo vs remainder: -20 % 8"
(modulo -20 8)
(remainder -20 8)
"Modulo vs remainder: 20 % -8"
(modulo 20 -8)
(remainder 20 -8)
(expt 2 5)   ; exponent
'(/ 10 5)

(newline)
"Rounding numbers"
(round 3.4)
(round 3.5)
(round 3.6)
(truncate 3.6)
(truncate 3.1)
(floor 3.6)
(ceiling 3.4)

(newline)
"Other mathematical functions"
(sqrt 9)
(sqrt 2)
(exp 1)
(log pi)
(log (exp 1))
"Trig functions"
(sin (/ pi 2))
(cos (/ pi 2))
(tan (/ pi 4))
(asin (/ pi 2))
(acos (/ pi 2))
(atan (/ pi 4))


(newline)
"Characters"
(char? 'a)
(char? "a")
(char? #\a)
(char-upcase #\a)
(char-upcase #\A)
(char->integer #\A)
(char->integer #\a)
(integer->char 65)


(newline)
"Boolean"
(< 4 10)
(> 4 10)
(<= 4 10)
(>= 4 10)
(not #f)
(or #t #f)
(and #t #f)
(xor #t #f)
(or (not (integer? 6)) (symbol? 'six))
(and (integer? 6) (symbol? '6))