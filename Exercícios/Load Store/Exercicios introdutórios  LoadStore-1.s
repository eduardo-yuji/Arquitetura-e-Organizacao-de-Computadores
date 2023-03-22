.data

.text
    main:
        li $t1, 5
        sw $t1, 40($sp)

        li $t2, 20
        sw $t2, 160($sp)

        lw $t1, 40($sp)
        lw $t2, 160($sp)

        add $t3, $t1, $t2

        sw $t3, 400($sp)
        lw $t4, 400($sp)

        li $v0, 1
        add $a0, $zero, $t4
        syscall

        li $v0, 10
        syscall
