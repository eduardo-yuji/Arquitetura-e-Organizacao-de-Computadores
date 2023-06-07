
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

typedef struct {
    int opcode[4];
    int rs[4];
    int rt[4];
    int cons[4];
} I_Format;

typedef struct {
    int opcode[4];
    int rd[4];
    int cons[8]
} J_Format;

int main(){
  FILE *arq, *arq2;
  char arquivo_txt[301];
  char leitor[301];

  R_Format ass;
  R_Format bin;


  char aux[100];


  arq2 = fopen("bin.dat","wb");

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

  while(fgets(aux, 100, arq) != NULL) {
     //Percorre o arquivo ate chegar no final
 		//Formata a string aux por meio da expressão regular
  sscanf(aux, "%[^ ] %[^,], %[^,], %[^\n]\n", ass.opcode, ass.rd, ass.rs, ass.rt);



  if(strcmp("add",ass.opcode) == 0){
      strcpy(bin.opcode, "0001");
    }else if(strcmp("sub",ass.opcode) == 0){
      strcpy(bin.opcode, "0011 ");
    }else if(strcmp("addi",ass.opcode) == 0){
      strcpy(bin.opcode, "1000 ");
    }else if(strcmp("sft",ass.opcode) == 0){
      strcpy(bin.opcode, "1001 ");
    }// if opcode

    if(strcmp("$zero",ass.rs) == 0){
      strcpy(bin.rs, "0000 ");
    }else if(strcmp("$t0",ass.rs) == 0){
      strcpy(bin.rs, "0001 ");
    }else if(strcmp("$t1",ass.rs) == 0){
      strcpy(bin.rs, "0010 ");
    }else if(strcmp("$t2",ass.rs) == 0){
      strcpy(bin.rs, "0011 ");
    }else if(strcmp("$a0",ass.rs) == 0){
      strcpy(bin.rs, "0100 ");
    }else if(strcmp("$a1",ass.rs) == 0){
      strcpy(bin.rs, "0101 ");
    }else if(strcmp("$a2",ass.rs) == 0){
      strcpy(bin.rs, "0110 ");
    }else if(strcmp("$s0",ass.rs) == 0){
      strcpy(bin.rs, "0111 ");
    }else if(strcmp("$s1",ass.rs) == 0){
      strcpy(bin.rs, "1000 ");
    }else if(strcmp("$s2",ass.rs) == 0){
      strcpy(bin.rs, "1001 ");
    }else if(strcmp("$s3",ass.rs) == 0){
      strcpy(bin.rs, "1010 ");
    }else if(strcmp("$s4",ass.rs) == 0){
      strcpy(bin.rs, "1011 ");

}//if rs

if(strcmp("$zero",ass.rd) == 0){
  strcpy(arq2, "0000 ");
}else if(strcmp("$t0",ass.rd) == 0){
  strcpy(bin.rd, "0001 ");
}else if(strcmp("$t1",ass.rd) == 0){
  strcpy(bin.rd, "0010 ");
}else if(strcmp("$t2",ass.rd) == 0){
  strcpy(bin.rd, "0011 ");
}else if(strcmp("$a0",ass.rd) == 0){
  strcpy(bin.rd, "0100 ");
}else if(strcmp("$a1",ass.rd) == 0){
  strcpy(bin.rd, "0101 ");
}else if(strcmp("$a2",ass.rd) == 0){
  strcpy(bin.rd, "0110 ");
}else if(strcmp("$s0",ass.rd) == 0){
  strcpy(bin.rd, "0111 ");
}else if(strcmp("$s1",ass.rd) == 0){
  strcpy(bin.rd, "1000 ");
}else if(strcmp("$s2",ass.rd) == 0){
  strcpy(bin.rd, "1001 ");
}else if(strcmp("$s3",ass.rd) == 0){
  strcpy(bin.rd, "1010 ");
}else if(strcmp("$s4",ass.rd) == 0){
  strcpy(bin.rd, "1011 ");

}//if rd

if(strcmp("$zero",ass.rt) == 0){
  strcpy(bin.rt, "0000 ");
}else if(strcmp("$t0",ass.rt) == 0){
  strcpy(bin.rt, "0001 ");
}else if(strcmp("$t1",ass.rt) == 0){
  strcpy(bin.rt, "0010 ");
}else if(strcmp("$t2",ass.rt) == 0){
  strcpy(bin.rt, "0011 ");
}else if(strcmp("$a0",ass.rt) == 0){
  strcpy(bin.rt, "0100 ");
}else if(strcmp("$a1",ass.rt) == 0){
  strcpy(bin.rt, "0101 ");
}else if(strcmp("$a2",ass.rt) == 0){
  strcpy(bin.rt, "0110 ");
}else if(strcmp("$s0",ass.rt) == 0){
  strcpy(bin.rt, "0111 ");
}else if(strcmp("$s1",ass.rt) == 0){
  strcpy(bin.rt, "1000 ");
}else if(strcmp("$s2",ass.rt) == 0){
  strcpy(bin.rt, "1001 ");
}else if(strcmp("$s3",ass.rt) == 0){
  strcpy(bin.rt, "1010 ");
}else if(strcmp("$s4",ass.rt) == 0){
  strcpy(bin.rt, "1011 ");
}else if(strcmp("100",ass.rt) == 0){
  strcpy(bin.rt, "01100100 ");
}//if rd

    fprintf(arq2, "%s %s %s %s\n", bin.opcode, bin.rs, bin.rt, bin.rd);

}//while


  fclose(arq2);
  fclose(arq);
  return 0;
} // main
