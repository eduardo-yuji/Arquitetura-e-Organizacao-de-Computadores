/*
@file: ex2a21.c
@author: Sefora Davanso
@date: 24/05/22
@brief: ex2a21
2) Escreva um programa que leia do usuário os nomes de dois
arquivos texto. Crie um terceiro arquivo texto com o conteúdo dos
dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do
segundo).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    printf("Este programa recebe dois arquivos e cria um terceiro com o conteudo de ambos\n");
    FILE *arq1, *arq2, *arq3;
	  char arquivo_txt1[301], arquivo_txt2[301];
    char conteudo1[301], conteudo2[301];
    char *resultado1, *resultado2;

//recebendo do usuário os nomes dos arquivos
    printf("Digite o nome do primeiro arquivo de texto:");
    scanf("%s", arquivo_txt1 );
    printf("Digite o nome do segundo arquivo de texto:");
    scanf("%s", arquivo_txt2 );

//abrindo os arquivos
	arq1 = fopen(arquivo_txt1, "r");
  if(arq1 == NULL){
  printf("Erro na abertura do arquivo");
  exit(1); //finaliza o programa
  }//if
  arq2 = fopen(arquivo_txt2, "r");
  if(arq2 == NULL){
  printf("Erro na abertura do arquivo");
  exit(1); //finaliza o programa
  }//if

//acessando o conteudo dos arquivos
 fgets(conteudo1,301,arq1);
 fgets(conteudo2,301,arq2);

 //abrindo o arquivo tres
 arq3 = fopen("arquivoconcatenado.txt","w");
 if(arq3 == NULL){
 printf("Erro na abertura do arquivo");
 exit(1); //finaliza o programa
 }//if
//pegando os conteudo do arquivo 1 e 2 e colocando no 3
 fputs(conteudo1,arq3);
  if ( resultado1 == EOF) {
    printf("Erro na gravação\n");
  }
 fputs(conteudo2,arq3);
  if ( resultado1 == EOF) {
   printf("Erro na gravação\n");
 }

  fclose(arq1);
  fclose(arq2);
  fclose(arq3);
	return 0;
}//main
