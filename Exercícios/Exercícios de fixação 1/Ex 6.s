.data

.text
	main:
		addi $t1, $zero, $zero
		addi $t1, $zero, 5

		
		add $t3, $zero, $zero

	loop:
		beq $t0, $zero, sair
		add $t3, $t3, $t1
		addi $t0 , $t0, -1
		j loop

	sair:
		li $v0, 1
		add $a0, $zero, $t3
		syscall

		li $v0, 10
		syscall