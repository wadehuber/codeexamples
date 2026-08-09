;; =================================================
;; Helper method examples
;; =================================================

;; -------------------------------------------------
;; Counting positive numbers
;; -------------------------------------------------
(define positive-number?
  (lambda (n)
    (> n 0)))

(define count-positive
  (lambda (nums)
    (cond
      ((null? nums) 0)
      ((positive-number? (car nums))
       (+ 1 (count-positive (cdr nums))))
      (else
       (count-positive (cdr nums))))))

;; -------------------------------------------------
;; Filtering students who passed
;; -------------------------------------------------

;; Assume a student is represented as a list:
;; (name score assignments academic-hold?)
;; Example: ("Alice" 85 10 #f)

;; "Getter" helpers pull info out of the list
(define student-score (lambda (s) (cadr s)))
(define student-assignments (lambda (s) (caddr s)))
(define student-academic-hold? (lambda (s) (cadddr s)))

(define passed?
  (lambda (student)
    (and (>= (student-score student) 70)
         (>= (student-assignments student) 8)
         (not (student-academic-hold? student)))))

(define passing-students
  (lambda (students)
    (cond
      ((null? students) '())
      ((passed? (car students))
       (cons (car students)
             (passing-students (cdr students))))
      (else
       (passing-students (cdr students))))))

;; -------------------------------------------------
;; Checking whether a string is a valid username
;; -------------------------------------------------
(define char-alphanumeric?
  (lambda (c)
    (or (char-alphabetic? c) (char-numeric? c))))

(define list-alphanumeric?
  (lambda (lst)
    (cond
      ((null? lst) #t)
      ((char-alphanumeric? (car lst)) (list-alphanumeric? (cdr lst)))
      (else #f))))

(define (string-alphanumeric1? s)
  (andmap (lambda (c)
            (or (char-alphabetic? c)
                (char-numeric? c)))          
          (string->list s)))

(define string-alphanumeric?
  (lambda (s)
    (list-alphanumeric? (string->list s))))
  

(define (valid-username? name)
  (and (<= 3 (string-length name) 16)
       (string-alphanumeric? name)
       (not (char-numeric? (string-ref name 0)))))

(define (filter-valid-usernames names)
  (cond
    ((null? names) '())
    ((valid-username? (car names))
     (cons (car names)
           (filter-valid-usernames (cdr names))))
    (else
     (filter-valid-usernames (cdr names)))))

;; =================================================
;; Test Code
;; =================================================

(define (check-expect actual expected)
  (if (equal? actual expected)
      (display "PASS\n")
      (begin
        (display "FAIL: got ")
        (display actual)
        (display ", expected ")
        (display expected)
        (newline))))

;; =================================================
;; Counting positives
;; -------------------------------------------------
;; Tests for positive-number?
;; -------------------------------------------------

(check-expect (positive-number? 5)     #t)
(check-expect (positive-number? 1)     #t)
(check-expect (positive-number? 0)     #f)
(check-expect (positive-number? -3)    #f)
(check-expect (positive-number? 0.5)   #t)
(check-expect (positive-number? -0.1)  #f)

;; -------------------------------------------------
;; Tests for count-positive
;; -------------------------------------------------

(check-expect (count-positive '())               0)
(check-expect (count-positive '(1 2 3))          3)
(check-expect (count-positive '(-1 -2 -3))       0)
(check-expect (count-positive '(1 -2 3 -4 5))    3)
(check-expect (count-positive '(0 0 0))          0)
(check-expect (count-positive '(-5 0 7))         1)
(check-expect (count-positive '(10))             1)
(check-expect (count-positive '(-10))            0)
(check-expect (count-positive '(1 0 -1 2 0 3))   3)

;; =================================================
;; Student passing test code
;; -------------------------------------------------
;; Sample students
;; -------------------------------------------------

(define alice   '("Alice"   85 10 #f))  ; passes
(define bob     '("Bob"     65  9 #f))  ; fails (score)
(define carol   '("Carol"   90  7 #f))  ; fails (assignments)
(define dave    '("Dave"    78 12 #t))  ; fails (hold)
(define eve     '("Eve"     72  8 #f))  ; passes (borderline)

;; -------------------------------------------------
;; Tests for passed?
;; -------------------------------------------------
"passed? test cases"
(check-expect (passed? alice)  #t)
(check-expect (passed? bob)    #f)
(check-expect (passed? carol)  #f)
(check-expect (passed? dave)   #f)
(check-expect (passed? eve)    #t)

;; -------------------------------------------------
;; Tests for passing-students
;; -------------------------------------------------
"passing-students test cases"
(check-expect (passing-students '()) '())

(check-expect (passing-students (list alice bob carol dave eve))
              (list alice eve))

(check-expect (passing-students (list bob carol dave))
              '())

(check-expect (passing-students (list alice eve))
              (list alice eve))

(check-expect (passing-students (list dave alice bob eve))
              (list alice eve))

(check-expect (string-alphanumeric? "hello")        #t)
(check-expect (string-alphanumeric? "Hello123")     #t)
(check-expect (string-alphanumeric? "abcXYZ789")    #t)
(check-expect (string-alphanumeric? "")             #t)   ; empty string
(check-expect (string-alphanumeric? "hello!")       #f)   ; punctuation
(check-expect (string-alphanumeric? "hello world")  #f)   ; space
(check-expect (string-alphanumeric? "123")          #t)
(check-expect (string-alphanumeric? "a_b")          #f)   ; underscore

;; =================================================
;; Username test code
;; -------------------------------------------------
;; Tests for valid-username?
;; -------------------------------------------------
"valid-username test cases"
(check-expect (valid-username? "alice")         #t)
(check-expect (valid-username? "Bob42")         #t)
(check-expect (valid-username? "a1b2c3")        #t)
(check-expect (valid-username? "ab")            #f)   ; too short
(check-expect (valid-username? "abcdefghijklmnopq") #f) ; too long (17 chars)
(check-expect (valid-username? "1alice")        #f)   ; starts with digit
(check-expect (valid-username? "alice!")        #f)   ; non-alphanumeric
(check-expect (valid-username? "alice bob")     #f)   ; space
(check-expect (valid-username? "Alice")         #t)
(check-expect (valid-username? "a")             #f)   ; too short
(check-expect (valid-username? "abcdefghijklmnop") #t) ; exactly 16 chars

;; -------------------------------------------------
;; Tests for filter-valid-usernames
;; -------------------------------------------------
"filter-valid-usernames test cases"
(check-expect (filter-valid-usernames '()) '())

(check-expect (filter-valid-usernames (list "alice" "bob" "carol"))
              (list "alice" "bob" "carol"))

(check-expect (filter-valid-usernames (list "ab" "alice" "1bob" "carol!"))
              (list "alice"))

(check-expect (filter-valid-usernames (list "1start" "too_long_username_here" "okname" "x"))
              (list "okname"))

(check-expect (filter-valid-usernames (list "a" "ab" "abc" "abcd"))
              (list "abc" "abcd"))
