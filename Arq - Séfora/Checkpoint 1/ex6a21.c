/*
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
  printf("Este programa calcula o numero de vezes que uma palavra ocorre dentro de um arquivo de texto\n");
  FILE *arq;
  char arquivo_txt[301], palavra[21];
  char leitor[301];
  int achei = 0;
  // recebendo do usuário o nome do arquivo e a palavra
  printf("\nDigite o nome do arquivo que terá sua palavra encontrada:");
  scanf("%s", arquivo_txt);
  setbuf(stdin, NULL);

  printf("\nDigite a palavra que sera contada:");
  fgets(palavra, 21, stdin);
  palavra[strcspn(palavra, "\n")] = '\0';
  setbuf(stdin, NULL);

  // abrindo o arquivo
  arq = fopen(arquivo_txt, "r");
  if (arq == NULL){
    printf("Erro na abertura do arquivo");
    exit(1); // finaliza o programa
  }// if

  // acessando o conteudo do arquivo e contando as palavras
  while (!(feof(arq))){
    fscanf(arq, "%s", leitor);
    if (strcmp(fscanf(arq, "%s", leitor), palavra) == 0){
      achei++;
    }// if
  }// while

  printf("\nO total de vezes que essa palavra aparece é de: %d\n", achei);
  fclose(arq);
  return 0;
} // main
