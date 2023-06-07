.data
limite:	.space	256
string1: .asciiz   "Digite uma string:"
string2: .asciiz " é o tamanho da string "

.text
main:

    #printando a string1
    li $v0, 4
    la $a0, string1
    syscall

    #leitura da string
    li $v0, 8
    la $a0, limite   #cria o espaço limite para a string digitada
    syscall

    #chama a funcao
    jal strlen

    #colocando o resultado em $a0 para printar
    move $a0, $t2
    li $v0, 1
    syscall

    #printando a string2
    li $v0, 4
    la $a0, string2
    syscall

    #chamada de sistema para encerrar o prgrama
    li $v0, 10
    syscall

strlen:
    li $t0, 0       #iniciando contador
    li $s2, 0       #iniciando a variavel posicao 1

loop:
    add $s2, $a0, $t0      #endereço do caractere
    lb  $t1, 0($s2)        #carrega caractere
    beqz $t1, sair         #se for nulo, sai
    addi $t0, $t0, 1       # incrementa contador
    j loop                 # volta para o loop

sair:
    addi $t0, $t0, -1         #decrementa contador para excluir o \n
    add  $t2  $zero, $t0      #guarda o tamanho da string em $t2
    add  $t0, $zero,  $zero   #zerando o contador
    jr   $ra                  #volta para a funcao
