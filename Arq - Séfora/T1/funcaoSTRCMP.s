#NT STRCMP(char* str1, char*str2): Compara o conteúdo das strings 1 e 2. Retorna 0 se conteúdo das strings são iguais.
#Retorna < 0 se o conteúdo da string 1 é menor do que string 2.
#Retorna > 0 se o conteúdo da string1 é maior do que string2.

.data
limite1:	.space	256
limite2:	.space	256

string1: .asciiz   "Digite uma string:"
string2: .asciiz   "Digite uma segunda string:"
string3: .asciiz   " é o tamanho da string1\n"
string4: .asciiz   " é o tamanho da string2\n"
string5: .asciiz   " é a diferença das duas"

.text
main:

    #printando a string1
    li $v0, 4
    la $a0, string1
    syscall

    #leitura da string
    li $v0, 8
  	la $a0, limite1   #cria o espaço limite para a string digitada
  	syscall

    #chama a funcao
    jal strlen

    #colocando o resultado em $a0 para printar
    move $a0, $t2
    li $v0, 1
    syscall

    #printando a string3
    li $v0, 4
    la $a0, string3
    syscall

    #colocando o resultado em outro registrador
    #string 1 -> tam = $t3
    move $t3, $t2

    #printando a string2
    li $v0, 4
    la $a0, string2
    syscall

    #leitura da string
    li $v0, 8
  	la $a0, limite2   #cria o espaço limite para a string digitada
  	syscall

    #chama a funcao
    jal strlen

    #colocando o resultado em $a0 para printar
    move $a0, $t2
    li $v0, 1
    syscall

    #printando a string4
    li $v0, 4
    la $a0, string4
    syscall

    #colocando o resultado em outro registrador
    #string 2 -> tam = $t5
    move $t5, $t2

    #fazer comparação entre os tamanhos
    j strcmp

strlen:
    li $t0, 0       #iniciando contador
    li $s2, 0       #iniciando a variavel posicao 1
    li $t2, 0       #zerando $t2

loop:
    add $s2, $a0, $t0      #endereço do caractere
    lb  $t1, 0($s2)        #carrega caractere
    beqz $t1, sair        #se for nulo, sai
    addi $t0, $t0, 1       # incrementa contador
    j loop                    # volta para o loop

sair:
    addi $t0, $t0, -1         #decrementa contador para excluir o \n
    add  $t2  $zero, $t0      #guarda o tamanho da string em $t2
    add  $t0, $zero,  $zero   #zerando o contador
    jr   $ra                  #volta para a funcao


strcmp:
    # string1 = $t3   string2 = $t5
    beq $t5, $t3, iguais
    #  se a string 1 < string 2
    # $t3 < $t5  ->  $t4 = 1
    slt $t4, $t3, $t5
    bne $t4, $zero, string2Maior
    j string1Maior

iguais:
      li $t1, 0
      #colocando o resultado em $a0 para printar
      move $a0, $t1
      li $v0, 1
      syscall

      #printando a string5
      li $v0, 4
      la $a0, string5
      syscall

      j saida


string2Maior:
    sub $t1, $t3, $t5
    #colocando o resultado em $a0 para printar
    move $a0, $t1
    li $v0, 1
    syscall

    #printando a string5
    li $v0, 4
    la $a0, string5
    syscall

    j saida


string1Maior:
    sub $t1, $t3, $t5
    #colocando o resultado em $a0 para printar
    move $a0, $t1
    li $v0, 1
    syscall

    #printando a string5
    li $v0, 4
    la $a0, string5
    syscall

    j saida


saida:
  #chamada de sistema para encerrar o prgrama
  li $v0, 10
  syscall
