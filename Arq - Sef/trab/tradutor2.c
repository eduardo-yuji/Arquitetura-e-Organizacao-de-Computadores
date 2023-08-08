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
  switch (leitor) {
    case "add":
      fprintf(arq2, "0010 ");
    break;
  

  fclose(arq2);
  fclose(arq);
  return 0;
} // main
