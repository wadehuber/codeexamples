% sort_examples.pl
% This file shows two sorting approaches in Prolog:
%
%   1. Permutation sort
%      Declarative, but very inefficient.
%      Main idea: generate a permutation, then check if it is sorted.
%   2. Merge sort
%      A more practical recursive sorting algorithm.
%      Main idea: split the list, sort each half, then merge them.

% ------------------------------------------------------------
% Permutation sort
% ------------------------------------------------------------
is_sorted([]).
is_sorted([_]).
is_sorted([H1, H2 | T]) :-
    H1 =< H2,
    is_sorted([H2 | T]).

perm_sort(List, Sorted) :-
    permutation(List, Sorted),
    is_sorted(Sorted).


% ------------------------------------------------------------
% Merge sort
% ------------------------------------------------------------
merge_sort([], []).
merge_sort([X], [X]).
merge_sort(List, Sorted) :-
    split(List, Left, Right),
    merge_sort(Left, SortedLeft),
    merge_sort(Right, SortedRight),
    merge(SortedLeft, SortedRight, Sorted).


% ---- Merge sort helper methods -----------------------------
% split(List, Left, Right)
% Splits a list into two smaller lists by alternating items.
%
% Example:
%   split([4, 8, 15, 16, 23, 42], Left, Right).
% Result:
%   Left = [4, 15, 23]
%   Right = [8, 16, 42]
split([], [], []).
split([X], [X], []).
split([X, Y | Rest], [X | Left], [Y | Right]) :-
    split(Rest, Left, Right).

% merge(Left, Right, Result)
% Merges two already-sorted lists into one sorted list.
merge([], Right, Right).
merge(Left, [], Left).

merge([X | Xs], [Y | Ys], [X | Rest]) :-
    X =< Y,
    merge(Xs, [Y | Ys], Rest).

merge([X | Xs], [Y | Ys], [Y | Rest]) :-
    X > Y,
    merge([X | Xs], Ys, Rest).


% Example queries
%   perm_sort([4, 2, 7, 1, 3], Sorted).
%   merge_sort([4, 2, 7, 1, 3], Sorted).
