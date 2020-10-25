#include <stdio.h>
#include <stdlib.h>
int MAX = 20;
//funzione prototipo
int range_of_even(int * nums , int length , int * min , int * max );
void RiempiArray(int * nums, int length);
//main
int main(){
   printf("Dimensione array ? > ");
   scanf("%d", &MAX);
   int nums[MAX], min, max;
   //Funzione che riempie l'array...
   RiempiArray(nums, MAX);
   int ris = range_of_even(nums, MAX, &min, &max);
   printf("Il risultato e' : %d\n",ris);
}
void RiempiArray(int nums[], int length){
     for(int i=0; i<length; i++){
	     printf("Inserire valore in pos. [%d] > ", i);
	     scanf("%d", &nums[i]);
	 }
}
int range_of_even(int nums[], int length, int *min, int *max){ 
    int ris = 0;
    int i=0;
    for(; i<length; i++){
		/*Se il valore in pos. i è pari lo confronto con il minimo*/
	   if((nums[i]%2)==0){
	      if(nums[i] < *min){
		     *min = nums[i];
		  }
		  if(nums[i] > *max){
		     *max = nums[i];
		  }
		  ris = 1;
	   }
	}
    return ris;
}
