% flip_three/2 ->  [A, B, C, D] => [C, B, A, D]
flip_three([H1, H2, H3 | T], [H3, H2, H1 | T]).

do_strange_thing([A, B, C, D | T], [A, A, D, D, C, B, A, B, C, D | T]).

myreverse([], []) :- !.
%myreverse([H | T], [T1 | H]) :- myreverse(T, T1).   % attempt 1
%myreverse([H | T], [T1 | [H]]) :- myreverse(T, T1). % attempt 2
%myreverse([H | T], Result) :- myreverse(T, T1), append(T1, H, Result). % attempt 3
myreverse([H | T], Result) :- myreverse(T, T1), append(T1, [H], Result).

change(HalfDollars, Quarters, Dimes, Nickels, Pennies) :-
	member(Nickels, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]),
	member(Dimes, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
	member(Quarters, [0, 1, 2, 3, 4]),
	member(HalfDollars, [0, 1, 2]),
	SubTotal is ( (HalfDollars * 50) + (Quarters * 25) + (Dimes * 10) + (Nickels * 5) ),
	SubTotal =< 100,
	Pennies is 100 - SubTotal.

% Cut example
% Replace odd numbers with the atom odd, remove 0s, replace even numbers with half their value
% Cut ensures we stop searching for a solution if the list is empty
numrep([],[]) :- !.
% Cut below stops searching if the first element is 0
numrep([0 | T], T1) :- !, numrep(T, T1).
% Cut below stops searching if H is even
numrep([H | T], [H1 | T1]) :- 0 is H mod 2, !, H1 is H / 2, numrep(T, T1).
% We don't need to check if H is odd in the last rule - it is or else we would not reach this rule
numrep([_H | T], [odd | T1]) :- numrep(T, T1).

%warm_blooded(shark).
warm_blooded(cat).
warm_blooded(dog).
warm_blooded(chicken).
four_legs(dog).
four_legs(cat).
two_legs(chicken).

mammal0(bears).
mammal0(M) :- warm_blooded(M), four_legs(M).
mammal0(dolphins).

mammal1(bears).
mammal1(M) :- !, warm_blooded(M), four_legs(M).
mammal1(dolphins).

mammal2(bears).
mammal2(M) :- warm_blooded(M), !, four_legs(M).
mammal2(dolphins).

mammal3(bears).
mammal3(M) :- warm_blooded(M), four_legs(M), !.
mammal3(dolphins).

mammal4(_) :- !, fail.  % Nothing is a mammal4

% findall(Variable, query(Variable), ListOfValuesofVariableThatSucceed).
all_the_mammals(Mammals) :- findall(Mammal, mammal0(Mammal), Mammals).
find_all_change(Ways) :- findall([H, Q, D, N, P], change(H, Q, D, N, P), Ways).
find_big_coins(Ways) :- setof([H, Q, D], change(H, Q, D, _, _), Ways).

assert(mammal4(horse)).
% ?- mammal4(X).
% false.
% 
% ?- asserta(mammal4(horse)).
% true.
% 
% ?- mammal4(X).
% X = horse ;
% false.
% ?- assertz(mammal4(fox)).
% true.
% 
% ?- mammal4(X).
% X = mouse ;
% false.

% You can also assert rules:
% ?- assert((big(X) :- X > 10)).
% true.
% 
% ?- big(14).
% true.
% 
% ?- big(4).
% false.


% asserta inside a rule
% Guessing game
newgame(X) :- retractall(guess(_)), asserta((guess(X))).
% ?- newgame(4).
% true.
% 
% ?- guess(2).
% false.
% 
% ?- guess(6). 
% false.
% 
% ?- guess(4).
% true.
