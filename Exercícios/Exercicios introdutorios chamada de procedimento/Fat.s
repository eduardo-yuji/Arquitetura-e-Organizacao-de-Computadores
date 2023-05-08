.data

.text
	main:
		li $a0, 5
		li $v0, 1 #fat
		li $t0, 1
		
		jal fat
		
		move $t1, $v0
		li $v0, 1
		move $a0, $t1
		syscall
		
		li $v0, 10
		syscall
		
	fat:
		addi $sp, $sp, -12
		sw $a0, 12($sp)
		sw $s0, 8($sp)
		sw $ra, 4($sp)
		
		beq $a0, $t0, sair
		slti $s0, a0, 1
		bne $s0, $zero, sair
		
		addi $a0, a0, -1
		jal fat
		
	sair:
		lw $a0, 12($sp)
		lw $s0, 8($sp)
		lw $ra, 4($sp)
		
		mul $v0, $v0, $a0
		jr $ra
