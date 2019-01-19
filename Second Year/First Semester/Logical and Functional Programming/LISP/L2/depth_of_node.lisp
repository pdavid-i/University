; A binary tree is memorised in the following way:
;(node no-subtrees list-subtree-1 list-subtree-2 ...)

;Return the level (depth) of a node in a tree of type (1). The level of the root element is 0.
;______________________________________________________________________________________________



; FIRSTN takes as parametres a list and an integer n and returns the first n elements of the list
;FIRSTN(l n) = (l1, l2, l3, .. ln) where l  = (l1, l2, l3 ... lm), if n <=m
;			 = (l1  l2, ... lm)  
(DEFUN FIRSTN (LIST N)
  (IF (OR (ATOM LIST) (< N 1))
      LIST
      (DO ((NEW-LIST '() (CONS (CAR L) NEW-LIST))
           (L LIST (CDR L))
           (I 0 (1+ I)))
          ((= I N) (NREVERSE NEW-LIST))
        (WHEN (ATOM L) (RETURN (NRECONC NEW-LIST L))))))

;Complementary to FIRSTN, NOTFIRSTN returns all the elements remaining after the first N have been removed
;Therefore: FIRSTN(L N) + NOTFIRSTN(L N) = L
;NOTFIRSTN(L N) = L - FIRSTN(L N)
(defun NOTFIRSTN(L P)
    (if (> P 0)
        (NOTFIRSTN (cdr L) (- P 1))
        L
    )
)

;just a wrapper function so we dont have to have add 0 as the initial
;depth every time we want to call find_depth
(defun wrapper(Tree value)
		(find_depth Tree value 0)
)

;computes the minimum between 2 numbers
;minim(a b) = {a, a<b
;			  {b, b<a
(defun minim(a b)
	(if (< a b)
		a
		b
	)
)

;returns the depth at wich a given element is found

;find_depth(Tree value level) = {level, if t1 == value, where t1 is the first node of the tree
;								{find_dept(LeftSubtree, value, level+1), if the tree has kids and LeftSubtree is bigger
;								{find_dept(RightSubtree, value, level+1), if the tree has 2 kids and RightSubtree is bigger
	;							{9999 if the node can not be found
(defun find_depth(Tree value level)

		(if (equal (CAR Tree) value)
		level
		(
			
			cond
			;((equal (CAR Tree) value) level)
			( (= (CAR (CDR Tree)) 0) 9999)
			( (= (CAR (CDR Tree)) 1) (find_depth (CDR (CDR Tree)) value (+ level 1))  )
			( (= (CAR (CDR Tree)) 2)
				 (minim (find_depth (FIRSTN (CDR (CDR Tree)) (get_left_length (CDR (CDR Tree)))) value (+ level 1))  	
				      (find_depth (NOTFIRSTN (CDR (CDR Tree)) (get_left_length (CDR (CDR Tree)))) value (+ level 1)) )  
			)
	
		)
	)
)

;A functions that takes parametre a Tree and retruns the length of its left subtree
(defun get_left_length(Tree)
	(defvar valu (CAR (CDR Tree)))
	(defvar remaining (CDR (CDR Tree)))
	(defvar length 2)
    
    (loop while (> valu 0) do
        (setq length (+ length 2))
        (setq valu (+ valu (CAR(CDR remaining))))
        (setq valu (- valu 1))
        (setq remaining (CDR(CDR remaining)))
    )
    length
)

(write (wrapper '(A 2 B 0 C 2 D 0 E 0) 'A))
