
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct{
  int opcode[4];
  int regs[4];
  int regt[4];
  int regd[4];
} Formato_R;

typedef struct{
  int opcode[4];
  int regs[4];
  int constante[16];  
} Formato_R;


int main(){

  FILE *arq_bin;
  Binario completos[301];

  //abrindo o arquivo para pegar os numeros
  arq_bin = fopen("bin.dat","rb");
   if(arq_bin == NULL){
   printf("Erro ao abrir o arquivo!\n");
   exit(1);
   }// if



  return 0;
} // main
