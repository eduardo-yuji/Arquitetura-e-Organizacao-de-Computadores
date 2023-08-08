#Considerando:
 $s3 = i
 $s5 = k
 $s6 = save

#define o label do laço de repetição
Loop:

#move duas posições para a esquerda alinhando na memória
 sll $t0, $s3, 2
#carrega o vetor em $t0
#é como definir o vetor
 add $t0, $t0, $s6
#carrega o elemento $t1 em uma posição do vetor
 lw $t1, 0($t0)
#faz uma comparação, caso $t1 for igual a $s5 ele sai do programa
#se não mantém no código
 bne $t1, $s5, Sair
#ele pula para a proxima posição do vetor
 addi $s3, $s3, 1
#ele volta para o começo do loop para refazer todas as comparações
 J Loop

Sair:

#conclui-se que o código procura K dentro de vetor de i posições