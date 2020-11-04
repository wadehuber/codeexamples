%father/2
father(ruwee, padme).
father(anakin, luke).
father(anakin, leia).
father(han, ben).
%mother/2
mother(jobal, padme).
mother(shmi, anakin).
mother(padme, luke).
mother(padme, leia).
mother(leia, ben).

%alias/2
alias(darthvader, anakin).
alias(kyloren, ben).
alias(X,Y) :- alias(Y,X).

%parent/2
parent(X,Y) :- father(X, Y).
parent(X,Y) :- mother(X, Y).

%parent/2
childof(X,Y) :- parent(Y,X).
