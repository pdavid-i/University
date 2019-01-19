; 6. Write a function that returns the maximum of numeric atoms in a list, at any level.


;				 { (), L is empty
; list_max(l) = { l, l is a number
;				 { max(l1 l2 .... ln), l is a list


(defun list-max (l)
	(cond
		((numberp l) l)
		((listp l) (apply 'max (mapcar 'list-max l)))
	)
)

(print (list-max '(1 2 (2 3) (4 5 19))))