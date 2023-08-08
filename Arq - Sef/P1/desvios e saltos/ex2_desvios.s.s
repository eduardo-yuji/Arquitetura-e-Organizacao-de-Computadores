#file: ex2_desvios.s
#author: Sefora Davanso
#date: 05/09/22
#brief:Faça um programa, em assembly do mips, que receba um valor inteiro do teclado, 
# se esse valor for igual a 10 imprima-o na tela e saia do programa. Senão imprima 0 e saia do programa.





.data
	string: .asciiz "Digite um valor inteiro"


.text
 main:

	li $v0, 4
	la $a0, string
	syscall

#recebendo o valor inteiro
	
	li $v0, 5
	syscall
	move $t0, $v0
	
#colocando os valores 0 e 10
	li $t1, 10
	li $t2, 0

#fazendo a comparação
#se t0 for diferente de t1 ele vai para o else
	bne $t0, $t1, else

#printa o valor digitado 
	li $v0, 1
	move $a0, $t1
	syscall
	j sair

else:

#printa o valor digitado 
	li $v0, 1
	move $a0, $t2
	syscall
	j sair
	
sair: 
	  li $v0, 10
	  syscall

