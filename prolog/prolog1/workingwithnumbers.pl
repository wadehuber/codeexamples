
%avg_temp/2
avg_temp(berlin, 49).
avg_temp(karlsruhe, 60).
avg_temp(paris, 55).
avg_temp(belgrade, 52).
avg_temp(chicago, 50).
avg_temp(boston, 48).
avg_temp(johannesburg, 55).
avg_temp(phoenix, 80).
avg_temp(jerusalem, 61).

%avg_temp_celsius/2 - calculate the average temperature in Celsius
avg_temp_celsius(City, C_temp) :-    % head of the rule
                                 avg_temp(City, F_temp), % get the avg temp of City
				 C_temp is round((F_temp - 32) * 5 / 9).

play_outside(City) :- avg_temp_celsius(City, Temp), Temp < 15.

colder_than(City1, City2) :- 
                             avg_temp(City1, Temp1),
			     avg_temp(City2, Temp2),
			     Temp1 < Temp2.

% To check equality, use the same variable name!
same_temp(City1, City2) :-
                           avg_temp(City1, Temp),
                           avg_temp(City2, Temp),
			   City1 \= City2.
