.data

.text

main:
	li $t0, 0		#i = 0
	li $t1, 10		#j = 10
	li $t2, 0		#k = 0
	
	slt $t3, $t0, $t1 
	beq $t3, 1, while
	
	sair:
		li $v0, 1
		add $a0, $zero, $t0
		syscall
		
		li $v0, 1
		add $a0, $zero, $t2
		syscall

		li $v0, 10
		syscall
		
	while:
		addi $t0, $t0, 1
		addi $t2, $t2, 10
		slt $t3, $t0, $t1 
		beq $t3, 1, while
		j sair
		
	
