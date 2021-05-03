% splitlist/4
splitlist(_,[],[],[]) :- !.
splitlist(X, [H|T], [H|Smaller], Larger) :- H < X, !, splitlist(X,T,Smaller, Larger).
splitlist(X, [H|T], Smaller, [H|Larger]) :- splitlist(X,T,Smaller, Larger).

% quicksort/2
quicksort([],[]) :- !.
quicksort([Pivot|T],Sorted) :- 
    partition(Pivot, T, Left, Right),
    quicksort(Left, LeftSorted),
    quicksort(Right, RightSorted),
    append(LeftSorted, [Pivot|RightSorted], Sorted).
partition(_,[],[],[]) :- !.
partition(P, [H|T], [H|Left], Right) :- H < P, !, partition(P,T,Left,Right).
partition(P, [H|T], Left, [H|Right]) :- partition(P,T,Left,Right).

% unique/1
unique([]) :- !.
unique([_]) :- !.
unique([H, HX|T]) :- H \= HX, !, unique([H|T]), unique([HX|T]).

% lunch_duty/2
lunch_duty([[monday,A,B], [wednesday,C,D], [friday,E,F,G]], Teachers) :- 
    member(A,Teachers),
    member(B,Teachers),
    A \= B,
    member(C,Teachers),
    member(D,Teachers),
    C \= D, 
    member(E,Teachers),
    member(F,Teachers),
    member(G,Teachers),
    unique([E,F,G]).

