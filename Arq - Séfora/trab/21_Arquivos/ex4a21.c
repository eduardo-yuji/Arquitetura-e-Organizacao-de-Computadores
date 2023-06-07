/*
@file: ex4a21.c
@author: Sefora Davanso
@date: 24/05/22
@brief: ex4a21
4) Crie um programa para calcular e exibir o número de palavras
contido em um arquivo texto. O usuário deverá informar o nome do
arquivo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(){
    FILE *arq;
    char arquivo_txt[301];
    int palavras = 0;
    char leitor[301];

    printf("Este programa calcula o numero de palavras de um arquivo de texto\n");
    // recebendo do usuário o nomes do arquivo

    printf("Digite o nome do arquivo que terá suas palavras contadas:");
    scanf("%s", arquivo_txt);

    // abrindo o arquivo
    arq = fopen(arquivo_txt, "r");
    if (arq == NULL){
        printf("Erro na abertura do arquivo");
        exit(1); // finaliza o programa
    }// if

    // acessando o conteudo do arquivo e contando as palavras
    while (!(feof(arq))){
        fscanf(arq, "%s", leitor);
        palavras++;
    }
    printf("O total de palavras é de: %d\n", palavras);
    fclose(arq);
    return 0;
} // main
