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