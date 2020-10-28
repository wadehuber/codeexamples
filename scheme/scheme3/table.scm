#lang scheme

(define saints2009 '(
    (drew_brees . ((passing . 4388) (rushing . 33) (receiving . -4)))
    (mark_brunell . ((passing . 102) (rushing . -12)))
    (mike_bell . ((rushing . 654) (receiving . 12)))
    (reggie_bush . ((rushing . 390) (receiving . 335)))
    (devery_henderson . ((rushing . 13) (receiving . 804)))
    (jeremy_shockey . ((receiving . 569)))
    (marques_colston . ((rushing . 6) (receiving . 1074)))
    (lance_moore . ((receiving . 153)))))

(define find-value
  (lambda (lst value)
	  (if (null? lst)
    	0
    	(if (equal? value (caar lst))
        	  (cdar lst)
        	  (find-value (cdr lst) value)))))

(define total-stat
  (lambda (lst stat)
	  (if (null? lst)
    	0
    	(+ (find-value (cdar lst) stat) (total-stat (cdr lst) stat)))))

(define find-player
  (lambda (lst player)
	 (cond
           ((null? lst) '())
  	   ((equal? (caar lst) player) (cdar lst))
  	   (else (find-player (cdr lst) player)))))

(define find-stat
  (lambda (lst stat)
    (cond
      ((null? lst) 0)
      ((eq? stat (caar lst)) (cdar lst))
      (else (find-stat (cdr lst) stat)))))

(define find-player-stat
  (lambda (lst player stat)
    (find-stat (find-player lst player) stat)))

(find-player saints2009 'drew_brees)
(total-stat saints2009 'passing)
(total-stat saints2009 'rushing)
(find-stat (find-player saints2009 'drew-brees) 'passing)
(find-player-stat saints2009 'marques_colston 'receiving)
