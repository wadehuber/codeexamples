order(a,1).
order(b,2).
order(c,3).
order(x,24).
order(y,25).
order(z,26).

medal(1,gold).
medal(2,silver).
medal(3,bronze).

combo(1).
combo(2).
combo(3).
combo(5).
combo(7).

% variable assignment
combination(A,B,C) :- combo(A), combo(B), combo(C).

% singleton variable
medal_winner(Place) :- medal(Place,Color).
