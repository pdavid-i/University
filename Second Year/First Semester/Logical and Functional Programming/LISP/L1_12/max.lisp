;(defun firstEl(L - integer)
(defun firstEl(L)
    (cond
        ((null L) -1)
        ((numberp (car L)) (car L))
        (t (firstEl (car L)))
    )
)

;(defun firstEl(L) = nill, L is empty
;(defun firstEl(L) = l1 otherwise

;(defun maxP(L - list)
(defun maxP(L)
    (maxS L (firstEl L))
)

;(defun maxP(L) = nill, L is empty
;(defun maxP(L) = l1 otherwise
    
;(defun maxS(L-list mx-integer)
(defun maxS(L mx)
    (cond
        ((null L) mx)
        ((numberp (car L)) (maxS (cdr L) 
                                 (max (car L) mx)))
        ((listp (car L)) (maxS (cdr L) (maxS (car L) mx)))
    )
)
;(defun maxS(L) = nill, L is empty
;(defun maxS(L) = l1 otherwise
(write (maxP '(0 1 (2 (3) ((5)) (1)))))