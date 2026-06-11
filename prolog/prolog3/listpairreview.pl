% review.pl
%
% Prolog Lists & PairsReview
%
% In Scheme, lists are built from pairs.
% In Prolog, lists are built from a similar head/tail structure:
%
%   [Head | Tail]
%
% The empty list is written as [].

% ------------------------------------------------------------
% Lists
% ------------------------------------------------------------

lst([1, 2, 3, 4, 5]).

% car in Scheme is like getting the head of a Prolog list.
car([H | _], H).

% cdr in Scheme is like getting the tail of a Prolog list.
cdr([_ | T], T).

% cadr means car of cdr.
cadr([_, Second | _], Second).

% cons in Scheme is like [Head | Tail] in Prolog.
cons(H, T, [H | T]).

% append works similarly to Scheme append.
append_lists(A, B, Result) :-
    append(A, B, Result).


% ------------------------------------------------------------
% Pairs
% ------------------------------------------------------------

% In Prolog, [Head | Tail] exposes the pair-like structure directly.
%
% Proper list:
%   [3 | []]
% Same as:
%   [3]
%
% Another proper list:
%   [m | [n, o, p, q]]
% Same as:
%   [m, n, o, p, q]

one_item_list([3 | []]).

letter_list([m | [n, o, p, q]]).

% Prolog can also write an improper pair-like structure:
%   [1 | 2]
%
% This is not a normal list, because the tail is not [] or another list.
% Most Prolog list predicates expect proper lists.
pair_like([1 | 2]).


% ------------------------------------------------------------
% Example list predicates
% ------------------------------------------------------------

% Add all numbers in a list.
add_list([], 0).
add_list([H | T], Result) :-
    add_list(T, Rest),
    Result is H + Rest.


% Build a new list where each number is divided by 2.
halve_each_element([], []).
halve_each_element([H | T], [Half | Rest]) :-
    Half is H / 2,
    halve_each_element(T, Rest).


% ------------------------------------------------------------
% Example queries
% ------------------------------------------------------------
%
%   sum_xyz(Result).
%
%   expression_result(Result).
%
%   square(10, Result).
%
%   x(X), square(X, Result).
%
%   x(X), z(Z), N is X * Z, square(N, Result).
%
%   lst(L), car(L, First).
%
%   lst(L), cdr(L, Rest).
%
%   lst(L), cadr(L, Second).
%
%   lst(L), cons(0, L, NewList).
%
%   cons([a, b, c], [1, 2, 3], Result).
%
%   append_lists([a, b, c], [1, 2, 3], Result).
%
%   one_item_list(Result).
%
%   letter_list(Result).
%
%   pair_like(Result).
%
%   add_list([10, 37, 39], Result).
%
%   lst(L), add_list(L, Result).
%
%   halve_each_element([37, 89, 42, 28], Result).

% ------------------------------------------------------------
% Auto-run examples when the file is consulted
% ------------------------------------------------------------
