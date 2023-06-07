.data
stringOrigem: .asciiz "Digite uma string de 10 caracteres: ";
tamanho: .space 10
stringDestino: .asciiz "\nString copiada: ";
nada: .asciiz " ";

.text

main:
	#Recebendo string do usuário
   	li $v0, 4
   	la $a0, stringOrigem
   	syscall

	li $v0, 8         #leitura da string
	la $a0, tamanho   #salva a leitura na variável/registrador $a0
	la $a1, 10        #tamanho da string
	syscall
	move $a1, $a0

	la $a0, nada      #a0 vai receber a copia de a1 depois

	#printando "string copiada"
	li $v0, 4
	la $a0, stringDestino
   	syscall

	#escreve o resultado
	jal strcpy        #chama a função
	#mostrar a string copiada na tela
   	li $v0, 4
   	syscall

	#chamada de sistema para sair do programa
	li $v0, 10
	syscall


strcpy:

	#Posicionamento do ponteiro, de forma que ao se deslocar
	#desloca uma posição e permite fazer um sw (escrever em memória) o $s0
	sub $sp, $sp, 4 #ou add $sp, $sp, -4 / ajusta a pilha, reservando espaço para um 1 caracter
	#Guarda o caracter anterior, escreve na memória/pilha o $s0, na posição que abriu (4)
	sw $s0, 0($sp)
	#Declarando a variavel i e concatenando o zero a ele
	add $s0, $zero, $zero #o $s0 = i que recebe o zero porque ele é a variavel de controle

	L1:
	#calcula o endereço de memoria onde tem que ler o caracter
	add $t1, $a1, $s0 # soma o $s0 + $a1(carrega a string) e guarda o endereço de memoria em $t1(recebe a string)
	lb $t2, 0($t1) # usando a lb (load byte) le e copia o endereço de memoria do caracter e salva em $t2
	add $t3, $a0, $s0 #soma a variavel i ao $a0 e salva em t3
	sb $t2, 0($t3) #sb escreve o caracter
	beq $t2, $zero, L2 #compara o valor em t2 com 0 para saber se desvia para L2 ou soma i para continuar percorrendo t2 != 0, nao desvia. t2 = 0, desvia.
	add $s0, $s0, 1
	j L1 #repete o loop $s0 muda e os endereços de memoria também.

	L2:
	#processo de desempilhar
	lw $s0, 0($sp) #leitura dos valores na pilha
	add $sp, $sp, 4 #reposiciona o ponteiro - libera o espaço reservado na pilha
	jr $ra #retorna com o resultado
