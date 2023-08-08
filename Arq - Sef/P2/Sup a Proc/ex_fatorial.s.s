#file: ex_fatorial.s
#author: Sefora Davanso
#date: 05/011/22
#brief: fatorial seguindo as convenções



.data
    msg: .asciiz "O fatorial é: "
    string: .asciiz "Digite um numero para ter seu fatorial calculado: "
    
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

#chamando a funcao
    jal fat
    
    move $t0, $v0
    
#printando a mensagem
    la $a0, msg
    li $v0, 4
    syscall   
    
#printando o inteiro    
    move $a0, $t0
    li $v0, 1
    syscall
    
#saindo do programa
    li $v0, 10
    syscall
    
fat:
    addi $sp, $sp, -8
    sw $a0, 4($sp)
    sw $ra, 8($sp)

    slti $t0, $a0, 1
    beq $t0, $zero, L1
    
    li $v0, 1
    addi $sp, $sp, 8
    jr $ra   
    
L1:
    addi $a0, $a0, -1
    jal fat

    lw $a0, 4($sp)
    lw $ra, 8($sp)
    addi $sp, $sp, 8

    mul $v0, $v0, $a0
    
    jr $ra




