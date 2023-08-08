#file: ex_pont.s
#author: Sefora Davanso
#date: 05/011/22
#brief: exemplo clear ponteiro

.data

	vetor:  .word  1, 2, 3, 4, 5, 6, 7, 8, 9, 10

.text
main:
       li $a1, 10                   #size
       la $a0, vetor                #endereço do vetor
     
  	 #inicialização
    	 move  $t0, $a0                #p = endereço do array

 	sll  $t1, $a1, 2              # $t1 = size  * 4
      add $t2, $a0, $t1             # $t2 =  endereço array[size]   


loop:
    sw  $zero, 0($t0)        #  memória[p] = 0
    addi $t0, $t0, 4         # p = p +4   
   
    slt $t3, $t0, $t2           # $t3 = (p < &array[size)
    bne $t3, $zero, loop        # se (p < &array[size]) vai p loop
SAIR:

     add $t2, $a0, $zero      # $t2 = &arr
     addi $t4, $zero, 1       # t4 = indice i

     add $t5, $t2, $zero     #t5 var aux p receber &arr corrente
     add $t6, $zero, $zero  #t6 var aux para receber o indice atualizado devidamente shiftado

print:     
      slti  $s1, $t4, 10          # i < 10
      beq $s1, $zero, EXT   
          
      lw $a0, 0($t5)            # $a0 = arr[i]
      addi $v0, $zero, 1
      syscall
      
      addi $t4, $t4, 1           # i = i+ 1
      sll $t6, $t4,2         # (i = i+1) em bytes
      add $t5, $t2, $t6        # $t5 =  &arr[i]
          
      j print   

EXT:
      addi $v0, $zero, 10
      syscall
