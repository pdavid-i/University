;Write a function that returns the product of 
;numeric atoms in a list,
;at any level


;						{  (), if L is empty or a literal
;compute_product(l) = { l1 + compute_product(l2, l3, ....., ln), l1 is number
;						{ compute_product(l1) + compute_product(l2, l3, .... ln). l1 is a list


(defun compute_product(l)
	(cond
		((numberp l) l) 
		((list l) (apply '* (mapcar 'compute_product l)))
	)

)

(write (compute_product '(1 2 3 (2 3) 4 5)))