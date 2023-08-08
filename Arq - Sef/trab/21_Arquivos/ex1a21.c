/*
@file: ex1a21.c
@author: Sefora Davanso
@date: 24/05/22
@brief: ex1a21
1) Escreva um programa que leia do usuário o nome de um arquivo
texto. Em seguida, mostre na tela quantas linhas esse arquivo possui
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    printf("Este programa recebe um arquivo e diz quantas linhas ele possui\n");
    FILE *arq;
	  char arquivo_txt[301];
    char fim_linha = '\n';
   	int linhas = 0;
//recebendo do usuário o nome do arquivo
    printf("Digite o nome do arquivo de texto:");
    scanf("%s", arquivo_txt );

//abrindo o arquivo
	arq = fopen(arquivo_txt, "r");
  if(arq == NULL){
  printf("Erro na abertura do arquivo");
  exit(1); //finaliza o programa
  }//if
//lendo o arquivo para contar as linhas
  fread (&arquivo_txt, sizeof(char), 200, arq);
//for que percorre todo o arquivo de texto e contabilizará as linhas
  for (int i = 0; i < strlen(arquivo_txt); i++){
//if para definir o fim de uma linha
        if(arquivo_txt[i] == fim_linha){
             linhas++;
     }//if
  }//for

    printf("\nLinhas do arquivo de texto é: %i\n",linhas + 1);

  fclose(arq);
	return 0;
}//main
