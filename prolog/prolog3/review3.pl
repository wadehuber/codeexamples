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