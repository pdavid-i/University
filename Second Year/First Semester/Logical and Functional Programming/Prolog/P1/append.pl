%Appends an element to a list
%append_elem(L - initial list, E - element to append, R - resulted list)
%multiply_list_elems = (i, i, o) 
append_elem([], E, [E]).
append_elem([H|T], E, [H|R]):-
	append_elem(T, E, R).
%append_elem([1, 2, 3, 4], 5, R)