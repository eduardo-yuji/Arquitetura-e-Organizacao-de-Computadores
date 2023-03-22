.data

.text
	main:
    		li $t0, 50
    		sw $t0, 40($sp)
 
	 	li $t1, 100
    		sw $t1, 56($sp)
 

	    	lw $t2,40($sp) 
		lw $t3,56($sp)
	
		add $t4,$t2,$t3
    
	 	li $v0, 1
	  	move $a0, $t4
	 	syscall
	    
	 	li, $v0, 40
	  	syscall
