;Define a function to tests the 
;membership of a node in a n-tree
;represented   as   (root list_of_nodes_subtree1 ... list_of_nodes_subtreen) 

;
;does_tree_contain(l) = { 0, V e E l e != element 
;						{ 1, exists e E l such that e = element

(defun does_tree_contain(tree element)
	(cond
		((and (atom tree) (= tree element) ) 1)
		((listp tree) (apply 'max (mapcar #' (lambda (a) (does_tree_contain a element)) tree)))
		(t 0)
	)
)

(write (does_tree_contain '(g (b (c)) (d) (E (f))) 'f))