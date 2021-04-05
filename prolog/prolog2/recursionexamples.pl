% f(0) = 0
% f(1) = 2
% f(2) = 3
% f(n) = 2 * f(n-2) + f(n-1)

func(0,0) :- !.
func(1,2) :- !.
func(2,3) :- !.
func(N,S) :- N1 is N - 1, func(N1, S1), N2 is N - 2, func(N2, S2), 
             S is S1 + (S2 * 2).


% censor
censor([], _, []) :- !.
censor([H|T], Vals, [censored | TRest]) :- member(H, Vals), !, 
                                           censor(T, Vals, TRest).
censor([H|T], Vals, [H | TRest]) :- !, censor(T, Vals, TRest).

factorial(1,1).    % base case: 1! = 1
factorial(N,F) :- N > 1, N1 is N - 1, factorial(N1, F1), F is N * F1.

factorial_tail(N, F) :- factorial_tail(N, 1, F).
factorial_tail(0, F, F) :- !.
factorial_tail(N, Acc, F) :- 
    N1 is N - 1,
    NewAcc is Acc * N, 
    factorial_tail(N1, NewAcc, F).

