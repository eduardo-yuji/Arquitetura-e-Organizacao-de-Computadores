//para ler
char str[20]="Ola arquivo";
float numero = 5.23;
int vetor[5] = {10, 20, 30, 40, 50};

FILE *arq = fopen("arquivo.bin","wb");
...
fwrite(str,sizeof(char),20,arq);
fwrite(&numero,sizeof(float),1,arq);
fwrite(vetor,sizeof(float),5,arq);
fclose(arq);

//para escrever
char str[20];
float numero ;
int vetor[5];
FILE *arq = fopen("arquivo.bin","rb"); //Abre o arquivo
...
fread(str,sizeof(char),20,arq);// Lê 20 caracteres
fread(&numero,sizeof(float),1,arq);// Lê um número real
fread(vetor,sizeof(float),5,arq);// Lê o vetor de tamanho 5
// Exibe os dados lidos
printf("Texto: %s\n",str);
printf("Float: %.2f\n",numero);
for (int i = 0; i < 5; i++) {
printf("%i ",vetor[i]);
}//for
fclose(arq);

//exemplo de fprintf
char texto[20] = "Apucarana";
 float real = 5.26;
 int inteiro = 42;
 FILE *arq = fopen("arquivo.txt","w"); //Abre o arquivo
...
//Realiza a escrita utilizando o fprintf
 fprintf(arq,"Texto: %s\n", texto);
 fprintf(arq,"Real: %f", real);
 fprintf(arq,"Inteiro: %i", inteiro);
 fclose(arq);

 //exemplo de fscanf
 char texto[20] = "Apucarana"
, label[20];
 float real = 5.26;
 int inteiro = 42;
 FILE *arq = fopen("arquivo.txt","w"); //Abre o arquivo
...
//Realiza a leitura utilizando o fscanf
 fscanf(arq,"%s %s\n", label, texto);
 fscanf(arq,"%s %f", label, &real);
 fscanf(arq,"%s %i", label, &inteiro);
//Exibe os dados lidos
 printf("Texto: %s\n", texto);
 printf("Real: %f", real);
 printf("Inteiro: %i", inteiro);
 fclose(arq);

//movendo-se pelo arquivo
int fseek(FILE* arq, int deslocamento, int origem);
