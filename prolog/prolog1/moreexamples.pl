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
