.data

.text

main:

li $t0, 0

beq $t0, $zero, if

else:
	li $t0, 10
	j sair
if:
	li $t0, 5

sair:
	li $v0, 1
	add $a0, $zero, $t2
	syscall

	li $v0, 10
	syscall
