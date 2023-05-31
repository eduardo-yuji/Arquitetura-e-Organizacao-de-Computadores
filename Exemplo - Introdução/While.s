.data

.text

main:

li $t0, 0

while:
	slti $s1, $t0, 10
	beq $s1, $zero, sair
	addi $t0, $t0, 1
	j while

sair:
	li $v0, 1
	add $a0, $zero, $t3
	syscall

	li $v0, 10
	syscall	
