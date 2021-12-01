% double_list/2 - double each element in a list
double_list([],[]).
double_list([H | T], [H2 | T2]) :- H2 is H * 2, double_list(T, T2).


% duplicate_list_element/2 - duplicate each element in a list
duplicate_list_elements([],[]).
duplicate_list_elements([H | T], [ H, H | T2]) :- duplicate_list_elements(T, T2).

% nextto/3 - 2 elements appear next to each other in a list
nextto([X,Y|_], X, Y).
nextto([_ | T], X, Y) :- nextto(T, X, Y).

% sumlist/2 - sum the elements of a list
sumlist([], 0).
sumlist([H | T], Sum) :- sumlist(T, SumT), Sum is SumT + H.

% sum_first_x/3 - sum the first x elements of a list
sum_first_x(_List, 0, 0).
sum_first_x([H | T], X, Sum) :-
	X1 is X - 1, 
	sum_first_x(T, X1, SumTail),
	Sum is SumTail + H.

cons(Element, List, [Element | List]).
duplicate_head([H | T], [H, H | T]).

% listsize/2 - size of a list
listsize([], 0).
listsize([_H|T], Size) :- listsize(T,TailSize), Size is TailSize + 1.

% add_one_to_all/2 - increment each element in the list
add_one_to_all([], []).
add_one_to_all([H|T], [H1|T1]) :- H1 is H + 1, add_one_to_all(T, T1).

% increment/2 - increment the first parameter
increment([H|T], List) :- add_one_to_all([H|T], List).
increment(X,Y) :- Y is X + 1.

% only_mults_of_3/2 - keep only multiples of 3
only_mults_of_3([],[]).
only_mults_of_3([H | T], [H | T1]) :- 0 is H mod 3, only_mults_of_3(T, T1).
only_mults_of_3([H | T], T1) :- X is H mod 3, X > 0, only_mults_of_3(T, T1).

% remove_eo/2 - remove every other element from a list
remove_eo([], []).
remove_eo([X], [X]).
remove_eo([H, _|T], [H|T1]) :- remove_eo(T, T1).

% is_sorted/1 - predicate to determine if a list is sorted
is_sorted([]).
is_sorted([_]).
is_sorted([H1,H2| T]) :- H1 < H2, is_sorted([H2|T]).

% perm_sort/2 - permutation sort
perm_sort(X,Y) :- permutation(X,Y), is_sorted(Y).