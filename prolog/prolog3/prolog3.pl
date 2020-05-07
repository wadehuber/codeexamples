% flip_three/2 -> [A, B, C, D, E] => [C, B, A, D, E]
flip_three([H1, H2, H3 | T], [H3, H2, H1 | T]).

do_strange_thing([A, B, C, D | T], [A, A, D, D, C, B, A, B, C, D | T]).


% myreverse/2 - reverses a list
myreverse([], []) :- !.
%myreverse([H | T], [T1 | H]) :- myreverse(T, T1).                        % attempt 1
%myreverse([H | T], [T1 | [H]]) :- myreverse(T, T1).                      % attempt 2
%myreverse([H | T], Result) :- myreverse(T, T1), append(T1, H, Result).   % attempt 3
myreverse([H | T], Result) :- myreverse(T, T1), append(T1, [H], Result).  % attempt 3

change(HalfDollars, Quarters, Dimes, Nickels, Pennies) :-
	member(Nickels, [0, 1, 2, 3, 4, 5 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]),
	member(Dimes, [0, 1, 2, 3, 4, 5 6, 7, 8, 9, 10]),
	member(Quarters, [0, 1, 2, 3, 4]),
	member(HalfDollars, [0, 1, 2]),
	SubTotal is ( (HalfDollars * 50) + (Quarters * 25) + (Dimes * 10) + (Nickels * 5) ),
	SubTotal =< 100,
	Pennies is 100 - SubTotal.





% Cut example
% Replace odd numbers with the atom odd, remove 0s, replace even numbers with half their value
% Cut ensures that we stop searching for a solution if the list is empty.
numrep([],[]) :- !.
% Cut below stops searching if the first element is 0
numrep([0 | T], T1) :- !, numrep(T, T1).
% Cut below stops searching once it determines the head of the list is even
numrep([H | T], [H1 | T1]) :- 0 is H mod 2, !, H1 is H / 2, numrep(T, T1).
% We don't need to check if H is odd in the last rule - it is or else we would not reach this rule
numrep([_H | T], [odd | T1]) :- numrep(T, T1).

warm_blooded(shark).
warm_blooded(cat).
warm_blooded(dog).
warm_blooded(chicken).
four_legs(dog).
four_legs(cat).
two_legs(chicken).

mammal0(bear).
mammal0(M) :- warm_blooded(M), four_legs(M).
mammal0(dolphin).

mammal1(bear).
mammal1(M) :- !, warm_blooded(M), four_legs(M).
mammal1(dolphin).

mammal2(bear).
mammal2(M) :- warm_blooded(M), !, four_legs(M).
mammal2(dolphin).

mammal3(bear).
mammal3(M) :- warm_blooded(M), four_legs(M), !.
mammal3(dolphin).

mammal4(_) :- !, fail.  % Nothing is a mammal4





% findall(Variable, query(Variable), ListOfValuesOfVariableThatSucceed)
all_the_mammals0(Mammals) :- findall(Mammal, mammal0(Mammal), Mammals).
all_the_mammals1(Mammals) :- findall(Mammal, mammal1(Mammal), Mammals).
all_the_mammals2(Mammals) :- findall(Mammal, mammal2(Mammal), Mammals).
all_the_mammals3(Mammals) :- findall(Mammal, mammal3(Mammal), Mammals).

find_all_change(Ways) :- findall([H, Q, D, N, P], change(H, Q, D, N, P), Ways).

find_big_coins(Ways) :- setof([H, Q, D], change(H, Q, D, _, _), Ways).


like_animal(turtle).
like_animal(dog).
like_animal(bear).

mammals_i_like(List) :- all_the_mammals0(MammalList), only_ones_i_like(MammalList, List).
only_ones_i_like([], []) :- !.
only_ones_i_like([H | T], [H | T1]) :- like_animal(H), !, only_ones_i_like(T, T1).
only_ones_i_like([_H | T] , T1) :- only_ones_i_like(T, T1).



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
