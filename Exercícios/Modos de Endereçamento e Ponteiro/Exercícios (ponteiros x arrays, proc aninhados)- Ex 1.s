.data
print: .asciiz "Digite um número inteiro: "

.text
main:
	li $v0, 4
	la $a0, print
	syscall
	
	li $v0, 5
	syscall
	move $t0, $v0
	
	addi $t1, $t0, 0
	li $t3, 1
	
somador:
	slti, $t2, $t0, 1
	beq $t2, $zero, if
	
	j sair
	
if:
	addi $t0, $t0, -1
	add $t1, $t0, $t1
	j somador		
	

	
sair:
	li $v0, 1
	move $a0, $t1
	syscall

	
	li $v0, 10
	syscall
