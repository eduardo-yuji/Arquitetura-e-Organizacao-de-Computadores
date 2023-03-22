.data

.text
    main:
        li $t1, 100
        sw $t1, 80($sp)

        li $t2, 200
        sw $t2, 160($sp)

        lw $t3, 80($sp)
        lw $t4, 160($sp)

        li $v0, 1
        add $a0, $zero, $t3
        syscall

        li $v0,10
        syscall