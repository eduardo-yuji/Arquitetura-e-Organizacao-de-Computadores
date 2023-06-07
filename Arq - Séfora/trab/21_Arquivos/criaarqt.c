 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <string.h>

 int main(){

   FILE *arq;
    char texto[100] = "sefora\n";
    // Abre o arquivo
    arq = fopen("teste2.txt","w");
    if(arq == NULL){
    printf("Erro na abertura do arquivo");
    exit(1); //finaliza o programa
    }//if
    // Percorre o vetor escrevendo no arquivo
    for (int i = 0; i < strlen(texto); i++) {
    fputc(texto[i],arq);
    }//for
    //Fecha o arquivo
    fclose(arq);
 	return 0;
 }//main
