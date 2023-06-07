and  $a0, $a1, $a2
sub $a0, $a1, $a2
sub $a0, $a1,$a3
sub $a0, $a1, $a2
sub $a0, $a1, $a2
jaime:
sub $a0, $a1, $a2
and $s1, $s0, $s2
or  $s3, $s4, $s1
xor  $zero, $zero, $zero
slt $t1, $t2, $t0
lw  $gp, $sp, $ra
sw  $t0, $t1, $t2
beq  $t0, $t0, 1
blt  $t0, $t1, 3
addi $s1, 1
sft $s1, jaime
lui $s1, 3
j $s2, 4
jal $s1, 5
not $t1