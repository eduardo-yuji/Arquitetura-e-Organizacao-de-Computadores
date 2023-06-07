#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
	char operation[32];
	char registers[3][32];
} Operacoes;

typedef struct
{
	char opcode[16];
	char rs[8];
	char rt[8];
	char rd[8];
} R_Format;

typedef struct
{
	char opcode[16];
	char rd[32];
	char cost[32];
} J_Format;

typedef struct
{
	char opcode[16];
	char rs[8];
	char rt[8];
	char immediate[32];
} I_Format;

typedef struct
{
	char label[36];
	int line;
} Label;

typedef struct NoPilha *PonteiroNo; // Ponteiro para estrutura NoPilha

typedef struct NoPilha
{
	int chave;			// Informacao
	Label labels;
	PonteiroNo proximo; // Ponteiro prox elemento
} NoPilha;

typedef struct
{
	PonteiroNo topo;
	int quantidade;
} PilhaDinamica;

/**
 * @brief Funcao para iniciar a pilha zerando seus valores
 *
 * @param p
 * @return int
 */
int iniciarPilha(PilhaDinamica *p)
{
	p->topo = NULL;
	p->quantidade = 0;
}

/**
 * @brief Funcao de insercao na pilha
 *
 * @param p
 * @param n
 */
void inserirPilha(PilhaDinamica *p, int n, char *name)
{
	// Criar novo No
	PonteiroNo aux = NULL;
	aux = (PonteiroNo)malloc(sizeof(NoPilha));
	// Novo no recebe o valor que queremos inserir
	aux->chave = n;
	aux->labels.line = n;
	strcpy(aux->labels.label, name);
	// Proximo do novo No recebe o topo da pilha
	aux->proximo = p->topo;
	// Topo da pilha passa a apontar para o valor do novo No
	p->topo = aux;
	// Incremento da quantidade
	p->quantidade++;
}

/**
 * @brief Funcao recursiva para conversao do numero inteiro para binario
 *
 * @param p
 * @param numero
 * @return int
 */
int binarioRecursivo(PilhaDinamica *p, int numero)
{
	if (numero == 0)
	{
		printf("Armazenando numero em binario na pilha...\n");
	}
	else
	{
		inserirPilha(p, numero % 2, "");
		binarioRecursivo(p, numero / 2);
	}
}

/**
 * @brief funcao que retorna se a pilha esta vazia (1 = true // 0 = false)
 *
 * @param p
 * @return int
 */
int estaVazia(PilhaDinamica p)
{
	if (p.quantidade == 0)
	{
		return 1;
	}
	return 0;
}

/**
 * @brief Funcao para remocao de elemento na pilha
 *
 * @param p
 */
void removerPilha(PilhaDinamica *p)
{
	PonteiroNo *aux;
	if (estaVazia(*p) == 0)
	{
		// No auiliar recebendo topo da pilha
		aux = p->topo;
		// Topo da pilha aponta para o proximo
		p->topo = p->topo->proximo;
		// Desaloca pilha e diminui a quantidade de elementos
		free(aux);
		p->quantidade--;
	}
	else
	{
		printf("Pilha esta vazia\n");
	}
}

/**
 * @brief Funcao para destruir pilha, e feito a chamada da funcao remover ate que o valor do topo seja NULL
 *
 * @param p
 */
void destruirPilha(PilhaDinamica *p)
{
	while (p->topo != NULL)
	{
		removerPilha(p);
	}
}

void firstReg(Operacoes *op, char reg[8]) {
	bool error = false;
	// Rs = 1st register operand (5 bits)
	// Registradores temporarios
	if (strcmp(op->registers[1], "$zero") == 0)
	{
		strcpy(reg, "0000"); // zero = 0
		error = true;
	}
	if (strcmp(op->registers[1], "$t0") == 0)
	{
		strcpy(reg, "0001"); // t0 = 08
		error = true;
	}
	if (strcmp(op->registers[1], "$t1") == 0)
	{
		strcpy(reg, "0010"); // t1 = 09
		error = true;
	}
	if (strcmp(op->registers[1], "$t2") == 0)
	{
		strcpy(reg, "0011"); // t2 = 10
		error = true;
	}
	// Registradores argumentativos
	if (strcmp(op->registers[1], "$a0") == 0)
	{
		strcpy(reg, "0100"); // a0 = 08
		error = true;
	}
	if (strcmp(op->registers[1], "$a1") == 0)
	{
		strcpy(reg, "0101"); // a1 = 09
		error = true;
	}
	if (strcmp(op->registers[1], "$a2") == 0)
	{
		strcpy(reg, "0110"); // t2 = 10
		error = true;
	}
	// Registradores temporarios salvos
	if (strcmp(op->registers[1], "$s0") == 0)
	{
		strcpy(reg, "0111"); // s0 = 16
		error = true;
	}
	if (strcmp(op->registers[1], "$s1") == 0)
	{
		strcpy(reg, "1000"); // s1 = 17
		error = true;
	}
	if (strcmp(op->registers[1], "$s2") == 0)
	{
		strcpy(reg, "1001"); // s2 = 18
		error = true;
	}
	if (strcmp(op->registers[1], "$s3") == 0)
	{
		strcpy(reg, "1010"); // s3 = 19
		error = true;
	}
	if (strcmp(op->registers[1], "$s4") == 0)
	{
		strcpy(reg, "1011"); // s4 = 20
		error = true;
	}
	if (strcmp(op->registers[1], "$sp") == 0)
	{
		strcpy(reg, "1101"); // s4 = 20
		error = true;
	}
	if (strcmp(op->registers[1], "$gp") == 0)
	{
		strcpy(reg, "1100"); // s4 = 20
		error = true;
	}
	if (strcmp(op->registers[1], "$pc") == 0)
	{
		printf("Error on operation: %s %s %s %s\n", op->operation, op->registers[0], op->registers[1], op->registers[2]);
		exit(1);
	}
	if (error == false)
	{
		printf("Error on operation: %s %s %s %s\n", op->operation, op->registers[0], op->registers[1], op->registers[2]);
		exit(1);
	}
}

void secondReg(Operacoes *op, char reg[8]) {
	bool error = false;
	// Rs = 1st register operand (5 bits)
	// Registradores temporarios
	if (strcmp(op->registers[2], "$zero") == 0)
	{
		strcpy(reg, "0000"); // zero = 0
		error = true;
	}
	if (strcmp(op->registers[2], "$t0") == 0)
	{
		strcpy(reg, "0001"); // t0 = 08
		error = true;
	}
	if (strcmp(op->registers[2], "$t1") == 0)
	{
		strcpy(reg, "0010"); // t1 = 09
		error = true;
	}
	if (strcmp(op->registers[2], "$t2") == 0)
	{
		strcpy(reg, "0011"); // t2 = 10
		error = true;
	}
	// Registradores argumentativos
	if (strcmp(op->registers[2], "$a0") == 0)
	{
		strcpy(reg, "0100"); // a0 = 08
		error = true;
	}
	if (strcmp(op->registers[2], "$a1") == 0)
	{
		strcpy(reg, "0101"); // a1 = 09
		error = true;
	}
	if (strcmp(op->registers[2], "$a2") == 0)
	{
		strcpy(reg, "0110"); // t2 = 10
		error = true;
	}
	// Registradores temporarios salvos
	if (strcmp(op->registers[2], "$s0") == 0)
	{
		strcpy(reg, "0111"); // s0 = 16
		error = true;
	}
	if (strcmp(op->registers[2], "$s1") == 0)
	{
		strcpy(reg, "1000"); // s1 = 17
		error = true;
	}
	if (strcmp(op->registers[2], "$s2") == 0)
	{
		strcpy(reg, "1001"); // s2 = 18
		error = true;
	}
	if (strcmp(op->registers[2], "$s3") == 0)
	{
		strcpy(reg, "1010"); // s3 = 19
		error = true;
	}
	if (strcmp(op->registers[2], "$s4") == 0)
	{
		strcpy(reg, "1011"); // s4 = 20
		error = true;
	}
	if (strcmp(op->registers[2], "$sp") == 0)
	{
		strcpy(reg, "1101"); // s4 = 20
		error = true;
	}
	if (strcmp(op->registers[2], "$gp") == 0)
	{
		strcpy(reg, "1100"); // s4 = 20
		error = true;
	}
	if (strcmp(op->registers[2], "$pc") == 0)
	{
		printf("Error on operation: %s %s %s %s\n", op->operation, op->registers[0], op->registers[1], op->registers[2]);
		exit(1);
	}
	if (error == false)
	{
		printf("Error on operation: %s %s %s %s\n", op->operation, op->registers[0], op->registers[1], op->registers[2]);
		exit(1);
	}
}

void zeroReg(Operacoes *op, char reg[8]) {
	bool error = false;
	// Rd = register destination (5 bits)
	// Registradores temporarios
	if (strcmp(op->registers[0], "$t0") == 0)
	{
		strcpy(reg, "0001"); // t0 = 08
		error = true;
	}
	if (strcmp(op->registers[0], "$t1") == 0)
	{
		strcpy(reg, "0010"); // t1 = 09
		error = true;
	}
	if (strcmp(op->registers[0], "$t2") == 0)
	{
		strcpy(reg, "0011"); // t2 = 10
		error = true;
	}
	// Registradores argumentativos
	if (strcmp(op->registers[0], "$a0") == 0)
	{
		strcpy(reg, "0100"); // a0 = 08
		error = true;
	}
	if (strcmp(op->registers[0], "$a1") == 0)
	{
		strcpy(reg, "0101"); // a1 = 09
		error = true;
	}
	if (strcmp(op->registers[0], "$a2") == 0)
	{
		strcpy(reg, "0110"); // t2 = 10
		error = true;
	}
	// Registradores temporarios salvos
	if (strcmp(op->registers[0], "$s0") == 0)
	{
		strcpy(reg, "0111"); // s0 = 16
		error = true;
	}
	if (strcmp(op->registers[0], "$s1") == 0)
	{
		strcpy(reg, "1000"); // s1 = 17
		error = true;
	}
	if (strcmp(op->registers[0], "$s2") == 0)
	{
		strcpy(reg, "1001"); // s2 = 18
		error = true;
	}
	if (strcmp(op->registers[0], "$s3") == 0)
	{
		strcpy(reg, "1010"); // s3 = 19
		error = true;
	}
	if (strcmp(op->registers[0], "$s4") == 0)
	{
		strcpy(reg, "1011"); // s4 = 20
		error = true;
	}
	if (strcmp(op->registers[0], "$sp") == 0)
	{
		strcpy(reg, "1101"); // s4 = 20
		error = true;
	}
	if (strcmp(op->registers[0], "$gp") == 0)
	{
		strcpy(reg, "1100"); // s4 = 20
		error = true;
	}
	if (strcmp(op->registers[0], "$pc") == 0)
	{
		printf("Error on operation: %s %s %s %s\n", op->operation, op->registers[0], op->registers[1], op->registers[2]);
		exit(1);
	}
	if (error == false)
	{
		printf("Error on operation: %s %s %s %s\n", op->operation, op->registers[0], op->registers[1], op->registers[2]);
		exit(1);
	}
}

void binaryStack(char cost[6], char reg[32], bool type) {
	strcpy(reg, ""); // Concatena NULL
	int number = atoi(cost);
	// Pilha de binarios
	PilhaDinamica pilha;
	iniciarPilha(&pilha);
	binarioRecursivo(&pilha, number);
	int bitsFaltando = 0;
	if (type == true)
	{
		bitsFaltando = 8 - pilha.quantidade; // Quantos bits falta para os 16 do Immediate
	} else {
		bitsFaltando = 4 - pilha.quantidade; // Quantos bits falta para os 16 do Immediate
	}
	int cont = 0;
	while (cont != bitsFaltando)
	{
		strcat(reg, "0");
		cont++;
	}
	char numString[16];
	for (PonteiroNo i = pilha.topo; i != NULL; i = i->proximo)
	{
		sprintf(numString, "%d", i->chave); // Formata o numero para string
		strcat(reg, numString);
	}
	destruirPilha(&pilha);
	return;
}

void typeRInstruction(Operacoes *op, R_Format *rInstruction, FILE *saida)
{
	firstReg(op, rInstruction->rs);
	secondReg(op, rInstruction->rt);
	zeroReg(op, rInstruction->rd);
}

void typeIInstruction(Operacoes *op, I_Format *iInstruction, FILE *saida)
{
	firstReg(op, iInstruction->rs);
	zeroReg(op, iInstruction->rt);
	secondReg(op, iInstruction->immediate);
}

/**
 * @brief Funcao para conversão dos registradores e instruções em binários, converte cada registrador temporario e salvo em binário
 *
 * @param op
 * @param saida
 */
void convertBinary(Operacoes *op, FILE *saida, PilhaDinamica *labels, int lines)
{
	R_Format rInstruction;
	I_Format iInstruction;
	J_Format jInstruction;
	bool error = false;

	/////////////////////////
	// INSTRUCOES ARITMETICAS

	// R-format Instructions
	if (strcmp(op->operation, "add") == 0)
	{
		error = true;
		strcpy(rInstruction.opcode, "0010");
		typeRInstruction(op, &rInstruction, saida);
		// Salvando no arquivo binario
		fprintf(saida, "%s %s %s %s\n", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd);
		return;
	}

	// R-format Instructions
	if (strcmp(op->operation, "sub") == 0)
	{
		error = true;
		strcpy(rInstruction.opcode, "0011");
		typeRInstruction(op, &rInstruction, saida);
		// Salvando no arquivo binario
		fprintf(saida, "%s %s %s %s\n", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd);
		return;
	}

	// I-format Instructions
	if (strcmp(op->operation, "addi") == 0)
	{
		error = true;
		strcpy(iInstruction.opcode, "1000");
		zeroReg(op, iInstruction.rs);
		zeroReg(op, iInstruction.rt);
		/*
			- Pilha de numeros binarios:
				passar o número para binário e ir armazenando seues bits em uma pilha
			- Passar cada bit para iInstruction.immediate em char
				(como o armazenamento desses bits estaram em forma de pilha basta seguirmos
				do topo ate NULL para uma ordem correta)
			- A partir da quantidade saberemos quantos bits faltam para os 16 do immediate
		*/
		binaryStack(op->registers[1], iInstruction.immediate, false);
		fprintf(saida, "%s %s %s %s\n", iInstruction.opcode, iInstruction.rs, iInstruction.rt, iInstruction.immediate);
		return;
	}

	// R-format Instructions
	if (strcmp(op->operation, "sft") == 0)
	{
		error = true;
		strcpy(rInstruction.opcode, "1001");
		zeroReg(op, rInstruction.rd);
		strcpy(rInstruction.rs, "0000");
		binaryStack(op->registers[1], rInstruction.rt, false);
		fprintf(saida, "%s %s %s %s\n", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd);
		return;
	}

	//////////////////////////////////
	// INSTRUCOES DE DESVIO CONDICIONAL

	// I-format Instructions
	if (strcmp(op->operation, "beq") == 0)
	{
		error = true;
		strcpy(iInstruction.opcode, "1100");
		firstReg(op, iInstruction.rs);
		zeroReg(op, iInstruction.rt);
		for (PonteiroNo i = labels->topo; i != NULL; i = i->proximo)
		{
			if (i->labels.line > 14)
			{
				printf("Error on operation: %s %s %s %s\n", op->operation, op->registers[0], op->registers[1], op->registers[2]);
				printf("beq instruction only accepts labels with 4 bits\n");
				exit(1);
			}
			if (strstr(i->labels.label, op->registers[2]) != NULL)
			{
				sprintf(iInstruction.immediate, "%d", i->labels.line);
				char aux[32]; // Aux é usado pq como passamos as var por ponteiros o valor de jInstruction.cost é alterado
				sprintf(aux, "%d", i->labels.line); //aux recebe mesmo valor de jInstruction.cost (linha)
				binaryStack(aux, iInstruction.immediate, false);
				fprintf(saida, "%s %s %s %s\n", iInstruction.opcode, iInstruction.rs, iInstruction.rt, iInstruction.immediate);
				return;
			}
		}
		binaryStack(op->registers[2], iInstruction.immediate, false);
		fprintf(saida, "%s %s %s %s\n", iInstruction.opcode, iInstruction.rs, iInstruction.rt, iInstruction.immediate);
		return;
	}

	// I-format Instructions
	if (strcmp(op->operation, "blt") == 0)
	{
		error = true;
		strcpy(iInstruction.opcode, "1101");
		firstReg(op, iInstruction.rs);
		zeroReg(op, iInstruction.rt);
		for (PonteiroNo i = labels->topo; i != NULL; i = i->proximo)
		{
			if (i->labels.line > 14)
			{
				printf("Error on operation: %s %s %s %s\n", op->operation, op->registers[0], op->registers[1], op->registers[2]);
				printf("beq instruction only accepts labels with 4 bits\n");
				exit(1);
			}
			if (strstr(i->labels.label, op->registers[2]) != NULL)
			{
				sprintf(iInstruction.immediate, "%d", i->labels.line);
				char aux[32]; // Aux é usado pq como passamos as var por ponteiros o valor de jInstruction.cost é alterado
				sprintf(aux, "%d", i->labels.line); //aux recebe mesmo valor de jInstruction.cost (linha)
				binaryStack(aux, iInstruction.immediate, false);
				fprintf(saida, "%s %s %s %s\n", iInstruction.opcode, iInstruction.rs, iInstruction.rt, iInstruction.immediate);
				return;
			}
		}
		binaryStack(op->registers[2], iInstruction.immediate, false);
		fprintf(saida, "%s %s %s %s\n", iInstruction.opcode, iInstruction.rs, iInstruction.rt, iInstruction.immediate);
		return;
	}

	////////////////////////////////////
	// INSTRUCOES DE DESVIO CONDICIONAL

	// J-format Instructions
	if (strcmp(op->operation, "jal") == 0)
	{
		error = true;
		strcpy(jInstruction.opcode, "1111");
		zeroReg(op, jInstruction.rd);
		if (strcmp(op->registers[1], "$ra") == 0)
		{
			strcpy(jInstruction.rd, "1111"); // ra = 20
			fprintf(saida, "%s %s\n", jInstruction.opcode, jInstruction.rd);
			return;
		}
		for (PonteiroNo i = labels->topo; i != NULL; i = i->proximo)
		{
			if (strstr(i->labels.label, op->registers[1]) != NULL)
			{
				sprintf(jInstruction.cost, "%d", i->labels.line);
				char aux[32]; // Aux é usado pq como passamos as var por ponteiros o valor de jInstruction.cost é alterado
				sprintf(aux, "%d", i->labels.line); //aux recebe mesmo valor de jInstruction.cost (linha)
				binaryStack(aux, jInstruction.cost, true);
				fprintf(saida, "%s %s %s\n", jInstruction.opcode, jInstruction.rd, jInstruction.cost);
				return;
			}
		}
		binaryStack(op->registers[1], jInstruction.cost, true);
		fprintf(saida, "%s %s %s\n", jInstruction.opcode, jInstruction.rd, jInstruction.cost);
		return;
	}

	// J-format Instructions
	if (strcmp(op->operation, "j") == 0)
	{
		error = true;
		strcpy(jInstruction.opcode, "1110");
		zeroReg(op, jInstruction.rd);
		if (strcmp(op->registers[1], "$ra") == 0)
		{
			strcpy(jInstruction.rd, "1111"); // ra = 20
			fprintf(saida, "%s %s\n", jInstruction.opcode, jInstruction.rd);
			return;
		}
		for (PonteiroNo i = labels->topo; i != NULL; i = i->proximo)
		{
			if (strstr(i->labels.label, op->registers[1]) != NULL)
			{
				sprintf(jInstruction.cost, "%d", i->labels.line);
				char aux[32]; // Aux é usado pq como passamos as var por ponteiros o valor de jInstruction.cost é alterado
				sprintf(aux, "%d", i->labels.line); //aux recebe mesmo valor de jInstruction.cost (linha)
				binaryStack(aux, jInstruction.cost, true);
				fprintf(saida, "%s %s %s\n", jInstruction.opcode, jInstruction.rd, jInstruction.cost);
				return;
			}
		}
		binaryStack(op->registers[1], jInstruction.cost, true);
		fprintf(saida, "%s %s %s\n", jInstruction.opcode, jInstruction.rd, jInstruction.cost);
		return;
	}

	////////////////////////////////////
	// INSTRUCOES DE TRANSFERENCIA

	// I-format Instructions
	if (strcmp(op->operation, "lw") == 0)
	{
		error = true;
		strcpy(iInstruction.opcode, "0000");
		typeIInstruction(op, &iInstruction, saida);
		// Salvando no arquivo binario
		fprintf(saida, "%s %s %s %s\n", iInstruction.opcode, iInstruction.rs, iInstruction.rt, iInstruction.immediate);
		return;
	}

	// I-format Instructions
	if (strcmp(op->operation, "sw") == 0)
	{
		error = true;
		strcpy(iInstruction.opcode, "0001");
		typeIInstruction(op, &iInstruction, saida);
		// Salvando no arquivo binario
		fprintf(saida, "%s %s %s %s\n", iInstruction.opcode, iInstruction.rs, iInstruction.rt, iInstruction.immediate);
		return;
	}

	// I-format Instructions
	if (strcmp(op->operation, "lui") == 0)
	{
		error = true;
		strcpy(iInstruction.opcode, "1011");
		zeroReg(op, iInstruction.rt);
		strcpy(iInstruction.rs, "0000");
		/*
			- Pilha de numeros binarios:
				passar o número para binário e ir armazenando seues bits em uma pilha
			- Passar cada bit para iInstruction.immediate em char
				(como o armazenamento desses bits estaram em forma de pilha basta seguirmos
				do topo ate NULL para uma ordem correta)
			- A partir da quantidade saberemos quantos bits faltam para os 16 do immediate
		*/
		binaryStack(op->registers[1], iInstruction.immediate, false);
		fprintf(saida, "%s %s %s %s\n", iInstruction.opcode, iInstruction.rs, iInstruction.rt, iInstruction.immediate);
		return;
	}

	////////////////////////////////////
	// INSTRUCOES DE LÓGICA

	// R-format Instructions
	if (strcmp(op->operation, "and") == 0)
	{
		error = true;
		strcpy(rInstruction.opcode, "1011");
		typeRInstruction(op, &rInstruction, saida);
		fprintf(saida, "%s %s %s %s\n", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd);
		return;
	}

	// R-format Instructions
	if (strcmp(op->operation, "or") == 0)
	{
		error = true;
		strcpy(rInstruction.opcode, "0101");
		typeRInstruction(op, &rInstruction, saida);
		fprintf(saida, "%s %s %s %s\n", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd);
		return;
	}
	if (strcmp(op->operation, "not") == 0)
	{
		error = true;
		strcpy(rInstruction.opcode, "1010");
		zeroReg(op, rInstruction.rd);
		strcpy(rInstruction.rs, "0000"); // zero = 0
		strcpy(rInstruction.rt, "0000"); // zero = 0
		fprintf(saida, "%s %s %s %s\n", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd);
		return;
	}
	// R-format Instructions
	if (strcmp(op->operation, "xor") == 0)
	{
		error = true;
		strcpy(rInstruction.opcode, "0110");
		typeRInstruction(op, &rInstruction, saida);
		fprintf(saida, "%s %s %s %s\n", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd);
		return;
	}
	// R-format Instructions
	if (strcmp(op->operation, "slt") == 0)
	{
		error = true;
		strcpy(rInstruction.opcode, "0111");
		typeRInstruction(op, &rInstruction, saida);
		fprintf(saida, "%s %s %s %s\n", rInstruction.opcode, rInstruction.rs, rInstruction.rt, rInstruction.rd);
		return;
	}
	if (error == false) {
		printf("Error on operation: %s %s %s\n", op->operation, op->registers[0], op->registers[1]);
		exit(1);
	}
}

/**
 * @brief Funcao para leitura do arquivo
 *
 * @param entrada
 * @param op
 * @param saida
 */
void readFile(FILE *entrada, Operacoes *op, FILE *saida)
{
	PilhaDinamica label;
	int lines = 0;
	char aux[100];
	while (fgets(aux, 100, entrada) != NULL)
	{ // Percorre o arquivo ate chegar no final
		// Formata a string aux por meio da expressão regular
		sscanf(aux, "%[^\n ] %[^,], %[^,\n], %[^\n]\n", op->operation, op->registers[0], op->registers[1], op->registers[2]);
		if (strstr(op->operation, ":") != NULL)
		{
			inserirPilha(&label, (lines + 2) * 2, op->operation);
		} else {
			convertBinary(op, saida, &label, lines);
		}
		lines++;
	}
	destruirPilha(&label);
}

int main(int argc, char *argv[])
{
	FILE *entrada = fopen("exemplo.s", "r");
	if (entrada == NULL)
	{
		return 1;
	}
	FILE *saida = fopen("saida.dat", "wb");
	if (saida == NULL)
	{
		return 1;
	}
	Operacoes op;
	readFile(entrada, &op, saida);
	fclose(entrada);
	fclose(saida);
	return 0;
}