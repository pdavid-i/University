;Write a function that returns the sum of numeric atoms in a list,
; at any level


;					{  (), if L is empty or a literal
;compute_sum(l) = { l1 + compute_sum(l2, l3, ....., ln), l1 is number
;					{ compute_sum(l1) + compute_sum(l2, l3, .... ln). l1 is a list

(defun compute_sum(l)
	(cond
		((numberp l) l) 
		((list l) (apply '+ (mapcar 'compute_sum l)))
	)

)

(write (compute_sum '(1 2 3 (2 3) 4 5) ))