.data
	prompt: .asciiz "digite o primeiro numero inteiro POSITIVO: "
	prompt2: .asciiz "digite o segundo numero inteiro POSITIVO: "
.text

	main:
		li $v0, 4
		la $a0, prompt
		syscall
		
		li $v0, 5
		syscall
		la $t0, 0($v0)
		
		li $v0, 4
		la $a0, prompt2
		syscall

		li $v0, 5
		syscall
		la $t1, 0($v0)

		
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