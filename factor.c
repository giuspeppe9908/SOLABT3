/*
  Programma "factor" : scompone in fattori primi un numero UNSIGNED int.
*/
#include <stdio.h>
#include <stdlib.h>
void Scomponi(unsigned int number, int b);
int main(){
   printf("SCOMPOSITORE IN FATTORI PRIMI\n");
   unsigned int number;
   int b=2;
   /*printf("MENU : 0) ESCI 1)Inserire Numero");
   while(number!=0 || number != 1){ */
   printf("Fornire un numero >> ");
   scanf("%d", &number);
   printf("\n %d = ", number);
   Scomponi(number, b);
   printf("\n");
   return 0;
}

void Scomponi(unsigned int number, int b){
      int tmp = b, a = 0;
      for(; number!=1; a++){
       while(number%b!=0){
          b++;
       }
          int divisori[a];
          number/=b;
          printf("%d",b);
          printf(" * ");
          b=2;
      }
}
