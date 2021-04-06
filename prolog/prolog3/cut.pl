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