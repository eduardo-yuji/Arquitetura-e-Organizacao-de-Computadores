.data
	prompt: .asciiz "digite um numero inteiro"
.text

	main:
		li $v0, 4
		la $a0, prompt
		syscall
		
		li $v0, 5
		syscall
		la $t0, 0($v0)
		
		li $v0, 4
		la $a0, prompt
		syscall

		li $v0, 5
		syscall
		la $t1, 0($v0)

		#comparacao
		beq $t0, $t1, igual
		
	else:
		slt $s1, $t0, $t1
		beq $s1, 1, if
		add $t2, $t0, $zero
		j sair
	if:
		add $t2, $t1, $zero
		j sair

	igual:
		li $t2, -111
		
		li $v0, 1
		add $a0, $zero, $t2
		syscall

		li $v0, 10
		syscall
		
	sair:
		li $v0, 1
		add $a0, $zero, $t2
		syscall

		li $v0, 10
		syscall