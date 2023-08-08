#file: ex12_lista.s
#author: Sefora Davanso
#date: 12/09/22
#brief: Codifique em assembly do mips um programa correspondente a :

.data

.text
main: 

	li $t0, 1
	li $t1, 5
#registrador 
	li $t2, 1

#testando as condições
	bgt $t1, $t2, if

if:
	addi $t1, $t1, -1

#faremos t0  somado t1 vezes
	#quando t1 chegar a 0 ele sai do label
	beq $t1, $zero, sair
	#decrementar o t1 em uma unidade
	addi $t1, $t1, -1
	#soma o t0 no s0 
	#considerando que todo registrador é inicializado no 0
	add $s0, $s0, $t0
	#volta para o começo do label
	j if



