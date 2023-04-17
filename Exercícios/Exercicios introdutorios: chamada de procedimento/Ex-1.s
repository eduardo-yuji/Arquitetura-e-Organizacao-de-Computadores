.data
	print: .asciiz "digite um valor inteiro: "
	print2: .asciiz "Soma: "

.text
	main:
		li $v0, 4
		la $a0, print
		syscall
		
		li $v0, 5
		syscall
		la $t0, 0($v0)
		
		li $v0, 4
		la $a0, print
		syscall
		
		li $v0, 5
		syscall
		la $t1, 0($v0)
		
		
		
		jal soma
		
		move $t0, $v0
		
		li $v0, 4
		la $a0, print2
		syscall
		
		li $v0, 1
		move $a0, $t0
		syscall
		
		li $v0, 10
		syscall
		
		soma:
			addi $sp, $sp, -12
			sw $s0, 8($sp)
			sw $ra, 4($sp)
			
			add $v0, $t0, $t1
			
			lw $s0, 8($sp)
			lw $ra, 4($sp)
			addi $sp, $sp,12
			
			jr $ra
			
			
			
			
