/*Il programma scrive nel
  file argv[2] le righe del file argv[1] in ordine casuale (si veda man 3 rand per numeri casuali). Una riga si identifica come una
  sequenza di byte terminata dal carattere “a capo”.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define M2 30
#define M1 130
/*Variabili globali...*/
char words[200];
char lines[M2][M1];
/* Functions Prototipes */
int RandomNumberGenerator(int from, int to, int N);
/*Main Function...*/
int main(int argc, char **argv){
    FILE *source, *dest;
    char *res;
    int dim = 0;
    argv[0]="file-shuffle-rows.c";
    argv[1]="source.txt";
    argv[2]="dest.txt";
    //controllo che il main ha ricevuto 2 argomenti)
    if(argc != 3){
       fprintf(stdout,"Esegui il programma con sintassi : ./[nome programma].out [fileInput.estensione] [fileOutput.estensione]\n");
       fflush(stdout);
        exit(1);
    }
    source = fopen(argv[1], "r");
    while(fgets(lines[dim], M1, source)){
       lines[dim][strlen(lines[dim])-1] = '\0';
       dim++;
    }
    int num = dim;
    /*Stampa del vettore lines...*/
    printf("Il vettore delle righe del file ha questo contenuto : \n");
      for(dim = 0; dim < num; dim++){
         printf("[%d] %s\n",dim , lines[dim]);
      }
      printf("\n");
      printf("Avvio operazione di scrittura nel file 'dest.txt'...\n");
      dest = fopen(argv[2],"w");
      int i=0;
      while(i<=num){
         int random = RandomNumberGenerator(0,num+1,1);
         fprintf(dest, "%s\n", lines[random]);
         i++;
      }
      printf("Operazione terminata.\n");
      printf("Chiudo i file e termino programma...\n");
  fclose(source);
  fclose(dest);
  return 0;
}

int RandomNumberGenerator(const int nMin, const int nMax, const int  nNumOfNumsToGenerate)
{
  int nRandomNumber = 0;
  for (int i = 0; i < nNumOfNumsToGenerate; i++){
       nRandomNumber = rand()%(nMax-nMin) + nMin;
  }
 return nRandomNumber;
}
