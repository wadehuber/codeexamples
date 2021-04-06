knows_scheme(bob).
knows_scheme(alice).
knows_prolog(alice).

passes_240(Student) :- knows_scheme(Student), knows_prolog(Student).

% math operatoins & functions
double(X, Y) :- Y is X * 2.
less_than_square_root(X, Y) :- Y < sqrt(X).
tangent(X, Y) :- Y is tan(X).
divides(X, Y) :- 0 is X mod Y.

% nutrition/5
% nutrition(Food, Calories, Fat, Carbs, Protein)
nutrition(egg, 85, 6, 1, 6).
nutrition(bacon, 38, 3, 0, 3).
nutrition(cereal, 130, 1, 28, 2).
nutrition(oatmeal, 150, 2, 25, 6).
nutrition(toast, 75, 0.96, 13, 2).
nutrition(fruit, 65, 0, 15, 1).
nutrition(milk, 1033, 2, 12, 8).

% lower_fat/2 - Food1 fat content < Foo2 fat content
lower_fat(Food1, Food2) :-
         nutrition(Food1, _, Fat1, _, _),
         nutrition(Food2, _, Fat2, _, _),
	 Fat1 < Fat2.

% lower_fat/3 - Which food has the lower fat content
lower_fat(Food1, Food2, Food1) :-
         nutrition(Food1, _, Fat1, _, _),
         nutrition(Food2, _, Fat2, _, _),
	 Fat1 < Fat2.
lower_fat(Food1, Food2, Food2) :-
         nutrition(Food1, _, Fat1, _, _),
         nutrition(Food2, _, Fat2, _, _),
	 Fat2 =< Fat1.

protein_content(Food, Protein) :- nutrition(Food, _, _, _, Protein).

more_protein(Food1, Food2) :-
         protein_content(Food1, Protein1),
         protein_content(Food2, Protein2),
	 Protein1 > Protein2.

% execute on consulting
:- nutrition(egg, Calories, Fat, _Carbs, Protein),
         write('Egg: '),
	 write(' Calories='), write(Calories),
	 write(' Fat='), write(Fat),
	 write(' Protein='), write(Protein),
	 nl.