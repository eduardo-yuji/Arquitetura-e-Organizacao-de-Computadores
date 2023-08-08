#file: ex1_syscalls.s
#author: Sefora Davanso
#date: 09/09/22
#brief:salve o valor 50 na memória na posição 10. Agora salve 100 na posição 14. 
#Some o conteúdo da memória na posição 10 e 14, mostre o resultado com a chamada de sistema correspondente. Saia do programa.



.data



.text
 main:

	li $t0, 50
	sw $t0, 40($sp)

	li $t1, 100
	sw $t1, 56($sp)

#somando 
	add $t2, $t1, $t0

#printando 
	li $v0, 1
	move $a0, $t2
	syscall
	
sair: 
	  li $v0, 10
	  syscall

