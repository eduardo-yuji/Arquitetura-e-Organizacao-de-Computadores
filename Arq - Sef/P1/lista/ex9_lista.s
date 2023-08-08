#file: ex9_lista.s
#author: Sefora Davanso
#date: 13/09/22
#brief: Codifique um programa correspondente ao seguinte código em c:

.data


.text
main:

#registradores
	li $t0, 3
	li $t1, 2
	li $t2, 10

	li $t4, 1

#igualando t0 e t2
	move $t2, $t0

#faremos a comparação
# se t1<t2 (b<m) o t3 = 1
	slt $t3, $t1, $t2
	beq $t3, $t4, else
	beq $t3, $t5, if

if:
#printar o m = a
	li $v0, 1
	move $a0, $t2
	syscall
	j sair

else:
#printar m = b
	move $t2, $t1
	li $v0, 1
	move $a0, $t2
	syscall

sair:
	li $v0, 10
	syscall