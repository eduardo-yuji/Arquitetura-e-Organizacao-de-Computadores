
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct {
    int opcode[4];
    int rs[4];
    int rt[4];
    int rd[4];
} R_Format;

int main(){
  FILE *arq, *arq2;
  char arquivo_txt[301];
  char leitor[301];

  R_Format regis_r;
  R_Format teste;

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
  if(strcmp("add",leitor) == 0){
      strcpy(regis_r.opcode, "0001");

      fscanf(arq, "%s", leitor);
        if(strcmp("$t0",leitor) == 0){
          strcpy(regis_r.rd, "0001");
        }else if(strcmp("$t1",leitor) == 0){
          strcpy(regis_r.rd, "0010");
        }else if(strcmp("$t2",leitor) == 0){
          strcpy(regis_r.rd, "0011");
        }
            fscanf(arq, "%s", leitor);
        if(strcmp("$t0",leitor) == 0){
            strcpy(regis_r.rs, "0001");
          }else if(strcmp("$t1",leitor) == 0){
            strcpy(regis_r.rs, "0010");
          }else if(strcmp("$t2",leitor) == 0){
            strcpy(regis_r.rs, "0011");
          }

              fscanf(arq, "%s", leitor);
          if(strcmp("$t0",leitor) == 0){
              strcpy(regis_r.rt, "0001");
            }else if(strcmp("$t1",leitor) == 0){
              strcpy(regis_r.rt, "0010");
            }else if(strcmp("$t2",leitor) == 0){
              strcpy(regis_r.rt, "0011");
            }

    fprintf(arq2, "%s %s %s %s\n", regis_r.opcode, regis_r.rs, regis_r.rt, regis_r.rd);

}//if

}//while


  fclose(arq2);
  fclose(arq);
  return 0;
} // main
