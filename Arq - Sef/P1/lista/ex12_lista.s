#file: ex12_lista.s
#author: Sefora Davanso
#date: 14/09/22
#brief: Codifique em assembly do mips um programa correspondente a :

.data

.text 	
main:
	
	#numero que será fatorado
	li $t0, 5
	#variavel pra 1
	li $t2, 1 

loop:
	#definindo caso base
	beq $t0, $zero, sai
	move $t1, $t0
	move $t3, $zero

	loop2:

		beq $t1, $zero, sai1
		add $t3, $t3, $t2
		addi $t1, $t1, -1
		j loop2

sai1: 
	move $t2, $t3
	addi $t0, $t0, -1
	j loop
		
sai:

#printando resultado
	li $v0, 1
	move $a0, $t2
	syscall

#saindo
	li $v0, 10
	syscall