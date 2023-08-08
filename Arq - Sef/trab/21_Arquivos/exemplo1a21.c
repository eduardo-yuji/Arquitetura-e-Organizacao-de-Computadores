//para manipular arqs
FILE *fp;

//para abrir
FILE* fopen(char* nome_arquivo, char* modo);

FILE* fopen(char* nome_arquivo, char* modo); FILE *arq = fopen("dados.txt","w");
 if(arq == NULL){
 printf("Erro ao abrir o arquivo!\n");
 exit(1);// 1 significa erro
 }// if
 fclose(arq);

 //para ler e escrever char
 FILE *arq;
 char texto[100] = "Texto que sera escrito no arquivo";
 // Abre o arquivo
 arq = fopen("arquivo.txt",
"r");
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

 FILE *arq;
  char c;
  // Abre o arquivo
  arq = fopen("arquivo.txt", "r");
  if(arq == NULL){
  printf("Erro na abertura do arquivo");
  exit(1); //finaliza o programa
  }//if
  // Lê enquanto não chegar no fim do arquivo
  while ((c = fgetc(arq)) != EOF) {
  printf("%c",c);
  }//for
  //Fecha o arquivo
  fclose(arq);

//para ler escrever string
  FILE *arq;
char texto[100] = "Texto que sera escrito via fputs";
int resultado;
// Abre o arquivo
arq = fopen("arquivo.txt","w");
if(arq == NULL){
printf("Erro na abertura do arquivo\n");
exit(1); //finaliza o programa
}//if
fputs(texto, arq);// Escreve o texto do arquivo
if (resultado == EOF) {
printf("Erro na gravação\n");
}//for
fclose(arq); //Fecha o arquivo

FILE *arq;
 char texto[100];
 char* resultado;
 arq = fopen("arquivo.txt","r"); // Abre o arquivo
 if(arq == NULL){
 printf("Erro na abertura do arquivo\n");
 exit(1); //finaliza o programa
 }//if
 fgets(texto, 100,arq);// Lê o texto do arquivo
 if (resultado == EOF) {
 printf("Erro na leitura\n");
 }else{
printf("%s\n",texto);
 }//else
 fclose(arq);//Fecha o arquivo
