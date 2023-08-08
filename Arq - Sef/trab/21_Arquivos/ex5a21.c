/*
!!
@file: ex5a21.c
@author: Sefora Davanso
@date: 24/05/22
@brief: ex5a21
5) Elabore um programa para calcular e exibir o número de
vezes que cada letra ocorre dentro de um arquivo texto.
Ignore as letras com acento. O usuário deverá informar o
nome do arquivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    printf("Este programa calcula o numero de vezes que uma letra ocorre dentro de um arquivo de texto\n");
    FILE *arq;
	  char arquivo_txt[301];
    int* ordem, i = 64, posicacao = 0;
    char caracter;

//recebendo do usuário o nomes do arquivo
    printf("Digite o nome do arquivo que terá suas letras contadas:");
    scanf("%s", arquivo_txt);

//abrindo o arquivo
	arq = fopen(arquivo_txt, "r");
  if (arq == NULL){
    printf("Erro na abertura do arquivo");
    exit(1); // finaliza o programa
  }// if

//utilizando tabela ASCII

  ordem = calloc(26,sizeof(int));
  while (!(feof(arq))){
//pegando o caracter
    caracter = fgetc(arq);
//percorrendo todo o alfabeto da tabela e comparar com o caracter
    for (i = 65,posicacao = 0; i <= 90; i++, posicacao++) {
      if (caracter == i || caracter == i + 32) {
        ordem[posicacao]++;
      }//if
    }//for
  }//while

//para exibir as quantidades
  for (int i = 0; i < 26; i++) {
    printf("%c: %d vezes\n", i + 65, ordem[i] );
  }//for

  fclose(arq);
	return 0;
}//main
