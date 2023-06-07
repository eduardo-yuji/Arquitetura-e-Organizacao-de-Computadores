# Função para converter um valor inteiro para uma sequência de 4 bytes em ordem little-endian
def int_to_bytes(value):
    return struct.pack('<i', value)

# Função para converter uma sequência de 4 bytes em ordem little-endian para um valor inteiro
def bytes_to_int(bytes):
    return struct.unpack('<i', bytes)[0]

# Carregar o arquivo binário de entrada
with open('instructions.bin', 'rb') as file:
    instructions = file.read()

# Registradores do MIPS
registers = [0] * 32

# Instrução atual
pc = 0

while pc < len(instructions):
    # Obter a instrução atual (4 bytes)
    instruction = instructions[pc:pc+4]
    pc += 4

    # Decodificar a instrução (considerando que seja uma instrução do tipo R ou I)
    opcode = (bytes_to_int(instruction) >> 26) & 0x3F
    rs = (bytes_to_int(instruction) >> 21) & 0x1F
    rt = (bytes_to_int(instruction) >> 16) & 0x1F
    immediate = bytes_to_int(instruction) & 0xFFFF

    if opcode == 0 and rt == 0 and immediate == 0:  # nop
        continue
    elif opcode == 9:  # addiu $rt, $rs, immediate
        registers[rt] = registers[rs] + immediate
    elif opcode == 12:  # li $rt, immediate
        registers[rt] = immediate
    elif opcode == 4:  # beq $rs, $rt, offset
        offset = bytes_to_int(instructions[pc:pc+4])
        pc += 4
        if registers[rs] == registers[rt]:
            pc += offset * 4
    elif opcode == 28:  # mul $rd, $rs, $rt
        registers[rd] = registers[rs] * registers[rt]
    elif opcode == 8:  # addi $rt, $rs, immediate
        registers[rt] = registers[rs] + immediate
    elif opcode == 2:  # j target
        target = bytes_to_int(instruction & 0x3FFFFFF)
        pc = (pc & 0xF0000000) | (target * 4)
    else:
        print("Instrução desconhecida:", opcode, rt, immediate)
        break

# Exibir o valor do registro $t1 (resultado do fatorial)
print("O resultado é:", registers[9])