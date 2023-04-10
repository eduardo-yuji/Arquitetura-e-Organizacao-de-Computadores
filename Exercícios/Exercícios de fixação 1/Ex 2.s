addi $v0,$zero, 1                 #adiciona 1 no registrador v0 (função print)
add  $a0, $zero, $t0             #adiciona t0 no registrador a0 (o valor de a0 será impresso)
syscall                                  #chamada do sistema para executar a função
