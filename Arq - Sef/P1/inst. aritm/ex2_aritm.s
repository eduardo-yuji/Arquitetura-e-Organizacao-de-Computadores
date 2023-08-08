#file: ex2_aritm.s
#author: Sefora Davanso
#date: 24/08/22
#brief:Faça o registrador $t0 e $t1 receberem os valores 10, e 20 respectivamente. 
# E então faça um programa para resolver a seguinte expressão:

.data

#definindo strings
 string1: .asciiz "Calcula uma expressão "


.text
 main:
 
#para printar a string 1
	li, $v0, 4
	la $a0, string1
	syscall

# $t0 recebe 10 e t1 20
	li $t0, 10
	li $t1, 20

# estou fazendo a expressão e salvando em  t2
	addi $t0, $t0, 4
	addi $t1, $t1, -6
	sub  $t2, $t0, $t1

#printando 
	li $v0, 1
	move $a0, $t3
	syscall
	
sair: 
	  li $v0, 10
	  syscall

