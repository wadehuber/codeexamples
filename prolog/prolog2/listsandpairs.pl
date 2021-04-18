% Prolog lists & pairs
% PAIR: [ Head | Tail ]
% LIST: [] or [ Head | TailIsAList ]

pairparts([H|T], H, T).

% first/2 - find the first thing in a list or pair
first([H|_T], H).

% is_pair/1 - pair predicate
is_pair([_H|_T]).

% is_list/2 - list predicate
is_list([]).
is_list([_H|T]) :- is_list(T).

% at_least_two_in_list/1 - at least two element in the list
at_least_two_in_list([_,_|_T]).

% at_least_two_in_list/3 - first two elements in the list
at_least_two_in_list([A,B|_T], A, B).

% third_element/2 - find the third element in a list
third_element([_,_,A|_T], A).

% first_two - get the first two elements of a list
% first_two/3
first_two([H1, H2 | _T], H1, H2).
% first_two/2
first_two([H1, H2 | _T], [H1, H2]).
