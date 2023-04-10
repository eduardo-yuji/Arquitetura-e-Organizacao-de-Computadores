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
		
		#comparacao
		beq $t0, 10, igual
		
	sair:
		li $v0, 1
		add $a0, $zero, $zero
		syscall

		li $v0, 10
		syscall

	igual:
		li $v0, 1
		add $a0, $zero, $t0
		syscall

		li $v0, 10
		syscall