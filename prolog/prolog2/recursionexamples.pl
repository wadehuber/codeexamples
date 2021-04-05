% f(0) = 0
% f(1) = 2
% f(2) = 3
% f(n) = 2 * f(n-2) + f(n-1)

func(0,0) :- !.
func(1,2) :- !.
func(2,3) :- !.
func(N,S) :- N1 is N - 1, N2 is N - 2,
             func(N1, S1), func(N2, S2),
             S is (S2 * 2) + S1.

% censor/3
censor([],_,[]) :- !.
censor([H|T], CensoredValues, [censored | T1]) :- 
                  member(H, CensoredValues), !, 
                  censor(T, CensoredValues, T1).
censor([H|T], CensoredValues, [H | T1]) :- 
                  censor(T, CensoredValues, T1).

% Factorial
factorial(1,1) :- !.    % base case : 1! = 1
factorial(N, F) :- N > 1, N1 is N - 1, factorial(N1, F1), F is N * F1.

% Tail-recursive factorial
factorial_tail(N, F) :- factorial_tail(N, 1, F).
factorial_tail(1, F, F) :- !.
factorial_tail(N, PartialSolution, F) :-
               N > 1, 
               N1 is N - 1,
               NextPartialSolution is PartialSolution * N,
               factorial_tail(N1, NextPartialSolution, F).