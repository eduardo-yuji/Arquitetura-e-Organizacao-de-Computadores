#file: ex7.s
#author: Sefora Davanso
#date: 05/011/22
#brief: 


.data
    msg: .asciiz "O saldo da sua conta é: "
    string: .asciiz "Entre com seu salário e sua divida: "
    
    
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

#$a0 = salario $a1 = divida
#chamando a funcao
    jal saldo_disponivel
 
#passando o retorno para printar   
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
    
saldo_disponivel:
    addi $sp, $sp, -12
    sw $a1, 8($sp)
    sw $a0, 4($sp)
    sw $ra, 0($sp)

    li $a2, 0
    add $s0, $zero, $a0
    sub $s1, $s0, $a1

    lw $a1, 8($sp)
    lw $a0, 4($sp)
    lw $ra, 0($sp)
    addi $sp, $sp, 12

    add $v0, $zero, $s1
    
    jr $ra




