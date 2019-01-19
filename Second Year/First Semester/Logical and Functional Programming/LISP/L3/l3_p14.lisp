;14. Write a function that returns the number of atoms in a list, 
;at any level


;				      { 0, if L is empty or a literal
;count_elements(l) = { 1 + count_elements(l2, l3, ....., ln), l1 is number
;					  { count_elements(l1) + count_elements(l2, l3, .... ln). l1 is a list

(defun count_elements(l)
	(cond
		((numberp l) 1) 
		((list l) (apply '+ (mapcar 'count_elements l)))
		(t 0)
	)

)

(write (count_elements '(1 2 3 (2 3) 4 5) ))