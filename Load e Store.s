.data

.text

main:

li $t1, 5
addi $t1

sw $t1, 40($sp)
lw $t2, 40($sp)

li $v0, 1
add $a0, $zero, $t2
syscall

li $v0, 10
syscall
