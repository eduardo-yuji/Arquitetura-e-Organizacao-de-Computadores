#file: ex3_desvios.s
#author: Sefora Davanso
#date: 05/09/22
#brief:Faça um programa, em assembly do mips, que receba dois inteiros do teclado, e imprima o maior. 
# Se os números forem iguais imprima -111.





.data
	string: .asciiz "Digite um valor inteiro a: "
	string1: .asciiz "Digite um valor inteiro b: "


.text
main:

#declarando -111 e 1
	li $t2, -111
	li $t4, 1

#printar a string 
	li $v0, 4
	la $a0, string
	syscall

#recebendo o primeiro inteiro do teclado
	li $v0, 5
	syscall
	move $t0, $v0

#printar a string1 
	li $v0, 4
	la $a0, string1
	syscall

#recebendo o primeiro inteiro do teclado
	li $v0, 5
	syscall
	move $t1, $v0

#comparando se os dois são iguais
	beq $t0, $t1, else
#se t0 for menor que t1 t3 = 1
	slt $t3, $t0, $t1
	beq $t3, $t4, else2
#se t1 for menor que t0 t4 = 1
	slt $t3, $t1, $t0
	beq $t3, $t4, else3

else:
#printando o -111, por serem iguais
	li $v0, 1
	move $a0, $t2
	syscall
	j sair

else2:
#printa t1
	li $v0, 1
	move $a0, $t1
	syscall
	j sair

else3:
#printa t0
	li $v0, 1
	move $a0, $t0
	syscall
	j sair

sair:
	li $v0, 10
	syscall


