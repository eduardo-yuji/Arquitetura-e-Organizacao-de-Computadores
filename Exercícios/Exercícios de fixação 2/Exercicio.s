.data
	prompt: .asciiz "A soma dos vetores v0 e v1 é:  "
	v1: .word 10, 20, 30, 40, 50, 60 
	v2: .word 0, 10, -15, 16, 20, 30
	v3: .space 240

.text

	main:
		la $v0, v1	#recebe vetor 1
		la $t1, v2	#recebe vetor 2
		la $t2, v3	#recebe vetor 3
		li $t3, 0	#contador
		li $t4, 0
		li $t5, 0	#contador
		li $t6, 6

	loop:
		beq $t3, $t6, sair	#comparação
		addi $t3, $t3, 1	#Incrementa no contador
		addi $t2, $t2, 4	#adiciona 4 na posição
		add $t4, $t1, $t0	#soma
		sw $t4, v3($t2)
	
	sair:
		li $v0, 4
		la $a0, prompt
		syscall
		
	printf:
		beq $t5, $t6, sair	#comparação
		addi $t5, $t5, 1	#incrementa no contador
		li $v0, 1			
		add $a0, $zero, $t2
		syscall
	
	fim:
		li $v0, 10
		syscall