#file: ex10_lista.s
#author: Sefora Davanso
#date: 12/09/22
#brief: Codifique em assembly do mips um programa correspondente a :

.data


	

.text
 main:
 	li $t0, -1
	li $t1, 60
	li $t2, 0
	li $t3, 1
	li $t4, 50

#fazendo a comparação
#se t0 < 0   -> s0 = 1
	slt $s0, $t0, $zero
#caso já a primeira condição nao for atendida o x = 0
	beq $s0, $t3, xzero
#caso a s0 = q devemos testar a segunda condição
# t1>t2
	bgt $t1, $t4, xum

xum:
	addi $t2, $t2, 1
	li $v0, 1
	move $a0, $t2
	syscall
	j sair	

xzero:	
	li $v0, 1
	move $a0, $t2
	syscall
	j sair
	
sair: 
	  li, $v0, 10
	  syscall

