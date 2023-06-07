.data
	prompt: .asciiz "Digite um numero inteiro positivo: "
	result: .asciiz "O fatorial eh: "

.text
    main:
        # Exibir prompt para o usuario
        li $v0, 4
        la $a0, prompt
        syscall

        # Ler o numero do usuario
        li $v0, 5
        syscall
        move $t0, $v0

        # Calcular o fatorial
        li $t1, 1      # Inicializar o acumulador com 1

    loop:
        beq $t0, $zero, exit
        mul $t1, $t1, $t0
        addi $t0, $t0, -1
        j loop

    exit:
        # Exibir o resultado
        li $v0, 4
        la $a0, result
        syscall

        li $v0, 1
        move $a0, $t1
        syscall

        # Encerrar o programa
        li $v0, 10
        syscall
