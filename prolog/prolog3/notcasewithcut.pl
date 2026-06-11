% A cut lets the next clause serve as the "else" branch so 
% you don't have to restate (or negate) the condition you already tested.

% larger(X, Y, Max)  Max is the greater of X and Y.
larger(X, Y, X) :- X >= Y, !.   % if X >= Y, Max is X, so commit to this choice
larger(_, Y, Y).                % else: Max is Y (no need to write X < Y)

% classify(X, List, Result)
classify(X, List, present) :- member(X, List), !.
classify(_, _, absent).

% adult_status(Age, Status) under 18 is not_adult, otherwise adult.
adult_status(Age, not_adult) :- Age < 18, !.
adult_status(_, adult).         % else: 18 or over (no need to write Age >= 18)
