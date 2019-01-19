;(defun compute(L - list nrops - integer)
(defun compute(L nrops)
    (cond
        ((and (= nrops 0) (equal (car L) '+)) (+ (compute (cdr L) nrops) (compute (cdr L) (+ nrops 1))))
        ((and (= nrops 0) (equal (car L) '-)) (- (compute (cdr L) nrops) (compute (cdr L) (+ nrops 1))))
        ((and (= nrops 0) (equal (car L) '*)) (* (compute (cdr L) nrops) (compute (cdr L) (+ nrops 1))))
        ((and (= nrops 0) (equal (car L) '/)) (/ (compute (cdr L) nrops) (compute (cdr L) (+ nrops 1))))
        ((and (= nrops 0) (numberp (car L))) (car L))
        ((and (/= nrops 0) (numberp (car L))) (compute (cdr L) (- nrops 1)))
        (t (compute (cdr L) (+ nrops 1)))
    )
)

;(defun compute(L nrops) = computation result of the epression nrops


;(write (compute '(+ 3 4) 0))
;(write (compute '(+ * 2 4 3) 0))
(write (compute '(+ * 2 4 - 5 * 2 2) 0))