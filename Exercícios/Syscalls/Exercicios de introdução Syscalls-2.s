.data
	prompt: .asciiz "digite um numero inteiro: "
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
	
		sub $t2,$t0,$t1

		li $v0,1
		move $a0,$t2
		syscall
	
		li $v0,10
		syscall