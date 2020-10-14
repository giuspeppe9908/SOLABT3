//librerie da includere.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//variabile globale --- dimensione ---
#define DIM 80
//funzione main
void count_char(char* s, int dim);
int main(){
    char s[DIM];
    printf("Inserisci stringa:");
    fgets(s, sizeof(s), stdin);
    int lunghezza = strlen(s);
    count_char(s, lunghezza);
}
void count_char(char stringa[], int lungh){
    int conta[lungh], i, j;
    //CASO 1 : due caratteri consecutivi uguali
    for(i=0; i<lungh; i++)
    {
	   conta[i]=1;

	   for(j=i+1; j<lungh; j++)
		   if(stringa[i] == stringa[j])
			   conta[i]++;
   }
   //azzero elemento j se i caratteri sono uguali.
   for(i=0; i<lungh; i++)
   {
	   for(j=i+1; j<lungh; j++)
		   if(stringa[i] == stringa[j])
			   conta[j]=0;
   }
   //stampa vettore conta.
   for(i=0; i<lungh; i++)
   {
		if(conta[i] && conta[i]!='\0')
			printf("%d , %c\n", conta[i], stringa[i]); 
   }
}

