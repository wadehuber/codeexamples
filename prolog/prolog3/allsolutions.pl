change(HalfDollars, Quarters, Dimes, Nickels, Pennies) :-
	member(Nickels, [0, 1, 2, 3, 4, 5 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]),
	member(Dimes, [0, 1, 2, 3, 4, 5 6, 7, 8, 9, 10]),
	member(Quarters, [0, 1, 2, 3, 4]),
	member(HalfDollars, [0, 1, 2]),
	SubTotal is ( (HalfDollars * 50) + (Quarters * 25) + (Dimes * 10) + (Nickels * 5) ),
	SubTotal =< 100,
	Pennies is 100 - SubTotal.

mammal(bear).
mammal(dolphin).
mammal(deer).
mammal(dog).
mammal(squirrel).
mammal(cat).
like(turtle).
like(dog).
like(bear).

only_ones_i_like([], []) :- !.
only_ones_i_like([H | T], [H | T1]) :- like(H), !, only_ones_i_like(T, T1).
only_ones_i_like([_H | T] , T1) :- only_ones_i_like(T, T1).

% findall(Variable, query(Variable), ListOfValuesOfVariableThatSucceed)

find_all_change(Ways) :- findall([H, Q, D, N, P], change(H, Q, D, N, P), Ways).
find_big_coins(Ways) :- setof([H, Q, D], change(H, Q, D, _, _), Ways).

all_the_mammals(Mammals) :- findall(Mammal, mammal(Mammal), Mammals).
mammals_i_like(List) :- all_the_mammals(MammalList), only_ones_i_like(MammalList, List).

division(nl_west, diamondbacks). 
division(nl_west, dodgers). 
division(nl_west, giants). 
division(nl_west, padres). 
division(nl_west, rockies). 
division(al_west, angels). 
division(al_west, mariners). 
division(al_west, as). 
division(al_west, rangers). 
division(al_west, astros). 

nl_west(Teams) :- findall(Team, division(nl_west, Team), Teams).
mlb_teams(Teams) :- findall(Team, division(_, Team), Teams).
mlb_divisions(Divisions) :- setof(Division, Team^division(Division, Team), Divisions).
%mlb_divisions(Divisions) :- setof(Division, division(Division), Divisions).
