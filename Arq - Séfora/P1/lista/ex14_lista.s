#file ex14_lista.s
#Name: Sefora Davanso
#date 14/09/2022
#brief: Faça um programa, em assembly do mips, para somar dois vetores (V1 e V2) onde:

.data
	vetor1: .word 10, 20, 30, 40, 50, 60
	vetor2: .word 0, 10, -15, 16, 20, 30

.text
main:

#declarar o vetor
	la $s1, vetor1
	la $s2, vetor2

	li $t0, 60

while:
	#ajustar i 
	sll $t4, $t1, 2
	add $s3, $s1, $t4
	add $s4, $s2, $t4
	lw $t2, 0($s3)
	lw $t5, 0($s4)
	
	add $t6, $t2, $t5
	
	#printar t6
	li $v0, 1
	move $a0, $t6
	syscall
	beq $t2, $t0, sair
	addi $t1, $t1, 1
	j while

	

sair:
	li $v0, 10
	syscall