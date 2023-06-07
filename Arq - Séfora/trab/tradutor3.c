/*
!!
@file: ex6a21.c
@author: Sefora Davanso
@date: 24/05/22
@brief: ex6a21
6) Elabore um programa no qual o usuário informe o nome
de um arquivo texto e uma palavra, e o programa informe o
número de vezes que aquela palavra aparece
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
  FILE *arq, *arq2;
  char arquivo_txt[301];
  char leitor[301];

  arq2 = fopen("bin.dat","w");

  // recebendo do usuário o nome do arquivo e a palavra
  printf("\nDigite o nome do arquivo em assembly:");
  scanf("%s", arquivo_txt);
  setbuf(stdin, NULL);

  // abrindo o arquivo
  arq = fopen(arquivo_txt, "r");
  if (arq == NULL){
    printf("Erro na abertura do arquivo");
    exit(1); // finaliza o programa
  }// if

while (!feof(arq)) {
fscanf(arq, "%s", leitor);
  if(strcmp("add",leitor) == 0 || strcmp("sub",leitor) == 0){





  }else if(strcmp("addi",leitor) == 0 || strcmp("sft",leitor) == 0){

  }



  }else if(strcmp("$zero",leitor) == 0){
    fprintf(arq2, "0000 ");
  }else if(strcmp("$t0",leitor) == 0){
    fprintf(arq2, "0001 ");
  }else if(strcmp("$t1",leitor) == 0){
    fprintf(arq2, "0010 ");
  }else if(strcmp("$t2",leitor) == 0){
    fprintf(arq2, "0011 ");
  }else if(strcmp("$a0",leitor) == 0){
    fprintf(arq2, "0100 ");
  }else if(strcmp("$a1",leitor) == 0){
    fprintf(arq2, "0101 ");
  }else if(strcmp("$a2",leitor) == 0){
    fprintf(arq2, "0110 ");
  }else if(strcmp("$s0",leitor) == 0){
    fprintf(arq2, "0111 ");
  }else if(strcmp("$s1",leitor) == 0){
    fprintf(arq2, "1000 ");
  }else if(strcmp("$s2",leitor) == 0){
    fprintf(arq2, "1001 ");
  }else if(strcmp("$s3",leitor) == 0){
    fprintf(arq2, "1010 ");
  }else if(strcmp("$s4",leitor) == 0){
    fprintf(arq2, "1011 ");
  }else if(strcmp("100",leitor) == 0){
    fprintf(arq2, "01100100 ");

  }else{
      fprintf(arq2, " ");
  }
}

  fclose(arq2);
  fclose(arq);
  return 0;
} // main
