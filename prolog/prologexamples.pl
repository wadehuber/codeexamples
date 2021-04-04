%::::::::::::::
%usingswi.pl
%::::::::::::::
:- dynamic class/4.
city(denver).
city(sandiego).
has_beach(sandiego).
vacation(X) :- city(X), has_beach(X).

language(c).
language(cpp).
language(scheme).
language(prolog).


%::::::::::::::
%Prolog Notes 1
%::::::::::::::
male(luke).
male(john).
male(bob).
male(mike).
female(sarah).
president(lincoln).
president(kennedy).
president(bush).
president(obama).
president(trump).
president(biden).
president(bob).

score(dbacks, 4).
score(dodgers, 2).
score(dodgers, 1).
won(X) :- score(X, S1), score(Y, S2), S1 > S2, X \= Y.

happy(bob).
happy(alice).
talkative(bob).
annoying(X) :- happy(X), talkative(X).

% robot
badguy(joker).
badguy(deadshot).
fight(X) :- badguy(X).
fight(X) :- annoying(X).


%equation(A, B, C) :- C is A + B.
badequation(A, B, C) :- B is 1, C is A + B.
equation(A, B, C) :-
    member(A, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
    member(B, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
    C is A + B.

    
%::::::::::::::
%Prolog Notes 2
%::::::::::::::
% facts
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

location(london, 51, 0).
location(phoenix, 33, 112).
location(tokyo, 35, -139).
location(rome, 41, -12).
location(madrid, 48, 3).
location(canberra, -35, -149).
location(johannesburg, -26, -28).

%rules
warm_place(X) :- weather(X, winter, warm).

north_of(X, Y) :- 
	location(X, Lat1, _Long1),
	location(Y, Lat2, _Long2),
	Lat1 > Lat2.
west_of(X,Y) :-
	location(X, _Lat1, Long1),
	location(Y, _Lat2, Long2),
	Long1 > Long2.

% arithmetic
double(X, Y) :- Y is 2 * X.
increment(X, Y) :- Y is 1 + X.
less_than_square_root(X, Y) :- Y < sqrt(X).
tangent(X,Y) :- Y is tan(X).
divides(X, Y) :- K is X mod Y, K=0.

father(bob, alice).
mother(sue, james).
mother(sue, alice).
mother(ann, sue).

dad(X,Y) :- father(X,Y).
parent(X,Y) :- father(X,Y); mother(X,Y).
child(X,Y) :- father(Y,X).
child(X,Y) :- mother(Y,X).
grandmother(X,Y) :- mother(X,Z), parent(Z, Y).

%ancestor(A,D) :- ancestor(A, P), ancestor(P, A).
ancestor(A,D) :- parent(A,D).
ancestor(A,D) :- parent(A,P), ancestor(P,D).

% Prolog Pair:  [ H | T ]
% Prolog Lists: [] or [Head | TailList]

first([], []).
first([H | _T], H).

lastelement([X], X).    % [X] = [X | [] ]
lastelement([_H | T], LastElement) :- lastelement(T, LastElement).

%get first 2 elements of a list
firsttwo([H1, H2 | _T], H1, H2).
firsttwo([H1, H2 | _T], [H1, H2]).

listsize([], 0) :- !.
listsize([_H | T], S) :- listsize(T, ST), S is ST + 1.

%firsttwoaresame(X) :- firsttwo(X, A, B), A=B.
%firsttwoaresame([H1, H2 | _T]) :- H1=H2.
firsttwoaresame([H, H | _T]).

size_at_least_3([_, _, _ | _T]).

%remove every other one
remeo([],[]).
remeo([X], [X]).
remeo([H, _ | T], [H | T1]) :- remeo(T, T1).


factorial(1,1) :- !.
factorial(N, F) :- N1 is N - 1, factorial(N1, F1), F is N * F1.


% Additional Prolog list rule examples

% Change everyting in a list to 'secret'
change([], []) :- !.   % base case
% add 'secret' to the front of the result, change the tail
%   noat secret is an atom so we do not need quotes
change([_H| T], [secret | T1]) :- change(T, T1).  
% test change
:- change([1, 2, 3], X), write(X), nl.


% base case
positive([], []) :- !.
% if H is less than 0, multiple H by -1 and add to the result
positive([H| T], [HP | T1]) :- H < 0, HP is H * -1, positive(T, T1).
positive([H| T], [H | T1]) :- positive(T, T1).
:- positive([-1, 2, -3], X), write(X), nl.



%::::::::::::::
%Prolog Notes 3
%::::::::::::::
fib(0,0) :- !.
fib(1,1) :- !.
fib(N,F) :-  
	N>1, 
	N1 is N-1, 
	N2 is N-2, 
	fib(N1,F1), 
	fib(N2,F2), 	
	F is F1 + F2.


fib2(N,N) :- N =< 1.
fib2(N,F) :-  
	N1 is N-1, 
	N2 is N-2, 
	fib2(N1,F1), 
	fib2(N2,F2), 	
	F is F1 + F2.

change(H, Q, D, N, P) :- 
	member(N, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]),
	member(D, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]),
	member(Q, [0, 1, 2, 3, 4]),
	member(H, [0, 1, 2]),
	S is ( (H * 50) + (Q * 25) + (D * 10) + (N * 5) ), 
	S =< 100, 
	P is 100 - S.

warm_blooded(cat).
warm_blooded(dog).
warm_blooded(chicken).
four_legs(cat).
four_legs(dog).
two_legs(chicken).
mammal0(M) :- warm_blooded(M), four_legs(M).
mammal1(M) :- !, warm_blooded(M), four_legs(M).
mammal1(godzilla).  % This fact never seen!
mammal2(M) :- warm_blooded(M), !, four_legs(M).
mammal2(mothra).
mammal3(M) :- warm_blooded(M), four_legs(M), !.
mammal3(rodan).

all_mammals1 :- mammal0(X), write(['Mammal', X]), nl.
all_mammals2 :- mammal0(X), write(['Mammal', X]), nl, fail.
all_mammals3(M) :- findall(X, mammal0(X), M).

get_digit(X) :-
	repeat,   % Create backtracking point - always succeeds
	write('Enter a digit:'),
	get0(X1),  % Get ascii character
	X1 > 47,   % X >= '0'
	X1 < 58,   % X <= '9'
	X is X1 - 48,  % Convert ASCII to digit
	!.

% Example of repeat
mammal :-
    repeat,
    write('What mammal do you want to know about? '),
    read(N),
    mammal0(N),
    write('Ok.  Try Google'),
    !.


% Example of assert/retract
:- dynamic month/1.  % allows us to assert more month facts
month(january).
month(february).
month(march).
month(april).
month(may).
show_months :- findall(X, month(X), Months), write(['Months', Months]), nl.

%7 ?- show_months.
%[Months,[january,february,march,april,may]]
%true.
%
%8 ?- assert(month(june)).
%true.
%
%9 ?- show_months.
%[Months,[january,february,march,april,may,june]]
%true.
%
%10 ?- retract(month(january)).
%true.
%
%11 ?- show_months.
%[Months,[february,march,april,may,june]]
%true.


%::::::::::::::
%Prolog Notes 4
%::::::::::::::
state(california).
state(arizona).
state(texas).
state(nevada).

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

