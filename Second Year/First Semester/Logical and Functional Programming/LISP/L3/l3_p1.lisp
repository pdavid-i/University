;Write a function  to check if an atom is member of
;a list (the list is non-liniar)

;
;does_list_contain(l, element) = { 0, V e E l e != element 
;						{ 1, exists e E l such that e = element

(defun does_list_contain (l element)
	(cond
		((and(numberp l) (= element l))  1)
		((listp l) (apply 'max (mapcar #' (lambda (a) (does_list_contain a element)) l)    ) )
		(t 0)
	)
)


(write (does_list_contain '(1 2 3 (2 3) 5 9) 9))