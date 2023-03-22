.data

.text

main:

addi $t0, $zero, 10
addi $t1, $zero, 20

addi $t0, $t0, 4
addi $t1, $t1, -6

sub $t3, $t0, $t1

li $v0, 1
add $a0, $zero, $t3
#move $a0, $t3

syscall

li $v0, 10
syscall
