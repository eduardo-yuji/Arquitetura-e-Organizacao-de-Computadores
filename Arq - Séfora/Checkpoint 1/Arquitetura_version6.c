#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define zero 0
//------------------------------------------------------------------------------
//ESTRUTURAS
//------------------------------------------------------------------------------
//_____________________________
//Banco de Registradores
//_____________________________
typedef struct{
  int at;//at
  int v0;//v0
  int v1;//v1
  int a0;//a0
  int a1;//a1
  int a2;//a2
  int a3;//a3
  int t0;//t0
  int t1;//t1
  int t2;//t2
  int t3;//t3
  int t4;//t4
  int t5;//t5
  int t6;//t6
  int t7;//t7
  int s0;//s0
  int s1;//s1
  int s2;//s2
  int s3;//s3
  int s4;//s4
  int s5;//s5
  int s6;//s6
  int s7;//s7
  int t8;//t8
  int t9;//t9
  int k9;//k9
  int kl;//kl
  int gp;//gp
  int sp;//sp
  int fp;//fp
  int ra;//ra
}BancodeRegs;
//_____________________________
//R-Type
//_____________________________
typedef struct{
  char opcode[7];
  char RegS[6];
  char RegT[6];
  char RegD[6];
  char shamt[6];
  char funcao[7];
}InstrucaoR;
//_____________________________
//I-Type
//_____________________________
typedef struct{
  char opcode[7];
  char RegS[6];
  char RegT[6];
  char OFFSET[17];
}InstrucaoI;
//_____________________________
//J-Type
//_____________________________
typedef struct{
  char opcode[7];
  char endereco[27];
}InstrucaoJ;
//_____________________________
//Condicionais Globais
//_____________________________
typedef struct{
  bool ALUop;
  bool RegDST;
  bool RegWrite;
  bool ALUSrc;
  bool MemWrite;
  bool MemRead;
  bool MentoSrc;
  char operacao[7];
}Condicionais;
//_____________________________
//Dados Operações
//_____________________________
typedef struct{
  int RegS;
  int RegT;
  int resultado;
  int usuario;
  char Endereco[9];
}DadosFornecidos;
//------------------------------------------------------------------------------
//FUNCOES
//------------------------------------------------------------------------------
//_____________________________
//Simular os Valores já armazenados
//_____________________________
void IniciaValoresRegistradores(BancodeRegs* registradores){
  registradores->at=2;
  registradores->v0=3;
  registradores->v1=4;
  registradores->a0=5;
  registradores->a1=12;
  registradores->a2=12;
  registradores->a3=12;
  registradores->t0=12;
  registradores->t1=12;
  registradores->t2=12;
  registradores->t3=12;
  registradores->t4=12;
  registradores->t5=12;
  registradores->t6=12;
  registradores->t7=12;
  registradores->s0=12;
  registradores->s1=12;
  registradores->s2=12;
  registradores->s3=12;
  registradores->s4=12;
  registradores->s5=12;
  registradores->s6=12;
  registradores->s7=12;
  registradores->t8=12;
  registradores->t9=12;
  registradores->k9=12;
  registradores->kl=12;
  registradores->gp=12;
  registradores->sp=12;
  registradores->fp=12;
  registradores->ra=12;
}
//_____________________________
//Unidade de Controle
//_____________________________
void UnidadeControle(Condicionais* condicional){

  if(strcmp(condicional->operacao,"111111")==0){
  //SOMA
    condicional->ALUop==false;
    condicional->RegDST==true;
    condicional->RegWrite==false;
    condicional->ALUSrc==false;
    condicional->MemRead==false;
    condicional->MemWrite==false;
    condicional->MentoSrc==false;
  } else if(strcmp(condicional->operacao,"111110")==0){
  //SUBTRACAO
  condicional->ALUop==false;
  condicional->RegDST==true;
  condicional->RegWrite==false;
  condicional->ALUSrc==false;
  condicional->MemRead==false;
  condicional->MemWrite==false;
  condicional->MentoSrc==false;
} else if(strcmp(condicional->operacao,"111101")==0){
  //MULT
  condicional->ALUop==false;
  condicional->RegDST==true;
  condicional->RegWrite==false;
  condicional->ALUSrc==false;
  condicional->MemRead==false;
  condicional->MemWrite==false;
  condicional->MentoSrc==false;
} else if(strcmp(condicional->operacao,"111100")==0){
    //DIV
    condicional->ALUop==false;
    condicional->RegDST==true;
    condicional->RegWrite==false;
    condicional->ALUSrc==false;
    condicional->MemRead==false;
    condicional->MemWrite==false;
    condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"111011")==0){
      //AND
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"111010")==0){
        //OR
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"111001")==0){
      //XOR
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"111000")==0){
      //NOR
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"110111")==0){
      //SLT
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"110110")==0){
      //SLL
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"110101")==0){
      //SRL
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"110100")==0){
      //SRA
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"110011")==0){
      //ANDI
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"110010")==0){
      //ORI
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"110001")==0){
      //XORI
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }else if(strcmp(condicional->operacao,"110000")==0){
      //ADDI
      condicional->ALUop==false;
      condicional->RegDST==true;
      condicional->RegWrite==false;
      condicional->ALUSrc==false;
      condicional->MemRead==false;
      condicional->MemWrite==false;
      condicional->MentoSrc==false;
  }
}
//_____________________________
//Banco de Registradores -> FUNCOES
//_____________________________
void ConsultaBanco(char Endereco[],BancodeRegs* registradores,DadosFornecidos* dados,bool isS){
  //printf("%s\n",Endereco);
  if(strcmp("11111",Endereco)==0){
    if(isS){
      dados->RegS=zero;
    }else{
      dados->RegT=zero;
    }
  }else if(strcmp("11110",Endereco)==0){
    if(isS){
      dados->RegS=registradores->at;
    }else{
      dados->RegT=registradores->at;
    }
  }else if(strcmp("11101",Endereco)==0){
    if(isS){
      dados->RegS=registradores->v0;
    }else{
      dados->RegT=registradores->v0;
    }
  }else if(strcmp("11100",Endereco)==0){
    if(isS){
      dados->RegS=registradores->v1;
    }else{
      dados->RegT=registradores->v1;
    }
  }else if(strcmp("11011",Endereco)==0){
    if(isS){
      dados->RegS=registradores->a0;
    }else{
      dados->RegT=registradores->a0;
    }
  }else if(strcmp("11010",Endereco)==0){
    if(isS){
      dados->RegS=registradores->a1;
    }else{
      dados->RegT=registradores->a1;
    }
  }else if(strcmp("11001",Endereco)==0){
    if(isS){
      dados->RegS=registradores->a2;
    }else{
      dados->RegT=registradores->a2;
    }
  }else if(strcmp("11000",Endereco)==0){
    if(isS){
      dados->RegS=registradores->a3;
    }else{
      dados->RegT=registradores->a3;
    }
  }else if(strcmp("10111",Endereco)==0){
    if(isS){
      dados->RegS=registradores->t0;
    }else{
      dados->RegT=registradores->t0;
    }
  }else if(strcmp("10110",Endereco)==0){
    if(isS){
      dados->RegS=registradores->t1;
    }else{
      dados->RegT=registradores->t1;
    }
  }else if(strcmp("10101",Endereco)==0){
    if(isS){
      dados->RegS=registradores->t2;
    }else{
      dados->RegT=registradores->t2;
    }
  }else if(strcmp("10100",Endereco)==0){
    if(isS){
      dados->RegS=registradores->t3;
    }else{
      dados->RegT=registradores->t3;
    }
  }else if(strcmp("10011",Endereco)==0){
    if(isS){
      dados->RegS=registradores->t4;
    }else{
      dados->RegT=registradores->t4;
    }
  }else if(strcmp("10010",Endereco)==0){
    if(isS){
      dados->RegS=registradores->t5;
    }else{
      dados->RegT=registradores->t5;
    }
  }else if(strcmp("10001",Endereco)==0){
    if(isS){
      dados->RegS=registradores->t6;
    }else{
      dados->RegT=registradores->t6;
    }
  }else if(strcmp("10000",Endereco)==0){
    if(isS){
      dados->RegS=registradores->t7;
    }else{
      dados->RegT=registradores->t7;
    }
  }else if(strcmp("01111",Endereco)==0){
    if(isS){
      dados->RegS=registradores->s0;
    }else{
      dados->RegT=registradores->s0;
    }
  }else if(strcmp("01110",Endereco)==0){
    if(isS){
      dados->RegS=registradores->s1;
    }else{
      dados->RegT=registradores->s1;
    }
  }else if(strcmp("01101",Endereco)==0){
    if(isS){
      dados->RegS=registradores->s2;
    }else{
      dados->RegT=registradores->s2;
    }
  }else if(strcmp("01100",Endereco)==0){
    if(isS){
      dados->RegS=registradores->s3;
    }else{
      dados->RegT=registradores->s3;
    }
  }else if(strcmp("01011",Endereco)==0){
    if(isS){
      dados->RegS=registradores->s4;
    }else{
      dados->RegT=registradores->s4;
    }
  }else if(strcmp("01010",Endereco)==0){
    if(isS){
      dados->RegS=registradores->s5;
    }else{
      dados->RegT=registradores->s5;
    }
  }else if(strcmp("01001",Endereco)==0){
    if(isS){
      dados->RegS=registradores->s6;
    }else{
      dados->RegT=registradores->s6;
    }
  }else if(strcmp("01000",Endereco)==0){
    if(isS){
      dados->RegS=registradores->s7;
    }else{
      dados->RegT=registradores->s7;
    }
  }else if(strcmp("00111",Endereco)==0){
    if(isS){
      dados->RegS=registradores->t8;
    }else{
      dados->RegT=registradores->t8;
    }
  }else if(strcmp("00110",Endereco)==0){
    if(isS){
      dados->RegS=registradores->t9;
    }else{
      dados->RegT=registradores->t9;
    }
  }else if(strcmp("00101",Endereco)==0){
    if(isS){
      dados->RegS=registradores->k9;
    }else{
      dados->RegT=registradores->k9;
    }
  }else if(strcmp("00100",Endereco)==0){
    if(isS){
      dados->RegS=registradores->kl;
    }else{
      dados->RegT=registradores->kl;
    }
  }else if(strcmp("00011",Endereco)==0){
    if(isS){
      dados->RegS=registradores->gp;
    }else{
      dados->RegT=registradores->gp;
    }
  }else if(strcmp("00010",Endereco)==0){
    if(isS){
      dados->RegS=registradores->sp;
    }else{
      dados->RegT=registradores->sp;
    }
  }else if(strcmp("00001",Endereco)==0){
    if(isS){
      dados->RegS=registradores->fp;
    }else{
      dados->RegT=registradores->fp;
    }
  }else if(strcmp("00000",Endereco)==0){
    if(isS){
      dados->RegS=registradores->ra;
    }else{
      dados->RegT=registradores->ra;
    }
  }
}

void SalvarDado(char Endereco[],BancodeRegs* registradores,DadosFornecidos* dados){
  if(strcmp("11110",Endereco)==0){
    registradores->at=dados->resultado;
  }else if(strcmp("11101",Endereco)==0){
    registradores->v0=dados->resultado;
  }else if(strcmp("11100",Endereco)==0){
    registradores->v1=dados->resultado;
  }else if(strcmp("11011",Endereco)==0){
    registradores->a0=dados->resultado;
  }else if(strcmp("11010",Endereco)==0){
    registradores->a1=dados->resultado;
  }else if(strcmp("11001",Endereco)==0){
    registradores->a2=dados->resultado;
  }else if(strcmp("11000",Endereco)==0){
    registradores->a3=dados->resultado;
  }else if(strcmp("10111",Endereco)==0){
    registradores->t0=dados->resultado;
  }else if(strcmp("10110",Endereco)==0){
    registradores->t1=dados->resultado;
  }else if(strcmp("10101",Endereco)==0){
    registradores->t2=dados->resultado;
  }else if(strcmp("10100",Endereco)==0){
    registradores->t3=dados->resultado;
  }else if(strcmp("10011",Endereco)==0){
    registradores->t4=dados->resultado;
  }else if(strcmp("10010",Endereco)==0){
    registradores->t5=dados->resultado;
  }else if(strcmp("10001",Endereco)==0){
    registradores->t6=dados->resultado;
  }else if(strcmp("10000",Endereco)==0){
    registradores->t7=dados->resultado;
  }else if(strcmp("01111",Endereco)==0){
    registradores->s0=dados->resultado;
  }else if(strcmp("01110",Endereco)==0){
    registradores->s1=dados->resultado;
  }else if(strcmp("01101",Endereco)==0){
    registradores->s2=dados->resultado;
  }else if(strcmp("01100",Endereco)==0){
    registradores->s3=dados->resultado;
  }else if(strcmp("01011",Endereco)==0){
    registradores->s4=dados->resultado;
  }else if(strcmp("01010",Endereco)==0){
    registradores->s5=dados->resultado;
  }else if(strcmp("01001",Endereco)==0){
    registradores->s6=dados->resultado;
  }else if(strcmp("01000",Endereco)==0){
    registradores->s7=dados->resultado;
  }else if(strcmp("00111",Endereco)==0){
    registradores->t8=dados->resultado;
  }else if(strcmp("00110",Endereco)==0){
    registradores->t9=dados->resultado;
  }else if(strcmp("00101",Endereco)==0){
    registradores->k9=dados->resultado;
  }else if(strcmp("00100",Endereco)==0){
    registradores->kl=dados->resultado;
  }else if(strcmp("00011",Endereco)==0){
    registradores->gp=dados->resultado;
  }else if(strcmp("00010",Endereco)==0){
    registradores->sp=dados->resultado;
  }else if(strcmp("00001",Endereco)==0){
    registradores->fp=dados->resultado;
  }else if(strcmp("00000",Endereco)==0){
    registradores->ra=dados->resultado;
  }
}

void BancoRegistradores(char RegS[],char RegT[],char RegD[],BancodeRegs* registradores,Condicionais* condicional,DadosFornecidos* dados){
  /*
  printf("%s\n",RegS);
  printf("%s\n",RegT);
  printf("%s\n",RegD);
  */
  if(condicional->RegWrite==false){//Procura Valores
    ConsultaBanco(RegS,registradores,dados,true);
    ConsultaBanco(RegT,registradores,dados,false);
  }else{//Salva Dados
    SalvarDado(RegD,registradores,dados);
  }
}

//_____________________________
//ULA
//_____________________________
int ConteBits(int numero){
  if(numero<10){
    return 1;
  }else{
    return 1+ConteBits(numero/10);
  }
}
//APAGAR CONVERSOR
int ConversorBin(int numero){
  if(numero==0){
    return 0;
  }else if(numero<2){
    return 1;
  }else{
    return (10*ConversorBin(numero/2))+numero%2;
  }
}
void MovaaEsquerda(char vetor[],int tamanho,int dif){
char* vetor_temp= (char*) malloc(tamanho* sizeof(char));//-> vetor temporario para copiar nosso valor
strcpy(vetor_temp,vetor);//Copiando valor
int temp=tamanho+dif;
  for (int i = 0; i < temp; i++) {
    vetor[i+dif]=vetor_temp[i];
  }
  for (int i = 0; i < dif; i++) {
    vetor[i]='0';
  }
}
int VerificaTamanho(char vetor[]){
  int temp=0;
  bool cond=true;
  while(cond){

    if(vetor[temp]=='\0'){
      cond=false;
    }else{
      temp++;
    }
  }
  //printf("temp => %i\n",temp);
  return temp;
}
void ULA(DadosFornecidos* dados,char opcode[],char funct[],Condicionais* condicional){
  if(strcmp(opcode,"000000") == 0 && strcmp(funct, "100000") == 0){
  //ADD
  condicional->RegWrite=true;
  dados->resultado=dados->RegS+dados->RegT;
} else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "100010") == 0){
  //SUB
  condicional->RegWrite=true;
  dados->resultado=dados->RegS-dados->RegT;
} else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "011000") == 0){
  //MULT
  condicional->RegWrite=true;
  dados->resultado=dados->RegS*dados->RegT;
} else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "011010") == 0){
    //DIV
    condicional->RegWrite=true;
    dados->resultado=dados->RegS/dados->RegT;
  }else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "100100") == 0){
      //AND
      int a=dados->RegS;
      char* vetor1= (char*) malloc(10* sizeof(char));
      itoa(a,vetor1,2);   // here 2 means binary
      printf("Convertido em binario = %s\n", vetor1);
      int tamanho1 =VerificaTamanho(vetor1);
      //itoa(a,vetor1,10);   // here 10 means decimal
      //printf("Decimal value = %s\n", vetor1);

      a=dados->RegT;
      char* vetor2= (char*) malloc(10* sizeof(char));
      itoa(a,vetor2,2);   // here 2 means binary
      printf("Convertido em binario = %s\n", vetor2);
      int tamanho2 =VerificaTamanho(vetor2);
      printf("Tamanho 1 => %i\nTamanho 2 => %i\n",tamanho1,tamanho2);
      vetor1= (char*) malloc(tamanho1+1* sizeof(char));
      vetor2= (char*) malloc(tamanho2+1* sizeof(char));
      int diferenca;
      if(tamanho1>tamanho2){
        diferenca=tamanho1-tamanho2;
      //  MovaaEsquerda(vetor2,tamanho2,diferenca);
      }else{
        diferenca=tamanho2-tamanho1;
        printf("Dif => %i\n",diferenca);
        MovaaEsquerda(vetor1,tamanho1,diferenca);
      }


      //itoa(a,vetor2,10);   // here 10 means decimal
      //printf("Decimal value = %s\n", vetor2);
      /*
      int temp1=ConversorBin(dados->RegS);
      int temp2=ConversorBin(dados->RegT);
      printf("%i\n%i\n",temp1,temp2);
      //----100
      //----010
      int tamanho1;
      int tamanho2;
      if(temp1>temp2){
        tamanho1 = ConteBits(temp1);
        tamanho2 = ConteBits(temp2);
        printf("Tamanho %i\n2Tamanho %i\n",tamanho1,tamanho2);
      }else{
        tamanho1 = ConteBits(temp2);
        tamanho2 = ConteBits(temp1);
        printf("Tamanho %i\n2Tamanho %i\n",tamanho1,tamanho2);
      }
      int* vetor1= (int*) malloc(tamanho1 * sizeof(int));
      int* vetor2= (int*) malloc(tamanho1 * sizeof(int));

      if(tamanho1 != tamanho2) {
        int dif=tamanho1-tamanho2;
        for(int i = 0; i < tamanho1; i++) {
          if(i<=dif){
    //        vetor1=;
            vetor2[i]=0;
          }else{
//            vetor1[i]=;
  //          vetor2[i]=;
          }

        }
      }
      */
      /*
      if(dados->RegbS&&dados->RegbT){
        dados->resultado = 1;
      }else{
        dados->resultado = 0;
      }
      */
  }else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "100101") == 0){
        //OR
        /*
        if(dados->RegbS||dados->RegbT){
          dados->resultado = 1;
        }else{
          dados->resultado = 0;
        }
        */
  }else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "100110") == 0){
      //XOR
      /*
      if((dados->RegbS&&dados->RegbT)==false && (dados->RegbS||dados->RegbT)==true){
        dados->resultado = 1;
      }else{
        dados->resultado = 0;
      }
      */
  }else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "100111") == 0){
      //NOR
      /*
      if(!(dados->RegbS||dados->RegbT)==true){
        dados->resultado = 1;
      }else{
        dados->resultado = 0;
      }
      */
  }else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "101010") == 0){
      //SLT
      /*
      if(dados->RegS<dados->RegT){
        dados->resultado = 1;
      }else{
        dados->resultado = 0;
      }
      */
  }else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "000000") == 0){
      //SLL
      //FAZER
  }else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "000010") == 0){
      //SRL
      //FAZER
  }else if(strcmp(opcode,"000000") == 0 && strcmp(funct, "000011") == 0){
      //SRA
      //FAZER
  }else if(strcmp(opcode,"001100") == 0 && strcmp(funct, "000000") == 0){
      //ANDI
      /*if(((dados->RegS==true)||(dados->RegS==1))&&(dados->usuario==1)){
        dados->resultado = 1;
        dados->resultadob = true;
      }else{
        dados->resultado = 0;
        dados->resultadob = false;
      }*/
  }else if(strcmp(opcode,"001101") == 0 && strcmp(funct, "000000") == 0){
      //ORI
      /*if((dados->RegS==true)&&(dados->usuario==1)){
        dados->resultado = 1;
        dados->resultadob = true;
      }else{
        dados->resultado = 0;
        dados->resultadob = false;
      }*/
  }else if(strcmp(opcode,"001110") == 0 && strcmp(funct, "000000") == 0){
      //XORI
      /*if((dados->RegbS&&(dados->usuario==1))==false && (dados->RegbS||(dados->usuario==1))==true){
        dados->resultado = 1;
        dados->resultadob = true;
      }else{
        dados->resultado = 0;
        dados->resultadob = false;
      }*/
  }else if(strcmp(opcode,"001000") == 0 && strcmp(funct, "000000") == 0){
      //ADDI
      //FAZER
  }
}
//_____________________________
//LEITURA PARA TIPO R
//_____________________________
void DividaParaR(char entrada[],InstrucaoR* instrucaor){
  int temp=0;

  for (int i = 0; i < 32; i++) {
    if(0<=i && i<=5){//OPCODE
      instrucaor->opcode[temp]=entrada[i];
      temp++;
    }if(6<=i && i<=10){//Registradors
      if(6==i){
        instrucaor->opcode[temp]='\0';
        temp=0;
      }
      instrucaor->RegS[temp]=entrada[i];
      temp++;
    }if(10<=i && i<=14){//Registradort
      if(10==i){
        instrucaor->RegS[temp]='\0';
        temp=0;
      }
      instrucaor->RegT[temp]=entrada[i];
      temp++;
    }if(14<=i && i<=19){//RegistradorD
      if(14==i){
      instrucaor->RegT[temp]='\0';
        temp=0;
      }
      instrucaor->RegD[temp]=entrada[i];
      temp++;
    }if(19<=i && i<=24){//Shamt
      if(19==i){
        instrucaor->RegD[temp]='\0';
        temp=0;
      }
      instrucaor->shamt[temp]=entrada[i];
      temp++;
    }else{
      if(25==i){
        instrucaor->shamt[temp]='\0';
        temp=0;
      }

    }
  }
  printf("OPCODE = %s\n",instrucaor->opcode);
  printf("RegS = %s\n",instrucaor->RegS);
  printf("RegT = %s\n",instrucaor->RegT);
  printf("RegD = %s\n",instrucaor->RegD);
  printf("Shamt = %s\n",instrucaor->shamt);
}
//_____________________________


int main() {

  Condicionais condicional;
  InstrucaoI instrucaoi;
  InstrucaoJ instrucaoj;
  InstrucaoR instrucaor;
  BancodeRegs registradores;
  DadosFornecidos dados;

  char entrada[33];
  /*->ARQUIVO BIN(NECESSITA REVISÃO)
  FILE* arq1=fopen("arq.bin","rb");
  if (arq1==NULL){
    printf("Não conseguiu abrir o arquivo\n");
  }

  fread(entrada,sizeof(char),32,arq1);
  printf("Entrada = %s\n",entrada);

  if(entrada[0]=='1'){
    DividaParaR(entrada,&instrucaor);
  }
  */

  IniciaValoresRegistradores(&registradores);
  //_____________________________
  //TEMPORARIO
  //_____________________________
  strcpy(entrada,"11111111111111110000000000000000");
  strcpy(instrucaor.opcode,"111111");
  strcpy(condicional.operacao,instrucaor.opcode);
  //printf("Opcode=%s\n",condicional.operacao);
  //printf("Chegou?\n");
  //_____________________________


  UnidadeControle(&condicional);//MEXEU EM TODAS AS CONDICIONAIS

  BancoRegistradores("11111","11110","11100",&registradores,&condicional,&dados);//Busca dados para as operações de tipo R e Salva no Struct Dados
  ULA(&dados,"000000","100100",&condicional);//Realiza a operação com nossos Dados e salvará no Struct Dados
  if(condicional.RegWrite==true){//Converte nosso RegWrite em true, para chamarmos novamente o banco de dados com a função de salvar
    BancoRegistradores("11111","11110","11100",&registradores,&condicional,&dados);//Salvará nosso resultado retornado da ula no nosso Banco de Registradores
  }

  printf("Registrador R3 = %i\n",registradores.v1);
  return 0;
}
