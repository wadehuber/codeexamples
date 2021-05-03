% splitlist/4
splitlist(_,[],[],[]) :- !.
splitlist(N, [H|T], [H|Smaller], Larger) :- H < N, !, splitlist(N,T,Smaller,Larger).
splitlist(N, [H|T], Smaller, [H|Larger]) :- splitlist(N,T,Smaller,Larger).

% quicksort/2
quicksort([],[]) :- !.
quicksort([Pivot | T], Sorted) :- 
          splitlist(Pivot, T, Left, Right),  % partition around the pivot
          quicksort(Left, LeftSorted),
          quicksort(Right, RightSorted),
          append(LeftSorted, [Pivot|RightSorted], Sorted).

% unique/1
unique([]) :- !.
unique([_]) :- !.
unique([H, HX|T]) :- H \= HX, !, unique([H|T]), unique([HX|T]). 

% lunch_duty
lunch_duty([[mon,A,B], [wed,C,D],[fri,E,F,G]], Teachers) :- 
   member(A, Teachers),
   member(B, Teachers),
   member(C, Teachers),
   member(D, Teachers),
   member(E, Teachers),
   member(F, Teachers),
   member(G, Teachers),
   unique([A,B,C,D,E,F,G]),
   C \= kent,
   D \= kent,
   E \= susan,
   F \= susan,
   G \= susan.
   