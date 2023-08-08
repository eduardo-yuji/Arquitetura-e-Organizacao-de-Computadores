/*
@file: ex3a21.c
@author: Sefora Davanso
@date: 24/05/22
@brief: ex3a21
3) Escreva um programa para converter o conteúdo de um arquivo
texto em caracteres maiúsculos. O programa deverá ler do usuário o
nome do arquivo a ser convertido e o nome do arquivo a ser salvo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    printf("Este programa recebe converte o conteudo de um arquivo em letras maiúsculas\n");
    FILE *arq1, *arq2;
	  char arquivo_txt1[301], arquivo_txt2[301];
    int i;
//recebendo do usuário os nomes dos arquivos
    printf("Digite o nome do arquivo que terá seu texto convertido:");
    scanf("%s", arquivo_txt1 );
    printf("Digite o nome do arquivo para salvar o texto apos a conversao:");
    scanf("%s", arquivo_txt2 );

//abrindo os arquivos
	arq1 = fopen(arquivo_txt1, "r");
  if(arq1 == NULL){
  printf("Erro na abertura do arquivo");
  exit(1); //finaliza o programa
  }//if
  arq2 = fopen(arquivo_txt2, "w");
  if(arq2 == NULL){
  printf("Erro na abertura do arquivo");
  exit(1); //finaliza o programa
  }//if


//acessando o conteudo do arquivo e trasnformando e maiúsculas
  while((i = fgetc(arq1))!= EOF){
    fputc(toupper(i),arq2);
  }

  fclose(arq1);
  fclose(arq2);
	return 0;
}//main
