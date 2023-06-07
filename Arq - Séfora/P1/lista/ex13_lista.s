#file: ex13_lista.s
#author: Sefora Davanso
#date: 14/09/22
#brief: Implementar o código correspondente em mips

.data
	vetor: .word 3, 0, 1, 2, -6, -2, 4, 10, 3, 7, 8, -9, -15, -20, -87, -100
	string: .asciiz "Digite um numero inteiro para ser procurado no vetor: "
	string1: .asciiz "Elemento não encontrado"

.text
	
main:

#declarando a string
	li $v0, 4
	la $a0, string
	syscall

#recebendo valor do teclado
	li $v0, 5
	syscall
	move $t0, $v0

#declarando o vetor
	la $s0, vetor
	li $t3, -100

loop:
	sll $t4, $t1, 2
	#anda uma pos no vetor
	add $s1, $s0, $t4
	#pega o elemento da pos
	lw $t2, 0($s1)
	
	#compara para caso for o elemento
	beq $t0, $t2, sair2

	#compara se chegou no ult elemento, para caso não encontrar
	beq $t2, $t3, sair1

	#anda uma posição no vetor
	addi $t1, $t1, 1
	j loop


sair2:
	#declarando a string
	li $v0, 1
	move $a0, $t2
	syscall

	li $v0, 10
	syscall

sair1:
	#declarando a string
	li $v0, 4
	la $a0, string1
	syscall

	li $v0, 10
	syscall