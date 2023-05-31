.data

.text

main:
	li $t0, 3
	li $t1, 4
	li $t2, 10
	addi $t2, $t0, 0
	slt $t3, $t1, $t2 
	beq $t3, $zero, if
	
	else:
		j sair
	
	if:
		addi $t2, $t1, 0
		
	sair:
		li $v0, 1
		add $a0, $zero, $t2
		syscall

		li $v0, 10
		syscall
