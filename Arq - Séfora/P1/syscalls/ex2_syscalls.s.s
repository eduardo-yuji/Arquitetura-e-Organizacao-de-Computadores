#file: ex2_syscalls.s
#author: Sefora Davanso
#date: 09/09/22
#brief:Receba um inteiro do teclado, recebe outro inteiro. subtraia o primeiro pelo segundo. Mostre o resultado na tela. Saia do programa.



.data
	string: .asciiz "Digite um inteiro a: "
	string1: .asciiz "Digite um inteiro b: "


.text
 main:

#para printar a string
	li $v0, 4
	la $a0, string 
	syscall

#recebendo do teclado
	li $v0, 5
	syscall
	move $t0, $v0
	
#para printar a string1
	li $v0, 4
	la $a0, string1 
	syscall

#recebendo do teclado
	li $v0, 5
	syscall
	move $t1, $v0

#subtraindo
	sub $t2, $t0, $t1

#printando 
	li $v0, 1
	move $a0, $t2
	syscall
	
sair: 
	  li $v0, 10
	  syscall

