#file: ex8_lista.s
#author: Sefora Davanso
#date: 13/09/22
#brief:Faça um programa, em assembly do MIPS,
# que receba e multiplique dois inteiros sem usar a instrução de multiplicação do MIPS. Imprima o resultado na tela.

.data
	string: .asciiz "Este programa multiplica dois inteiros
Digite um inteiro a:"
	string1: .asciiz "Digite um inteiro b: "

.text
main:

#printando as strings e recebendo valores

	li $v0, 4
	la $a0, string 
	syscall

	li $v0, 5
	syscall
	move $t0, $v0

	li $v0, 4
	la $a0, string1
	syscall

	li $v0, 5
	syscall
	move $t1, $v0

#faremos t0  somado t1 vezes

multiplica:
	#quando t1 chegar a 0 ele sai do label
	beq $t1, $zero, sair
	#decrementar o t1 em uma unidade
	addi $t1, $t1, -1
	#soma o t0 no s0 
	#considerando que todo registrador é inicializado no 0
	add $s0, $s0, $t0
	#volta para o começo do label
	j multiplica

sair:

#devemos printar o resultado da soma 
	li $v0, 1
	move $a0, $s0
	syscall

	li $v0, 10
	syscall
	