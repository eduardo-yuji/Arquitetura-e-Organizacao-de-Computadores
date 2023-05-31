.data

.text

main:

	li $t0, 100
	sw $t0, 4($sp)
	
	li $t1, 200
	sw $t1, 8($sp)
	
	li $t2, 300
	sw $t2, 12($sp)
	
	li $t3, 400
	sw $t3, 16($sp)
	
	li $t4, 500
	sw $t4, 20($sp)
	
	lw $t2, 12($sp)
	addi $t2, 50
	sw $t2, 12($sp)
	
	lw $t4, 8($sp)
	lw $t1, 20($sp)
	sw $t1, 8($sp)
	sw $t4, 20($sp)
	
	li $v0, 1
	add $a0, $zero, $t3
	syscall

	li $v0, 10
	syscall
