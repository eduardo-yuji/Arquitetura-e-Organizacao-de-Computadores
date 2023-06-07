.data
	string: .asciiz "Digite um numero:"
      string1: .asciiz "Quantidade de iterações:"

.text 
main:
 

#printando a string 
	li $v0, 4
	la $a0, string
	syscall

#recebendo do teclado
	li $v0, 5
	syscall
	move $a0, $v0

	jal while

	move $t0, $v0

#printando a string 
	li $v0, 4
	la $a0, string1
	syscall

#printando o inteiro
	move $a0, $t0
	li $v0, 1
	syscall

#Saindo do programa
	li $v0, 10
	syscall

while:
	addi $sp, $sp, 8
	sw $a0, 4($sp)
	sw $ra, 0($sp)

loop:
	beq $a0, $zero, sair
	addi $a0, $a0, -1
	addi $s0, $s0, 1

	j loop 


sair:
	lw $a0, 4($sp)
	lw $ra, 0($sp)
	addi $sp, $sp, 12

	move $v0, $s0
	jr $ra