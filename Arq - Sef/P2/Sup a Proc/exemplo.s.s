#file: ex_proc.s
#author: Sefora Davanso
#date: 05/011/22
#brief:  Int folha(int g, int h, int I, int j){
#        int f;
#        f = (g + h) - (I + j);
#        return f;
#        }



.data
	msg: .asciiz "O resultado é: "
	string: .asciiz "Digite 4 numeros, seguidos de enter, para calcular (a + b) - (c + d): "
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

#recebendo do teclado
	li $v0, 5
	syscall
	move $a2, $v0

#recebendo do teclado
	li $v0, 5
	syscall
	move $a3, $v0

# a0 = g $a1 = h $a2 = i $a3= j
#chamando a funcao 
	jal folha

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

folha:

#abrindo espaço na pilha para os regs
	addi $sp, $sp, -12
	sw $t1, 8($sp)
	sw $t0, 4($sp)
	sw $s0, 0($sp)

#fazendo as contas
	add $t0, $a0, $a1  #t0 = g + h
	add $t1, $a2, $a3  #t1 = I + j
	sub $s0, $t0, $t1  # f = (g+h)-(i+j) 

#colocando em vo para retornar
	add $v0, $s0, $zero

#voltando a pilha
	lw $s0, 0($sp)
	lw $t0, 4($sp)
	lw $t1, 8($sp)
	addi $sp, $sp, 12

#voltando para o end de origem
	jr $ra



