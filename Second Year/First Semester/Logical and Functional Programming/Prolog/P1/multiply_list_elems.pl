%Multiply elements of a list with a constant value
%%multiply_list_elems = (k - integer, L - initial list, R - Resulted List)
%multiply_list_elems = (i, i, o) 
multiply_list_elems(_, [], []).
multiply_list_elems(K, [H|T], [HR|TR]):- 
    HR is H*K,
    multiply_list_elems(K, T, TR).

%multiply_list_elems(2, [1, 2, 3, 4], R)