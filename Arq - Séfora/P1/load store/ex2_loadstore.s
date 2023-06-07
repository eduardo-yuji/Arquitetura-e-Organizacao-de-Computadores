#file: ex2_loadstore.s
#author: Sefora Davanso
#date: 09/09/22
#brief:Salve na memória o valor 100, na posição 20 usando como base o registrador $zero. 
# Depois salve 200 na posição 40.  

.data

#definindo strings
 string1: .asciiz "Carrega valores em posições de meória "


.text
 main:
 
#para printar a string 1
	li $v0, 4
	la $a0, string1
	syscall

# t0 recebe 100
# colocando nas posições de memoria i x 4
#se necessário printar o i basta /4
	li $zero, 100
	sw $zero, 80($sp)

#load para printar
	lw $zero, 80($sp)

#printando 
	li $v0, 1
	move $a0, $zero
	syscall

	li $zero, 200
	sw $zero, 160($sp)

#load para printar
	lw $zero, 160($sp)

#printando 
	li $v0, 1
	move $a0, $zero
	syscall
	
sair: 
	  li $v0, 10
	  syscall

