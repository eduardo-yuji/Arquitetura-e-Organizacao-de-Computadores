.data

.text

main:
	li $t0, 2		#a = 2
	li $t1, 10		#b = 10
	li $t2, 0		#x = 0
	
	slt $t3, $zero, $t0 
	bne $t3, $zero, compara2
	
	else:
		j sair
	
	compara2:
		slti $t3, $t1, 50
		bne $t3, $zero, if
		
	if:
		addi $t2, 1
		j sair
		
	sair:
		li $v0, 1
		add $a0, $zero, $t2
		syscall

		li $v0, 10
		syscall
