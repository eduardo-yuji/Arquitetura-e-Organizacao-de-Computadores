.data
	str1:	.asciiz	"Digite a primeira string: "
	str2:	.asciiz	"Digite a segunda string: "
	concat:	.asciiz	"String concatenada: "
	espaco:	.asciiz	"\n"

	#Espaço - tamanho string
	string1:    .space      256             # buffer para a primeira string 
	string2:    .space      256             # buffer para a segunda string 
	string3:    .space      512             # buffer concatenada

.text

main:
    ######## RECEBENDO A PRIMEIRA STRING ##############
    la $a0,str1               
    la $a1,string1             
    jal recebendoString				# solicita ao usuário a string
    move $s0,$v0                 		#salvando o tamanho da string  em s0

    ######## RECEBENDO A SEGUNDA STRING ##############
    la $a0,str2               
    la $a1,string2             
    jal recebendoString				# v0: comprimento da string (com a quebra de linha removida)
    move $s1,$v0                 		#salvando o tamanho da string  em s1

    # Aponta para o buffer da string concatenada
    # Atualizando conforme as chamadas de strcat
    la $a0,string3

    # Verificando qual string é menor 
    blt $s0,$s1,string1_menor

    # string 1 é menor 
    la $a1,string1
    jal strcat 						# strcat retorna a0 atualizado para o final do destino


	# string 2 é menor
    la $a1,string2
    jal strcat

    j concatenada

string1_menor:
	# string 2 é mais longa -- anexa à saída
    la $a1,string2
    jal strcat

	# string 1 é mais curta -- anexa à saída
    la $a1,string1
    jal strcat

#Imprime o resultado
concatenada:
	# Imprime a mensagem para a string completa
    li $v0,4
    la $a0,concat
    syscall

	# Gera a string concatenada
    li $v0,4
    la $a0,string3
    syscall

	# Termina a linha
    li $v0,4
    la $a0,espaco
    syscall
	
	#Chamada de sistema para encerrar o programa
    li $v0,10
    syscall

recebendoString: 				    # solicita ao usuário a string
    li $v0,4                 		# imprimindo a mensagem
    syscall

    								# pega a string do usuário
    li $v0,8 					# syscall para leitura de string
    move $a0,$a1					# a0: contém o endereço da string/ lugar para armazenar string
    li $a1,256 					# comprimento máximo da string
    syscall

    li $v1,0x0A 					# v1: contém ASCII para nova linha
    move $a1,$a0 					# a1: contém o endereço do buffer de string

# tira a nova linha e obtém o comprimento da string
juntandoLinha1:
    lb $v0,0($a0) 				# obtém o próximo caractere na string
    addi $a0,$a0,1 				# pré-incrementa em 1 para apontar para o próximo caractere (i=i+1)
    beq $v0,$v1,juntandoLinha2	# é nova linha? se sim, voe
    bnez $v0,juntandoLinha1		# é EOS? não, laço

juntandoLinha2:
	addi $a0,$a0,-1 				# compensa o pré-incremento
    sb $zero,0($a0) 				# zera a nova linha
    sub $v0,$a0,$a1 				# obtém o comprimento da string
    jr $ra 						# return

strcat:							#anexa string
	lb $v0,0($a1) 				# pega o caractere atual(v0)
    beqz $v0,strcat_feito 		# é char 0? se sim, feito

    sb $v0,0($a0) 				# armazena o caractere atual

    addi $a0,$a0,1 				# ponteiro para buffer de destino (a0)
    addi $a1,$a1,1 				# ponteiro para buffer de origem (a1)
    j strcat

strcat_feito:
    sb      $zero,0($a0)            
    jr      $ra                     # return