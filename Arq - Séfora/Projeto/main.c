#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char operation[5];
    char registers[3][6];
} Operacoes;

typedef struct {
    char opcode[16];
    char rs[8];
    char rt[8];
    char rd[8];
    char shamt[16];
    char funct[16];
} R_Format;

typedef struct {
    char opcode[16];
    char adress[32];
} J_Format;

typedef struct {
    char opcode[16];
    char rs[8];
    char rt[8];
    char immediate[32];
} I_Format;

typedef struct NoPilha *PonteiroNo; //Ponteiro para estrutura NoPilha

typedef struct NoPilha {
    int chave; //Informacao
    PonteiroNo proximo; //Ponteiro prox elemento
} NoPilha;

typedef struct {
    PonteiroNo topo;
    int quantidade;
} PilhaDinamica;

/*
char regTemporarios[10][5] = {
	"01000", "01001", "01010",
	"01011", "01100", "01101",
	"01110", "01111", "11000",
	"11001"
};

char regSalvo[8][5] = {
	"10000", "10001", "10010",
	"10011", "10100", "10101",
	"10110", "10111"
};
*/

/**
 * @brief Funcao para iniciar a pilha zerando seus valores
 *
 * @param p
 * @return int
 */
int iniciarPilha (PilhaDinamica *p) {
    p->topo = NULL;
    p->quantidade = 0;
}

/**
 * @brief Funcao de insercao na pilha
 *
 * @param p
 * @param n
 */
void inserirPilha(PilhaDinamica *p, int n) {
    //Criar novo No
    PonteiroNo aux = NULL;
    aux = (PonteiroNo) malloc(sizeof(NoPilha));
    //Novo no recebe o valor que queremos inserir
    aux->chave = n;
    //Proximo do novo No recebe o topo da pilha
    aux->proximo = p->topo;
    //Topo da pilha passa a apontar para o valor do novo No
    p->topo = aux;
    //Incremento da quantidade
    p->quantidade++;
}

/**
 * @brief Funcao recursiva para conversao do numero inteiro para binario
 *
 * @param p
 * @param numero
 * @return int
 */
int binarioRecursivo(PilhaDinamica *p, int numero) {
    if (numero == 0) {
        printf("Armazenando numero em binario na pilha...\n");
    } else {
        binarioRecursivo(p, numero / 2);
        inserirPilha(p, numero % 2);
    }
}

/**
 * @brief funcao que retorna se a pilha esta vazia (1 = true // 0 = false)
 *
 * @param p
 * @return int
 */
int estaVazia (PilhaDinamica p) {
    if (p.quantidade == 0) {
        return 1;
    }
    return 0;
}

/**
 * @brief Funcao para remocao de elemento na pilha
 *
 * @param p
 */
void removerPilha(PilhaDinamica *p) {
    PonteiroNo *aux;
    if (estaVazia(*p) == 0) {
        //No auiliar recebendo topo da pilha
        aux = p->topo;
        //Topo da pilha aponta para o proximo
        p->topo = p->topo->proximo;
        //Desaloca pilha e diminui a quantidade de elementos
        free(aux);
        p->quantidade--;
    } else {
        printf("Pilha esta vazia\n");
    }
}

/**
 * @brief Funcao para destruir pilha, e feito a chamada da funcao remover ate que o valor do topo seja NULL
 *
 * @param p
 */
void destruirPilha(PilhaDinamica *p) {
    while (p->topo != NULL) {
        removerPilha(p);
    }
}

/**
 * @brief Funcao para conversão dos registradores e instruções em binários, converte cada registrador temporario e salvo em binário
 *
 * @param op
 * @param saida
 */
void convertBinary(Operacoes op, FILE *saida) {
	    //R-format Instructions
	    if(strcmp(op.operation, "add") == 0 || strcmp(op.operation, "sub") == 0 || strcmp(op.operation, "sll") == 0 || strcmp(op.operation, "srl") == 0) {
		    R_Format rInstruction;
		    strcpy(rInstruction.opcode, "000000 ");

			//Rs = 1st register operand (5 bits)
			//Registradores temporarios
			if (strcmp(op.registers[1], "$zero") == 0) {
		        strcpy(rInstruction.rs, "00000 "); //zero = 0
			}
			if (strcmp(op.registers[1], "$t0") == 0) {
		        strcpy(rInstruction.rs, "01000 "); //t0 = 08
			}
			if (strcmp(op.registers[1], "$t1") == 0) {
		        strcpy(rInstruction.rs, "01001 "); //t1 = 09
			}
			if (strcmp(op.registers[1], "$t2") == 0) {
		        strcpy(rInstruction.rs, "01010 "); //t2 = 10
			}
			/*
				if (strcmp(op.registers[1], "$t3") == 0) {
					strcpy(rInstruction.rs, "01011 "); //t3 = 11
				}
				if (strcmp(op.registers[1], "$t4") == 0) {
					strcpy(rInstruction.rs, "01100 "); //t4 = 12
				}
				if (strcmp(op.registers[1], "$t5") == 0) {
					strcpy(rInstruction.rs, "01101 "); //t5 = 13
				}
				if (strcmp(op.registers[1], "$t6") == 0) {
					strcpy(rInstruction.rs, "01110 "); //t6 = 14
				}
				if (strcmp(op.registers[1], "$t7") == 0) {
					strcpy(rInstruction.rs, "01111 "); //t7 = 15
				}
				if (strcmp(op.registers[1], "$t8") == 0) {
					strcpy(rInstruction.rs, "11000 "); //t8 = 24
				}
				if (strcmp(op.registers[1], "$t9") == 0) {
					strcpy(rInstruction.rs, "11001 "); //t9 = 25
				}
			*/
			//Registradores temporarios salvos
			if (strcmp(op.registers[1], "$s0") == 0) {
		        strcpy(rInstruction.rs, "10000 "); //s0 = 16
			}
			if (strcmp(op.registers[1], "$s1") == 0) {
		        strcpy(rInstruction.rs, "10001 "); //s1 = 17
			}
			if (strcmp(op.registers[1], "$s2") == 0) {
		        strcpy(rInstruction.rs, "10010 "); //s2 = 18
			}
			if (strcmp(op.registers[1], "$s3") == 0) {
		        strcpy(rInstruction.rs, "10011 "); //s3 = 19
			}
			if (strcmp(op.registers[1], "$s4") == 0) {
		        strcpy(rInstruction.rs, "10100 "); //s4 = 20
			}
			/*
				if (strcmp(op.registers[1], "$s5") == 0) {
					strcpy(rInstruction.rs, "10101 "); //s5 = 21
				}
				if (strcmp(op.registers[1], "$s6") == 0) {
					strcpy(rInstruction.rs, "10110 "); //s6 = 22
				}
				if (strcmp(op.registers[1], "$s7") == 0) {
					strcpy(rInstruction.rs, "10111 "); //s7 = 23
				}
			*/

			//Rt = 2nd register operand (5 bits)
			//Registradores temporarios
			if (strcmp(op.registers[2], "$zero") == 0) {
		        strcpy(rInstruction.rt, "00000 "); //zero = 0
			}
			if (strcmp(op.registers[2], "$t0") == 0) {
		        strcpy(rInstruction.rt, "01000 "); //t0 = 08
			}
			if (strcmp(op.registers[2], "$t1") == 0) {
		        strcpy(rInstruction.rt, "01001 "); //t1 = 09
			}
			if (strcmp(op.registers[2], "$t2") == 0) {
		        strcpy(rInstruction.rt, "01010 "); //t2 = 10
			}
			/*
				if (strcmp(op.registers[2], "$t3") == 0) {
					strcpy(rInstruction.rt, "01011 "); //t3 = 11
				}
				if (strcmp(op.registers[2], "$t4") == 0) {
					strcpy(rInstruction.rt, "01100 "); //t4 = 12
				}
				if (strcmp(op.registers[2], "$t5") == 0) {
					strcpy(rInstruction.rt, "01101 "); //t5 = 13
				}
				if (strcmp(op.registers[2], "$t6") == 0) {
					strcpy(rInstruction.rt, "01110 "); //t6 = 14
				}
				if (strcmp(op.registers[2], "$t7") == 0) {
					strcpy(rInstruction.rt, "01111 "); //t7 = 15
				}
				if (strcmp(op.registers[2], "$t8") == 0) {
					strcpy(rInstruction.rt, "11000 "); //t8 = 24
				}
				if (strcmp(op.registers[2], "$t9") == 0) {
					strcpy(rInstruction.rt, "11001 "); //t9 = 25
				}
			*/
			//Registradores temporarios salvos
			if (strcmp(op.registers[2], "$s0") == 0) {
		        strcpy(rInstruction.rt, "10000 "); //s0 = 16
			}
			if (strcmp(op.registers[2], "$s1") == 0) {
		        strcpy(rInstruction.rt, "10001 "); //s1 = 17
			}
			if (strcmp(op.registers[2], "$s2") == 0) {
		        strcpy(rInstruction.rt, "10010 "); //s2 = 18
			}
			if (strcmp(op.registers[2], "$s3") == 0) {
		        strcpy(rInstruction.rt, "10011 "); //s3 = 19
			}
			if (strcmp(op.registers[2], "$s4") == 0) {
		        strcpy(rInstruction.rt, "10100 "); //s4 = 20
			}
			/*
				if (strcmp(op.registers[2], "$s5") == 0) {
					strcpy(rInstruction.rt, "10101 "); //s5 = 21
				}
				if (strcmp(op.registers[2], "$s6") == 0) {
					strcpy(rInstruction.rt, "10110 "); //s6 = 22
				}
				if (strcmp(op.registers[2], "$s7") == 0) {
					strcpy(rInstruction.rt, "10111 "); //s7 = 23
				}
			*/
			//Rd = register destination (5 bits)
			//Registradores temporarios
			if (strcmp(op.registers[0], "$t0") == 0) {
		        strcpy(rInstruction.rd, "01000 "); //t0 = 08
			}
			if (strcmp(op.registers[0], "$t1") == 0) {
		        strcpy(rInstruction.rd, "01001 "); //t1 = 09
			}
			if (strcmp(op.registers[0], "$t2") == 0) {
		        strcpy(rInstruction.rd, "01010 "); //t2 = 10
			}
			/*
				if (strcmp(op.registers[0], "$t3") == 0) {
					strcpy(rInstruction.rd, "01011 "); //t3 = 11
				}
				if (strcmp(op.registers[0], "$t4") == 0) {
					strcpy(rInstruction.rd, "01100 "); //t4 = 12
				}
				if (strcmp(op.registers[0], "$t5") == 0) {
					strcpy(rInstruction.rd, "01101 "); //t5 = 13
				}
				if (strcmp(op.registers[0], "$t6") == 0) {
					strcpy(rInstruction.rd, "01110 "); //t6 = 14
				}
				if (strcmp(op.registers[0], "$t7") == 0) {
					strcpy(rInstruction.rd, "01111 "); //t7 = 15
				}
				if (strcmp(op.registers[0], "$t8") == 0) {
					strcpy(rInstruction.rd, "11000 "); //t8 = 24
				}
				if (strcmp(op.registers[0], "$t9") == 0) {
					strcpy(rInstruction.rd, "11001 "); //t9 = 25
				}
			*/
			//Registradores temporarios salvos
			if (strcmp(op.registers[0], "$s0") == 0) {
		        strcpy(rInstruction.rd, "10000 "); //s0 = 16
			}
			if (strcmp(op.registers[0], "$s1") == 0) {
		        strcpy(rInstruction.rd, "10001 "); //s1 = 17
			}
			if (strcmp(op.registers[0], "$s2") == 0) {
		        strcpy(rInstruction.rd, "10010 "); //s2 = 18
			}
			if (strcmp(op.registers[0], "$s3") == 0) {
		        strcpy(rInstruction.rd, "10011 "); //s3 = 19
			}
			if (strcmp(op.registers[0], "$s4") == 0) {
		        strcpy(rInstruction.rd, "10100 "); //s4 = 20
			}
			/*
				if (strcmp(op.registers[0], "$s5") == 0) {
					strcpy(rInstruction.rd, "10101 "); //s5 = 21
				}
				if (strcmp(op.registers[0], "$s6") == 0) {
					strcpy(rInstruction.rd, "10110 "); //s6 = 22
				}
				if (strcmp(op.registers[0], "$s7") == 0) {
					strcpy(rInstruction.rd, "10111 "); //s7 = 23
				}
			*/

			if (strcmp(op.operation, "sll") == 0) {
				//Na instrucao srl rs vale 0 e o rt é o valor de op.registers[1]
				strcpy(rInstruction.rt, rInstruction.rs);
				strcpy(rInstruction.rs, "00000");
				strcpy(rInstruction.shamt, ""); //Concatena NULL
		    	int number = atoi(op.registers[2]);
				//Pilha de binarios
				PilhaDinamica pilha;
		    	iniciarPilha(&pilha);
		    	binarioRecursivo(&pilha, number);
				char numString[16];
		    	for (PonteiroNo i = pilha.topo; i != NULL; i = i->proximo) {
					sprintf(numString, "%d", i->chave); //Formata o numero para string
		        	strcat(rInstruction.shamt, numString);
		    	}
				strcpy(rInstruction.funct, "000000 "); //function code (6 bits)
			} else if (strcmp(op.operation, "srl") == 0) {
				//Na instrucao srl rs vale 0 e o rt é o valor de op.registers[1]
				strcpy(rInstruction.rt, rInstruction.rs);
				strcpy(rInstruction.rs, "00000");
				strcpy(rInstruction.shamt, ""); //Concatena NULL
		    	int number = atoi(op.registers[2]);
				//Pilha de binarios
				PilhaDinamica pilha;
		    	iniciarPilha(&pilha);
		    	binarioRecursivo(&pilha, number);
				char numString[16];
		    	for (PonteiroNo i = pilha.topo; i != NULL; i = i->proximo) {
					sprintf(numString, "%d", i->chave); //Formata o numero para string
		        	strcat(rInstruction.shamt, numString);
		    	}
				strcpy(rInstruction.funct, "000010 "); //function code (6 bits)
			} else {
				strcpy(rInstruction.shamt, "00000 "); //shift amount (5 bits)
				strcpy(rInstruction.funct, "100000 "); //function code (6 bits)
			}

			//Salvando no arquivo binario
		    fprintf(saida, "%s %s %s %s %s %s \n", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd, rInstruction.shamt, rInstruction.funct);
    }
	    //I-format Instructions
	    if(strcmp(op.operation, "addi") == 0) {
	        I_Format iInstruction;
	        strcpy(iInstruction.opcode, "001000 ");

			//Rs = 1st register operand (5 bits)
			//Registradores temporarios
			if (strcmp(op.registers[0], "$t0") == 0) {
		        strcpy(iInstruction.rs, "01000 "); //t0 = 08
			}
			if (strcmp(op.registers[0], "$t1") == 0) {
		        strcpy(iInstruction.rs, "01001 "); //t1 = 09
			}
			if (strcmp(op.registers[0], "$t2") == 0) {
		        strcpy(iInstruction.rs, "01010 "); //t2 = 10
			}
			/*
				if (strcmp(op.registers[0], "$t3") == 0) {
					strcpy(iInstruction.rs, "01011 "); //t0 = 08
				}
				if (strcmp(op.registers[0], "$t4") == 0) {
					strcpy(iInstruction.rs, "01100 "); //t1 = 09
				}
				if (strcmp(op.registers[0], "$t5") == 0) {
					strcpy(iInstruction.rs, "01101 "); //t2 = 10
				}
				if (strcmp(op.registers[0], "$t6") == 0) {
					strcpy(iInstruction.rs, "01110 "); //t0 = 08
				}
				if (strcmp(op.registers[0], "$t7") == 0) {
					strcpy(iInstruction.rs, "01111 "); //t1 = 09
				}
				if (strcmp(op.registers[0], "$t8") == 0) {
					strcpy(iInstruction.rs, "11000 "); //t2 = 10
				}
				if (strcmp(op.registers[0], "$t9") == 0) {
					strcpy(iInstruction.rs, "11001 "); //t2 = 10
				}
			*/
			//Registradores temporarios salvos
			if (strcmp(op.registers[0], "$s0") == 0) {
		        strcpy(iInstruction.rs, "10000 "); //s0 = 16
			}
			if (strcmp(op.registers[0], "$s1") == 0) {
		        strcpy(iInstruction.rs, "10001 "); //s1 = 17
			}
			if (strcmp(op.registers[0], "$s2") == 0) {
		        strcpy(iInstruction.rs, "10010 "); //s2 = 18
			}
			if (strcmp(op.registers[0], "$s3") == 0) {
		        strcpy(iInstruction.rs, "10011 "); //s3 = 19
			}
			if (strcmp(op.registers[0], "$s4") == 0) {
		        strcpy(iInstruction.rs, "10100 "); //s4 = 20
			}
			/*
				if (strcmp(op.registers[0], "$s5") == 0) {
					strcpy(iInstruction.rs, "10101 "); //s5 = 21
				}
				if (strcmp(op.registers[0], "$s6") == 0) {
					strcpy(iInstruction.rs, "10110 "); //s6 = 22
				}
				if (strcmp(op.registers[0], "$s7") == 0) {
					strcpy(iInstruction.rs, "10111 "); //s7 = 23
				}
			*/

			//Rt = 2nd register operand (5 bits)
			if (strcmp(op.registers[1], "$zero") == 0) {
		        strcpy(iInstruction.rt, "00000 "); //t0 = 08
			}
			if (strcmp(op.registers[1], "$t0") == 0) {
		        strcpy(iInstruction.rt, "01000 "); //t0 = 08
			}
			if (strcmp(op.registers[1], "$t1") == 0) {
		        strcpy(iInstruction.rt, "01001 "); //t1 = 09
			}
			if (strcmp(op.registers[1], "$t2") == 0) {
		        strcpy(iInstruction.rt, "01010 "); //t2 = 10
			}
			/*
				if (strcmp(op.registers[1], "$t3") == 0) {
					strcpy(iInstruction.rt, "01011 "); //t0 = 08
				}
				if (strcmp(op.registers[1], "$t4") == 0) {
					strcpy(iInstruction.rt, "01100 "); //t1 = 09
				}
				if (strcmp(op.registers[1], "$t5") == 0) {
					strcpy(iInstruction.rt, "01101 "); //t2 = 10
				}
				if (strcmp(op.registers[1], "$t6") == 0) {
					strcpy(iInstruction.rt, "01110 "); //t0 = 08
				}
				if (strcmp(op.registers[1], "$t7") == 0) {
					strcpy(iInstruction.rt, "01111 "); //t1 = 09
				}
				if (strcmp(op.registers[1], "$t8") == 0) {
					strcpy(iInstruction.rt, "11000 "); //t2 = 10
				}
				if (strcmp(op.registers[1], "$t9") == 0) {
					strcpy(iInstruction.rt, "11001 "); //t2 = 10
				}
			*/
			//Registradores temporarios salvos
			if (strcmp(op.registers[0], "$s0") == 0) {
		        strcpy(iInstruction.rt, "10000 "); //s0 = 16
			}
			if (strcmp(op.registers[0], "$s1") == 0) {
		        strcpy(iInstruction.rt, "10001 "); //s1 = 17
			}
			if (strcmp(op.registers[0], "$s2") == 0) {
		        strcpy(iInstruction.rt, "10010 "); //s2 = 18
			}
			if (strcmp(op.registers[0], "$s3") == 0) {
		        strcpy(iInstruction.rt, "10011 "); //s3 = 19
			}
			if (strcmp(op.registers[0], "$s4") == 0) {
		        strcpy(iInstruction.rt, "10100 "); //s4 = 20
			}
			/*
				if (strcmp(op.registers[0], "$s5") == 0) {
					strcpy(iInstruction.rt, "10101 "); //s5 = 21
				}
				if (strcmp(op.registers[0], "$s6") == 0) {
					strcpy(iInstruction.rt, "10110 "); //s6 = 22
				}
				if (strcmp(op.registers[0], "$s7") == 0) {
					strcpy(iInstruction.rt, "10111 "); //s7 = 23
				}
			*/
		    /*
		        - Pilha de numeros binarios:
		            passar o número para binário e ir armazenando seues bits em uma pilha
		        - Passar cada bit para iInstruction.immediate em char
		            (como o armazenamento desses bits estaram em forma de pilha basta seguirmos
		            do topo ate NULL para uma ordem correta)
		        - A partir da quantidade saberemos quantos bits faltam para os 16 do immediate
		    */
		    strcpy(iInstruction.immediate, ""); //Concatena NULL
		    int number = atoi(op.registers[2]);
			//Pilha de binarios
			PilhaDinamica pilha;
		    iniciarPilha(&pilha);
		    binarioRecursivo(&pilha, number);
		    int bitsFaltando = 16 - pilha.quantidade; //Quantos bits falta para os 16 do Immediate
		    int cont = 0;
		    while (cont != bitsFaltando) {
		        strcat(iInstruction.immediate, "0");
		        cont++;
		    }
			char numString[16];
		    for (PonteiroNo i = pilha.topo; i != NULL; i = i->proximo) {
				sprintf(numString, "%d", i->chave); //Formata o numero para string
		        strcat(iInstruction.immediate, numString);
		    }
			//Salvando no arquivo binario
		    fprintf(saida, "%s %s %s %s\n", iInstruction.opcode, iInstruction.rs, iInstruction.rt, iInstruction.immediate);
			destruirPilha(&pilha);
		}
}

/**
 * @brief Funcao para leitura do arquivo
 *
 * @param entrada
 * @param op
 * @param saida
 */
void readFile(FILE *entrada, Operacoes op, FILE *saida) {
    char aux[100];
    while(fgets(aux, 100, entrada) != NULL) { //Percorre o arquivo ate chegar no final
		//Formata a string aux por meio da expressão regular
        sscanf(aux, "%[^ ] %[^,], %[^,], %[^\n]\n", op.operation, op.registers[0], op.registers[1], op.registers[2]);
        convertBinary(op, saida);
    }
}

int main(int argc, char *argv[]) {
	FILE *entrada = fopen(argv[1], "r");
	if (entrada == NULL) {
	    return 1;
	}
	FILE *saida = fopen(argv[2], "wb");
	if (saida == NULL) {
	    return 1;
	}
	Operacoes op;
	readFile(entrada, op, saida);
	fclose(entrada);
	fclose(saida);
	return 0;
}