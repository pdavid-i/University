;Write a function  that substitutes an element 
;through another one at all
;levels of a given list


;
;					{ () , l is not a list nor a number
;replace_elem (l e r) = { r, if l is a number and l == e
;				   { l, if l is a number and l != e
;					{ replace (l1 e r) U replace(l2 e r) U ..... U replace (ln e r), if l (l1, l2, l3, ... ln) is a list

(defun replace_elem (l e r)
    (cond
        ((and (numberp l) (if (= l e) r l)))
        ((listp l) (mapcar #'(lambda (a) (replace_elem a e r)) l) )
    )
)

(print (replace_elem '(1 2 (1 2 (3 1) 2)) 10 9))