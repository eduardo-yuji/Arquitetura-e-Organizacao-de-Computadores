.data
	save: .word 0, 0, 0, 0, 0, 5, 6, 7

.text

	main:
		la $t0, save		#carrega o endereço do vetor save
		li $t1, 0		#Recebe 0
		li $t2, 0		#Recebe 0

	while:
		sll $t3, $t2, 2		#t3 recebe 2 posições de endereço a esquerda de t2
		add $s0, $t3, $t0	#adiciona o valor de t3 em s0
		lw $s1, 0($s0)		#carrega o endereço de s0 em s1
		bne, $s1, $t1, sair	#compara o valor de t1 com s1, se diferente > sair
		addi $t2, $t2, 1	#adiciona 1 no contador
		j while			#jump

	sair:
		li $v0, 1		#print
		add $a0, $zero, $t2
		syscall

	li $v0, 10
	syscall