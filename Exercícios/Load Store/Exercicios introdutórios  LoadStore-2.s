.data

.text

main:

li $t1, 100
sw $t1, 20($sp)

li $t2, 200
sw $t2, 40($sp)

li $v0, 10
syscall
