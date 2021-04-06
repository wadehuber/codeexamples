% This specifies that I can modify the avenger fact using assert/retract statements
:- dynamic avenger/1.

avenger(ironman).
avenger(captainamerica).
avenger(thor).
avenger(blackwidow).
avenger(hulk).
avenger(hawkeye).

% Guessing game
newgame(X) :- retractall(secret_num(_)), asserta(secret_num(X)).

% Example of using guessing game
% ?- newgame(5).
% true.
% 
% ?- secret_num(3).
% false.
% 
% ?- secret_num(10).
% false.
% 
% ?- secret_num(5).
% true.


% Assert Examples
% ?- asserta(avenger(scarletwitch)).
% true.
% 
% ?- findall(X,avenger(X),Avengers).
% Avengers = [scarletwitch, ironman, captainamerica, thor, blackwidow, hulk, hawkeye].
% 
% ?- asserta(avenger(vision)).
% true.
% 
% ?- assertz(avenger(falcon)).
% true.
% 
% ?- avenger(X).
% X = vision ;
% X = scarletwitch ;
% X = ironman ;
% X = captainamerica ;
% X = thor ;
% X = blackwidow ;
% X = hulk ;
% X = hawkeye ;
% X = falcon.
% 
% ?- assert((positive_number(X) :- X > 0)).
% true.
% 
% ?- positive_number(10).
% true.
% 
% ?- positive_number(-4).
% false.



% Retract examples
% ?- retractall(positive_number(_)).
% true.
% 
% ?- positive_number(-4).
% false.
% 
% ?- positive_number(-4).
% false.
% 
% ?- positive_number(10).
% false.
% ?- retractall(avenger(ironman)).
% true.
% 
% ?- findall(X,avenger(X),Avengers).
% Avengers = [vision, scarletwitch, captainamerica, thor, blackwidow, hulk, hawkeye, falcon].
% 
% ?- retractall(avenger(hulk)).
% true.
% 
% ?- findall(X,avenger(X),Avengers).
% Avengers = [vision, scarletwitch, captainamerica, thor, blackwidow, hawkeye, falcon].
% 
