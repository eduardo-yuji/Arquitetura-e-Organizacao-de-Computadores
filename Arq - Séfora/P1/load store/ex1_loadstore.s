#file: ex1_loadstore.s
#author: Sefora Davanso
#date: 09/09/22
#brief:Faça um programa, em assembly do MIPS, para colocar o valor 5 na posição 10 da memória. Agora coloque o valor 20 na posição 40 da memória.  
#Some os conteúdos que estão na memória (5+20), e coloque o resultado na posição 100 da memória.

.data

#definindo strings
 string1: .asciiz "Carrega valores em posições de meória "


.text
 main:
 
#para printar a string 1
	li $v0, 4
	la $a0, string1
	syscall

# t0 recebe 5 e t1 20
# colocando nas posições de memoria i x 4
#se necessário printar o i basta /4
	li $t0, 5
	sw $t0, 40($sp)
	li $t1, 20
	sw $t1, 160($sp)

#somando 
	add $t2, $t0, $t1
	sw $t2, 400($sp)
#load para printar
	lw $t2, 400($sp)

#printando 
	li $v0, 1
	move $a0, $t2
	syscall
	
sair: 
	  li $v0, 10
	  syscall

