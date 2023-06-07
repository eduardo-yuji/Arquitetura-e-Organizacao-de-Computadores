lui $a0, 1
lw $s1, $s2, $s3
saida:
entrada:
sw $s1, $s2, $s3
addi $s1, 10
add $t0, $s1, $a0
sub $t0, $t0, $t1
sft $s1, 8
beq $s1, $s2, entrada
blt $s1, $s2, saida
jal $s1, 2
j $s1, entrada
and $s1, $s2, $s3
slt $t1, $t0, $s1
not $t0