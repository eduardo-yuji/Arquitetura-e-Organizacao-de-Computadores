.data
	fat:    .word 0 		# armazena o valor do fatorial
	n:      .word 5 		# armazena o valor do número para calcular o fatorial
	msg:    .asciiz "O fatorial é: "# mensagem a ser impressa na tela

.text
	main:   
		lw $t0, n 		# carrega o valor de n em $t0
		li $t1, 1 		# inicializa fat com 1
	
	loop:  
		beq $t0, $zero, end 	# se n == 0, saia do loop
		mul $t1, $t1, $t0   	# fat = fat * n
		addi $t0, $t0, -1    	# n = n - 1
		j loop 			# volta ao início do loop
		
	mul:
		beq $t0, $zero, sair
		add $t3, $t3, $t1
		addi $t0 , $t0, -1
		j loop
		
	end:    
		sw $t1, fat 		# salva o valor do fatorial em fat
		la $a0, msg 		# carrega o endereço da mensagem em $a0
		li $v0, 4 		# carrega o código da syscall para imprimir uma string
		syscall                 # imprime a mensagem na tela
		lw $a0, fat        	# carrega o valor do fatorial em $a0
		li $v0, 1          	# carrega o código da syscall para imprimir um inteiro
		syscall                 # imprime o fatorial na tela
		li $v0, 10         	# carrega o código da syscall para sair do programa
		syscall                 # finaliza o programa
