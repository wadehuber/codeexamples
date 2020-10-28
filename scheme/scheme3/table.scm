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

(newline)
"find-player returns the statistics for a player"
(define find-player
  (lambda (lst player)
    (cond
      ((null? lst) '())
      ((equal? (caar lst) player) (cdar lst))
      (else (find-player (cdr lst) player)))))

(find-player saints2009 'drew_brees)
(find-player saints2009 'marques_colston)
(find-player saints2009 'michael_thomas)

(newline)
"find-player-stat returns a specific statistic"
(define find-stat
  (lambda (lst stat)
    (cond
      ((null? lst) 0)
      ((equal? stat (caar lst)) (cdar lst))
      (else (find-stat (cdr lst) stat)))))
(define find-player-stat
  (lambda (lst player stat)
    (find-stat (find-player lst player) stat)))
(find-player-stat saints2009 'jeremy_shockey 'receiving)
(find-player-stat saints2009 'reggie_bush 'rushing)
(find-player-stat saints2009 'joe_burrow 'passing)

(newline)
"find-team-stat finds the teams total statistics"
(define find-value
  (lambda (lst stat)
    (cond
      ((null? lst) 0)
      ((equal? stat (caar lst)) (cdar lst))
      (else (find-value (cdr lst) stat)))))
(define find-team-stat
  (lambda (lst stat)
    (if (null? lst)
        0
        (+ (find-value (cdar lst) stat) (find-team-stat (cdr lst) stat)))))
(find-team-stat saints2009 'passing)
(find-team-stat saints2009 'rushing)
(find-team-stat saints2009 'receiving)
(find-team-stat saints2009 'losstofalcons)

