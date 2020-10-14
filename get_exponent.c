#include <stdio.h>
#include <stdlib.h>
/* Programma GET-EXPONENT */
/*Variabili globali*/
float D = 2.0;
/*Prototipi delle Funzioni*/
int get_exp(double v, int *exptr);
double mModn(double, float);
unsigned int logDue(double, float);
/*////////////////////////*/
int main(){
  //1. Leggere double da tastiera.
  double var;
  int n;
  printf("Valore di 'var' : ");
  scanf("%le", &var);
  //2. Estrarre esponente da rappresentazione in floating point.
  printf("Rappresentazione floating point \n %lf = ", var);
  int exp = get_exp(var, &n);
  //3. stampa esponente in decimale.
  printf(" * 2 ^ %d\n", exp);
  printf("\nProgramma in C scritto da Giuseppe Pio Lobascio®.");
  return 0;
}
int get_exp(double var, int *p){
    //Algoritmo euclideo (easy)
    //calcolo esponente finale.
    double ris = mModn(var, D);
    printf("%lf", ris);
    if(ris == 0){
	   *p = 0;
	}
	else *p = (int)(1 + logDue(var, D));
    return *p;
}

double mModn(double v, float D){
     double q = v/D, t=q;
     //printf("t vale : %lf\n", t);
     if(abs((int)q) >= 0.5){
     t = mModn(q,D);
     } 
   return t;
}
//funzione log2(b,2);
unsigned int logDue(double v, float D){
	return (v > D) ? 1 + logDue(v / D, D) : 0; 
} 
