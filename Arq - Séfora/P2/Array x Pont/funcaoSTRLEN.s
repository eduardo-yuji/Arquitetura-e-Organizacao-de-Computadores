#o começo da string é no $a0
#o valor retornado é no $v0

.data
string1: .asciiz   "sef"
tamanho:  .word    0
string2: .asciiz "\nO tamanho da string é: "

.text
main:

      la $a0, string1        #passando o endereço da string
      jal strlen             #chama a funcao
      sw $v0, tamanho        #da um store no tamanho, que até entao é 0, mas sera modificado pela função

      li $v0, 4              #printa a string que anuncia o resultado
      la $a0, string2
      syscall

      li $v0, 1              #printa o resultado do tamanho
      lw $a0, tamanho
      syscall

    	li $v0, 10             #chamada de sistema para sair do programa
    	syscall

strlen:
      addi $sp, $sp, -12     #abre espaço na pilha
      #declarando registradores
      sw $s0, 0($sp)         # $s0 fica com o caractere da i
      sw $s1, 4($sp)         # $s1 fica com o tamanho a cada i
      sw $s2, 8($sp)         # $s2 fica com o endereço do caractere

      li $s1, 0              #inicializando do inicio, no zero

loop:
      add $s2, $a0, $s1      #soma o tamanho do caractere ao tamanho total da string e salva no registrado de end.
      lbu $s0, 0($s2)        #carrega o byte, preenchendo os bytes faltantes com 0s
      beq $s0, $zero, fim    #compara se chegou ao byte nulo, ou seja ao fim da string
      addi $s1, $s1, 1       #adiciona mais um no tamanho
      j loop                 #vai para o loop, e repete

fim:
      move $v0, $s1          #coloca o tamanho no registrador de retorno, que é o v0

      lw $s0, 0($sp)         #dar um restore os registradores como no inicio
      lw $s1, 4($sp)
      lw $s2, 8($sp)
      addi $sp, $sp, 12      #volta a pilha

      jr $ra                 #retorna para o jal
