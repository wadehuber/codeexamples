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

%avg_temp/2
avg_temp(berlin, 49).
avg_temp(karlsruhe, 60).
avg_temp(paris, 55).
avg_temp(belgrade, 52).
avg_temp(chicago, 50).
avg_temp(boston, 48).
avg_temp(johannesburg, 55).
avg_temp(phoenix, 80).
avg_temp(jerusalem, 61).

%avg_temp_celsius/2 - calculate the average temperature in Celsius
avg_temp_celsius(City, C_temp) :-    % head of the rule
                avg_temp(City, F_temp), % get the avg temp of City
				 C_temp is round((F_temp - 32) * 5 / 9).

play_outside(City) :- avg_temp_celsius(City, Temp), Temp < 15.

colder_than(City1, City2) :- 
                avg_temp(City1, Temp1),
			    avg_temp(City2, Temp2),
			    Temp1 < Temp2.

% To check equality, use the same variable name!
same_temp(City1, City2) :-
               avg_temp(City1, Temp),
               avg_temp(City2, Temp),
			   City1 \= City2.


%president/1
president(washington).
president(lincoln).
president(kennedy).
president(obama).
president(X) :- member(X,[adams, jefferson, fdr]).

%score/2 - not a good rule!
score(dbacks, 4).
score(dodgers, 2).
score(patriots, 34).
score(falcons, 28).
won_bad(X) :- score(X, ScoreX), score(_Y, ScoreY), ScoreX > ScoreY.

% better won rule
game(dbacks, 4, dodgers, 2).
game(falcons, 28, patriots, 34).
won(X) :- game(X, ScoreX, _Y, ScoreY), ScoreX > ScoreY.
won(Y) :- game(_X, ScoreX, Y, ScoreY), ScoreY > ScoreX.

happy(bob).
happy(alice).
talkative(bob).
annoying(jarjar).
annoying(gnats).
annoying(X) :- talkative(X), happy(X).

%Robot AI
%badguy/1
badguy(darthvader).     
badguy(darthsidious).
badguy(kyloren).
%badguy/2
badguy(batman, twoface).
badguy(batman, joker).
badguy(superman, lexluthor).
fight(X) :- badguy(X).
fight(X) :- badguy(_Hero, X).

% Poor bob!
fight(X) :- annoying(X).

% Poor alice!
fight(alice).

%fight(_).    % Fight anything passed to the rule - Noooooooo!

% write output when a file is consulted
:- badguy(batman, Who), write('Batman has defeated '), write(Who), nl.
% note - don't use write in your rules!

is_integer(X) :- member(X, [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]).

% equation A + B = C
equation(A, B, C) :- 
                     is_integer(A),
                     is_integer(B),
		     C is A + B.
