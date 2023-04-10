.data

.text

main:

addi $t0, $zero, 15
addi $t1, $zero, 30

# li $t0, 15
# li $t1, 30

add $t3, $t0, $t1

li $v0, 1
add $a0, $zero, $t3
#move $a0, $t3

syscall

li $v0, 10
syscall
