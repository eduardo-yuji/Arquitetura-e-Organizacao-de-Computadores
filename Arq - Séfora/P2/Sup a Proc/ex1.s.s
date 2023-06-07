#file: ex_proc.s
#author: Sefora Davanso
#date: 05/011/22
#brief: soma dois numeros seguindo as conveçoes


.data
	msg: .asciiz "O resultado é: "
	string: .asciiz "Digite 2 numeros, seguidos de enter, para calcular sua soma: "
.text
 main:
#para printar a string
	li $v0, 4
	la $a0, string 
	syscall

#recebendo do teclado
	li $v0, 5
	syscall
	move $a0, $v0

#recebendo do teclado
	li $v0, 5
	syscall
	move $a1, $v0

# a0 = a $a1 = b
#chamando a funcao 
	jal soma

#passando o retorno 
	move $t0, $v0

#printando a mensagem
    la $a0, msg
    li $v0, 4
    syscall   
    
#printando o inteiro    
    move $a0, $t0
    li $v0, 1
    syscall

sair: 
	  li $v0, 10
	  syscall

soma:

#abrindo espaço na pilha para os regs
	addi $sp, $sp, -8
	sw $t0, 4($sp)
	sw $s0, 0($sp)

#fazendo as contas
	add $t0, $a0, $a1
	add $s0, $t0, $zero	

#colocando em vo para retornar
	add $v0, $s0, $zero

#voltando a pilha
	lw $s0, 0($sp)
	lw $t0, 4($sp)
	addi $sp, $sp, 8

#voltando para o end de origem
	jr $ra



