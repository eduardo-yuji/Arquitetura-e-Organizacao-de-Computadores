#file: ex11_lista.s
#author: Sefora Davanso
#date: 12/09/22
#brief: Codifique em assembly do mips um programa correspondente a :

.data

.text
main:
	li $t0, 0
	li $t1, 10
	li $t2, 0

while:

#quando t0 < t1  -> s0 = 1
	slt $s0, $t0, $t1
#caso a comparação for verdadeira o s0 =! 0 e ele irá para o jaime
	bne $s0, $zero, jaime
	beq $s0, $zero, sair

jaime:
	addi $t0, $t0, 1
	addi $t2, $t2, 10
	j while


sair: 
#printando 
	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 1
	move $a0, $t2
	syscall

	li $v0, 10
	syscall
