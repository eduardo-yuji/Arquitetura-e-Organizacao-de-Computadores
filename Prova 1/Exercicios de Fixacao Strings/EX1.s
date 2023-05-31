.data
	string1: .asciiz "a b c d e"
	string2: .asciiz ""

.text
main:
	la $s0, string1
	la $s1, string2
	li $t1, 0
	
loop:
	lb $t2, ($s0)
	sb $t2, ($s1)
	
	addi $s0, $s0, 1
	addi $s1, $s1, 1
	
	addi $t1, $t1, 1
	
	blt $t1, 5, loop
	
	li $t1, 0
	
saida:
	lb $t2, ($s1)
	li $v0, 4
	la $a0, string2
	syscall
	addi $s1, $s1, 1
	addi $t1, $t1, 1
	blt $t1, 5, saida
	li $v0, 10
	syscall
