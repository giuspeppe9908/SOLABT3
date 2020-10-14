/* Programma in C scritto da Giuseppe Pio Lobascio
   Senza usare operazione di divisione o di modulo (%).
   Focus del programma : 
   Convertire un intero in binario con operatori bitwise o shitf 
   operator.
   N.B. : Ho incluso solo la libreria stdio.h per printf e scanf.
*/
#include <stdio.h>
#define INT_SIZE sizeof(int) * 8//intero in bits sizeof(intero) = 4 bit * 8 = 32 cifre
int main(){
  printf("INT TO BIN CONVERTER.\n");
  int numero, tmp;//numero che fornisco in input.
  int BinVector[INT_SIZE];//inizializzo un vettore che ha come lunghezza
  //la INT_SIZE.
  printf("Inserire numero da convertire in binario _> ");
  scanf("%d", &numero);
  tmp = numero;//copio in tmp.
  int indice = INT_SIZE -1;
  while(indice >= 0){
        BinVector[indice] = tmp & 1;
        //decremento indice
        indice--;
        //shift a dx di 1.
        tmp >>= 1;
  }
  /*Stampo l'array */
  printf("%d in binario equivale a : ",numero);
  for(int i=0; i<INT_SIZE; i++){
      printf("%d", BinVector[i]);
  }
  printf("\nProgramma in C scritto da Giuseppe Pio Lobascio®.");
  return 0;
}
