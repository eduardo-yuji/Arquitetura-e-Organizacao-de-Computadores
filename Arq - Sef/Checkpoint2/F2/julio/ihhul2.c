
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


typedef struct {
    char opcode[6];// mudei todos para 6 por causa q estava dando overflow
    char rs[6];
    char rt[6];
    char rd[6];
} R_Format;

typedef struct {
      char opcode[6];
      char rs[6];
      char rd[6];
      int cons;
      char cons1[6];
      int cons2[6];
} I_Format;

typedef struct {
      char opcode[6];
      char rd[6];
      int cons[10]; // mudei para 10 pq estava dando overflow
} J_Format;

int main(){
  FILE *arq, *arq2;
  char arquivo_txt[301];
  char leitor[301];

  R_Format ass;
  R_Format bin;

  I_Format ass1;
  I_Format bin1;

  char aux[100];


  arq2 = fopen("bin2.dat","wb");

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
sscanf(aux, "%[^ ]\n", ass.opcode);

//if tipo R
if (strcmp("add",ass.opcode) == 0 || strcmp("sub",ass.opcode) == 0 ||
    strcmp("and",ass.opcode) == 0 || strcmp("or",ass.opcode) == 0 ||
    strcmp("xor",ass.opcode) == 0 || strcmp("slt",ass.opcode) == 0 ||
    strcmp("lw",ass.opcode) == 0 || strcmp("sw",ass.opcode) == 0 ) {

sscanf(aux, "%[^ ] %[^,], %[^,], %[^\n]\n", ass.opcode, ass.rd, ass.rs, ass.rt);

      if(strcmp("add",ass.opcode) == 0){
          strcpy(bin.opcode, "0001");
        }else if(strcmp("sub",ass.opcode) == 0){
          strcpy(bin.opcode, "0011 ");
        }else if(strcmp("and",ass.opcode) == 0){
          strcpy(bin.opcode, "0100 ");
        }else if(strcmp("or",ass.opcode) == 0){
          strcpy(bin.opcode, "0101 ");
        }else if(strcmp("xor",ass.opcode) == 0){
          strcpy(bin.opcode, "0110 ");
        }else if(strcmp("slt",ass.opcode) == 0){
          strcpy(bin.opcode, "0111 ");
        }else if(strcmp("sw",ass.opcode) == 0){
          strcpy(bin.opcode, "0001 ");
        }else if(strcmp("lw",ass.opcode) == 0){
          strcpy(bin.opcode, "0000 ");
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
      strcpy(bin.rd, "0000 "); // estava arq2
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
    }//if rt

fprintf(arq2, "%s %s %s %s\n", bin.opcode, bin.rs, bin.rt, bin.rd);

//if para o tipo i
}else if (strcmp("beq",ass.opcode) == 0 || strcmp("blt",ass.opcode) == 0) {

  sscanf(aux, "%[^ ] %[^,], %[^,], %[^\n]\n", ass1.opcode, ass1.rd, ass1.rs, ass1.cons1);//mudei ass.opcode para ass1.opcode
  if(strcmp("beq",ass1.opcode) == 0){
      strcpy(bin1.opcode, "1100 ");
    }else if(strcmp("blt",ass1.opcode) == 0){
      strcpy(bin1.opcode, "1101 ");
    }// if opcode
    printf("\n*%s*\n", bin1.opcode);

    if(strcmp("$zero",ass1.rs) == 0){
      strcpy(bin1.rs, "0000 ");
    }else if(strcmp("$t0",ass1.rs) == 0){
      strcpy(bin1.rs, "0001 ");
    }else if(strcmp("$t1",ass1.rs) == 0){
      strcpy(bin1.rs, "0010 ");
    }else if(strcmp("$t2",ass1.rs) == 0){
      strcpy(bin1.rs, "0011 ");
    }else if(strcmp("$a0",ass1.rs) == 0){
      strcpy(bin1.rs, "0100 ");
    }else if(strcmp("$a1",ass1.rs) == 0){
      strcpy(bin1.rs, "0101 ");
    }else if(strcmp("$a2",ass1.rs) == 0){
      strcpy(bin1.rs, "0110 ");
    }else if(strcmp("$s0",ass1.rs) == 0){
      strcpy(bin1.rs, "0111 ");
    }else if(strcmp("$s1",ass1.rs) == 0){
      strcpy(bin1.rs, "1000 ");
    }else if(strcmp("$s2",ass1.rs) == 0){
      strcpy(bin1.rs, "1001 ");
    }else if(strcmp("$s3",ass1.rs) == 0){
      strcpy(bin1.rs, "1010 ");
    }else if(strcmp("$s4",ass1.rs) == 0){
      strcpy(bin1.rs, "1011 ");
      printf("\n-%s-\n", bin1.rs);

  }//if rs

  if(strcmp("$zero",ass1.rd) == 0){
  strcpy(bin1.rd, "0000 "); //estava arq2
  }else if(strcmp("$t0",ass1.rd) == 0){
  strcpy(bin1.rd, "0001 ");
  }else if(strcmp("$t1",ass1.rd) == 0){
  strcpy(bin1.rd, "0010 ");
  }else if(strcmp("$t2",ass1.rd) == 0){
  strcpy(bin1.rd, "0011 ");
  }else if(strcmp("$a0",ass1.rd) == 0){
  strcpy(bin1.rd, "0100 ");
  }else if(strcmp("$a1",ass1.rd) == 0){
  strcpy(bin1.rd, "0101 ");
  }else if(strcmp("$a2",ass1.rd) == 0){
  strcpy(bin1.rd, "0110 ");
  }else if(strcmp("$s0",ass1.rd) == 0){
  strcpy(bin1.rd, "0111 ");
  }else if(strcmp("$s1",ass1.rd) == 0){
  strcpy(bin1.rd, "1000 ");
  }else if(strcmp("$s2",ass1.rd) == 0){
  strcpy(bin1.rd, "1001 ");
  }else if(strcmp("$s3",ass1.rd) == 0){
  strcpy(bin1.rd, "1010 ");
}else if(strcmp("$s4",ass1.rd) == 0){
  strcpy(bin1.rd, "1011 ");

  }

  bin1.cons = atoi(ass1.cons1);
  bin1.cons2[0] = 0;
  bin1.cons2[1] = 0;
  bin1.cons2[2] = 0;
  bin1.cons2[3] = 0;
  bin1.cons2[4] = 0;
  bin1.cons2[5] = 0;
  bin1.cons2[6] = 0;
  if(bin1.cons == 0){
     bin1.cons2[0] = 0;
    bin1.cons2[1] = 0;
    bin1.cons2[2] = 0;
    bin1.cons2[3] = 0;
    bin1.cons2[4] = 0;
    bin1.cons2[5] = 0;
    bin1.cons2[6] = 0;
  }

  int i;
  while(bin1.cons > 0){
    bin1.cons2[i++] = bin1.cons%2;
    bin1.cons /=2;

  }




fprintf(arq2, "%s %s %s ", bin1.opcode, bin1.rs, bin1.rd);
for(int j = 5; j>= 0;j--){
  fprintf(arq2, "%d", bin1.cons2[j]);
}
fprintf(arq2,"\n");
//if para o tipo j
}





}//while


  fclose(arq2);
  fclose(arq);
  return 0;
} // main
