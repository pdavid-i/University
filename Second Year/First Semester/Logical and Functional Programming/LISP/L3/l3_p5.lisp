;Write a function that computes the sum of
;all even numbers and substracts from that
;all the odd numbers


;					  {  (), if L is empty or a literal
;even_minus_odd(l) = { l1 + even_minus_odd(l2, l3, ....., ln), l1 is number and l1 % 2 == 0
;					 { -l1 + even_minus_odd(l2, l3, ....., ln), l1 is number and l1 % 2 == 1
;				      { even_minus_odd(l1) + even_minus_odd(l2, l3, .... ln). l1 is a list



(defun even_minus_odd(l)
	(cond
		((and (numberp l)(=(mod  l 2) 0))  l)
		((and (numberp l)(=(mod  l 2) 1))  (* -1 l))
		(t (apply '+ (mapcar 'even_minus_odd l)))
	)
)

(write (even_minus_odd '(2 3 4 (1 (-3) 2) 5 6)))