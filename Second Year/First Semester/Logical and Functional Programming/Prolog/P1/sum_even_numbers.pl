sum_evens([], 0).
sum_evens([H|T], R):-
	mod(H,2)=:=0,
	sum_evens(T, RN),
	R is H + RN.

sum_evens([H|T], R):-
	mod(H,2)=\=0,
    sum_evens(T, RN),
	R is RN.