.data

.text
    main:
	li $t0, 5

        # Calcular o fatorial
        li $t1, 1

    loop:
        beq $t0, $zero, exit
        mul $t1, $t1, $t0
        addi $t0, $t0, -1
        j loop

    exit:

        li $v0, 1
        move $a0, $t1
        syscall

        li $v0, 10
        syscall
