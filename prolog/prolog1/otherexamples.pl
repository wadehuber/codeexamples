% simple rule to show the difference between <space> and <enter>

% if X is 1, then return the atom one
% if X is even, return the atom even
spaceenter(1, one).
spaceenter(X, even) :- 0 is X mod 2.
