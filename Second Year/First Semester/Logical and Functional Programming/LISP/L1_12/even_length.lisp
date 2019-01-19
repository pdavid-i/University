;(defun evennr(L - list)
(defun evennr(L)
    (= (mod (length L) 2) 0)
)

;(defun evennr(L) = T, length mod 2 = 0
;(defun evennr(L) = nill, length mod 2 = 1

(write (evennr '(5 1 2 (3 4)) ))