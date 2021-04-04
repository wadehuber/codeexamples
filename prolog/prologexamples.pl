%::::::::::::::
%usingswi.pl
%::::::::::::::
city(denver).
city(sandiego).
has_beach(sandiego).
vacation(X) :- city(X), has_beach(X).

language(c).
language(cpp).
language(scheme).
language(prolog).



%::::::::::::::
%Prolog Lesson 1
%::::::::::::::
happy(bob).
happy(alice).
talkative(bob).
president(washington).
president(lincoln).
annoying(bruce).
annoying(X) :- happy(X), talkative(X).


% robot code
kill_them(badguys). 
attack(badguys).
attack(X) :- annoying(X).


%equation(A, B, C) :- C is A + B.
badequation1(A, B, C) :- B is 1, C is A + B.
equation(A, B, C) :- member(A, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), 
        member(B, [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), 
		C is A + B.


    
%::::::::::::::
%Prolog Lesson 2
%::::::::::::::
weather(phoenix, spring, hot).
weather(phoenix, summer, hot).
weather(phoenix, fall, hot).
weather(phoenix, winter, warm).
weather(wellington, spring, warm).
weather(wellington, summer, warm).
weather(wellington, fall, hot).
weather(wellington, winter, cold).
weather(toronto, spring, cold).
weather(toronto, summer, hot).
weather(toronto, fall, cold).
weather(toronto, winter, cold).


father(bob, alice).
father(mike, gloria). 
father(bubba, sarah). 
father(bill_bobb, bubba). 
father(herman, edith). 
mother(edith, gloria). 
mother(gloria, sarah). 
mother(mary_lou, bubba). 
mother(elizabeth, edith). 
mother(sue, bob).
mother(ann, sue).
dad(X, Y)  :-  father(X, Y).
child(Y, X)  :-  father(X, Y).
parent(X, Y) :- mother(X, Y); father(X, Y).
grandmother(X, Y) :- mother(X, Z), parent(Z, Y).
is_grandmother(X) :- grandmother(X, _).
grandparent(A, D) :- 
	parent(A, Person), 
	parent(Person, D).
% ancestor(A,D) :- ancestor(A, P), ancestor(P, D).
ancestor(A, D) :- parent(A,D).
ancestor(A,D) :- parent(A, P), ancestor(P, D).

factorial(1, 1) :- !.
factorial(N, F) :- N1 is N - 1, factorial(N1, F1), F is N * F1.


first([], []).
first([H | _], H).

firsttwo([H1, H2 | _], [H1, H2]).

firsttwoaresame([H1, H1 | _]).

lastelement([X], X).
lastelement([_ | T], X) :- lastelement(T,X).

listsize([],0) :- !.
listsize([_ | T], S) :- listsize(T,ST), S is 1 + ST.

% remove every other element
remeo([],[]).
remeo([X],[X]).
remeo([H, _ | T], [H | T1]) :- remeo(T, T1).


% Additional examples of rules with Prolog lists
% Change everything in a list to 'secret'
% The first rule is the base case which handles the case of an empty list
change([], []) :- !.   % base case
% The next rule add 'secret' to the front of the result, then changes the tail
%   note secret is an atom so we do not need quotes
change([_H| T], [secret | T1]) :- change(T, T1).  
% we don’t need a rule for the case where we don’t give the rule a list as a parameter since the existing two rules will fail for any non-list.
% this line tests change/2
:- change([1, 2, 3], X), write(X), nl.


% Transform every element in a list to a positive number
% The first rule is the base case which handles the case of an empty list
positive([], []) :- !.  % base case
% if H is less than 0, multiply H by -1 and add to the result
positive([H| T], [HP | T1]) :- H < 0, !, HP is H * -1, positive(T, T1).
% Otherwise, H is either 0 or positive, so leave it alone
positive([H| T], [H | T1]) :- positive(T, T1).
% test change				 
:- positive([-1, 2, -3], X), write(X), nl.

%::::::::::::::
%Prolog Lesson 3
%::::::::::::::
flip_three([H1, H2, H3 | T], [H3, H2, H1 | T]).

myreverse([],[]) :- !.
myreverse([H | T], Result) :- myreverse(T, T1), append(T1, [H], Result).

change(H, Q, D, N, P) :-
	member(N, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]),
	member(D, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
	member(Q, [0, 1, 2, 3, 4]),
	member(H, [0, 1, 2]),
	S is ( (50 * H) + (25 * Q) + (10 * D) + (5 * N) ),
	S =< 100,
	P is 100 - S.

warm_blooded(cat).
warm_blooded(dog).     
warm_blooded(chicken). 
four_legs(cat).
four_legs(dog).
two_legs(chicken).
mammal0(M) :- warm_blooded(M), four_legs(M).
mammal0(dinosaur).
mammal1(M) :- !, warm_blooded(M), four_legs(M).
mammal1(dinosaur).
mammal2(M) :- warm_blooded(M), !, four_legs(M).
mammal3(M) :- warm_blooded(M), four_legs(M), !.

% same rules as mammal1, but different order
mammal4(dinosaur).
mammal4(M) :- !, warm_blooded(M), four_legs(M).
mammal4(dragon).

mammal5(dinosaur).
mammal5(dragon).
mammal5(M) :- !, warm_blooded(M), four_legs(M).


state(california).
state(arizona).
state(texas).
state(nevada).

:- dynamic class/4.
class(cs, 101, "Introduction to Computer Science", cullum).
class(cs, 235, "Operating Systems", gupta).
class(cs, 328, "Computer Graphics", gupta).
class(cs, 380, "Algorithm Analysis", efferson).
class(cs, 440, "Theory of Computation", hilliard).

all_states(StateList) :- findall(S, state(S), StateList).

taught_by(Prof, ClassList) :- findall(Class, class(_, _, Class, Prof), ClassList).
cs_classes(ClassList) :- findall([Dept, Num, Class, Prof], class(Dept, Num, Class, Prof), ClassList).

upper_level(Class) :- class(_Dept, Number, Class, _Prof), Number >= 300.
upper_level_classes(ClassList) :- findall(Class, upper_level(Class), ClassList).

cs_profs(Profs) :- findall(Prof, class(_, _, _, Prof), Profs).
cs_profs2(Profs) :- findall(Prof, class(_, _, _, Prof), Profs).

