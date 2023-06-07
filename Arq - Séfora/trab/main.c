#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char operation[5];
    char registers[3];
} Operacoes;

typedef struct {
    char opcode[6];
    char rs[5];
    char rt[5];
    char rd[5];
    char shamt[6];
    char funct[6];
} R_Format;

typedef struct {
    char opcode[4];
    char regs[4];
    char regd[4];
    char immediate[16];
} I_Format;



void convertBinary(Operacoes op, FILE *saida) {
	char ops;
	strcpy(ops, op.operation);
	switch(ops) {
	    //R-format Instructions
	    case 'add':
			R_Format rInstruction;
		    strcpy(rInstruction.opcode, "000000");
		    switch(op.registers[1]){ //Rs = 1st register operand (5 bits)
		        case '$t0':
		            strcpy(rInstruction.rs, "01000"); //t0 = 08
		            break;
		        case '$t1':
		            strcpy(rInstruction.rs, "01001"); //t1 = 09
		            break;
		        case '$t2':
		            strcpy(rInstruction.rs, "01010"); //t2 = 10
		            break;
		    }
		    switch(op.registers[2]){ //Rt = 2nd register operand (5 bits)
		        case '$t0':
		            strcpy(rInstruction.rt, "01000"); //t0 = 08
		            break;
		        case '$t1':
		            strcpy(rInstruction.rt, "01001"); //t1 = 09
		            break;
		        case '$t2':
		            strcpy(rInstruction.rt, "01010"); //t2 = 10
		            break;
		    }
		    switch(op.registers[0]){ //Rd = register destination (5 bits)
		        case '$t0':
		            strcpy(rInstruction.rd, "01000"); //t0 = 08
		            break;
		        case '$t1':
		            strcpy(rInstruction.rd, "01001"); //t1 = 09
		            break;
		        case '$t2':
		            strcpy(rInstruction.rd, "01010"); //t2 = 10
		            break;
		    }
		    strcpy(rInstruction.shamt, "00000"); //shift amount (5 bits)
		    strcpy(rInstruction.funct, "000000"); //function code (6 bits)
		    break;
		    fprintf(saida, "%s %s %s %s %s %s ", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd, rInstruction.shamt, rInstruction.funct);


	    case 'sub':
		    R_Format rInstruction;
		    strcpy(rInstruction.opcode, "000000");
		    switch(op.registers[1]){ //Rs = 1st register operand (5 bits)
		        case '$t0':
		            strcpy(rInstruction.rs, "01000"); //t0 = 08
		            break;
		        case '$t1':
		            strcpy(rInstruction.rs, "01001"); //t1 = 09
		            break;
		        case '$t2':
		            strcpy(rInstruction.rs, "01010"); //t2 = 10
		            break;
		    }
		    switch(op.registers[2]){ //Rt = 2nd register operand (5 bits)
		        case '$t0':
		            strcpy(rInstruction.rt, "01000"); //t0 = 08
		            break;
		        case '$t1':
		            strcpy(rInstruction.rt, "01001"); //t1 = 09
		            break;
		        case '$t2':
		            strcpy(rInstruction.rt, "01010"); //t2 = 10
		            break;
		    }
		    switch(op.registers[0]){ //Rd = register destination (5 bits)
		        case '$t0':
		            strcpy(rInstruction.rd, "01000"); //t0 = 08
		            break;
		        case '$t1':
		            strcpy(rInstruction.rd, "01001"); //t1 = 09
		            break;
		        case '$t2':
		            strcpy(rInstruction.rd, "01010"); //t2 = 10
		            break;
		    }
		    strcpy(rInstruction.shamt, "00000"); //shift amount (5 bits)
		    strcpy(rInstruction.funct, "100000"); //function code (6 bits)
		    break;
		    fprintf(saida, "%s %s %s %s %s %s ", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd, rInstruction.shamt, rInstruction.funct);
    }
	    //I-format Instructions
		/*
	    case 'addi':
	        I_Format iInstruction;
	        strcpy(iInstruction.opcode, "001000");
	        switch(op.registers[0]){ //Rs = 1st register operand (5 bits)
		        case '$t0':
		            strcpy(iInstruction.rs, "01000"); //t0 = 08
		            break;
		        case '$t1':
		            strcpy(iInstruction.rs, "01001"); //t1 = 09
		            break;
		        case '$t2':
		            strcpy(iInstruction.rs, "01010"); //t2 = 10
		            break;
		    }
		    switch(op.registers[1]){ //Rt = 2nd register operand (5 bits)
		        case '$t0':
		            strcpy(iInstruction.rt, "01000"); //t0 = 08
		            break;
		        case '$t1':
		            strcpy(iInstruction.rt, "01001"); //t1 = 09
		            break;
		        case '$t2':
		            strcpy(iInstruction.rt, "01010"); //t2 = 10
		            break;
		    }
		    /* Ideia:
		        int number = atoi(op.register[2]);
		         - Pilha de numeros binarios:
		            passar o número para binário e ir armazenando seues bits em uma pilha
		        - Passar cada bit para iInstruction.immediate em char
		            (como o armazenamento desses bits estaram em forma de pilha basta seguirmos
		            do topo ate NULL para uma ordem correta)
		        - A partir da quantidade saberemos quantos bits faltam para os 16 do immediate
		    */
}


void readFile(FILE *entrada, Operacoes op, FILE *saida) {
    char aux[100];
    while(fgets(aux, 100, entrada) != NULL) {
        sscanf(aux, "%[^ ] %[^,], %[^,], %[^\n]\n", op.operation, op.registers[0], op.registers[1], op.registers[2]);
        convertBinary(op, saida);
    }
}

int main(int argc, char *argv[]) {
	FILE *entrada = fopen(argv[1], "r");
	if (entrada == NULL) {
	    return 1;
	}
	FILE *saida = fopen(argv[2], "w"); //txt file just for tests
	if (saida == NULL) {
	    return 1;
	}
	Operacoes op;
	readFile(entrada, op, saida);
	fclose(entrada);
	fclose(saida);
	return 0;
}
