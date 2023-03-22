.data

.text

main:

li $t1, 5
sw $t1, 10($sp)

li $t2, 20
sw $t2, 40($sp)

add $t3, $t1, $t2
sw $t3, 100($sp)

li $v0, 1
add $a0, $zero, $t3
syscall

li $v0, 10
syscall
