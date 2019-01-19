(defun dot_product(L1 L2)
	(COND
		((and (NULL (CAR L1)) (NULL (CAR L2))) 0)
		(t(+ (* (CAR L1) (CAR L2)) (dot_product (CDR L1) (CDR L2)) ))
	)

)

;defun dot_produt(L1 L2) = a1*b1 + a2*b2 + .... an * bn
;defun dot_produdt(L1 L2) = 0 L1 = L2 = null

(WRITE (dot_product '(5 -5) '(6 -6)))