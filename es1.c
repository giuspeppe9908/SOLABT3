#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
   char s1[80];//ciao a tutti --> 11
   char s2[80];//ia --> 2
   printf("Inserire prima stringa : ");
   fgets(s1,sizeof(s1),stdin);
   printf("Inserire seconda stringa : ");
   fgets(s2,sizeof(s2),stdin);
   int i=0, ris = 0;
   if(strlen(s2) > strlen(s1)) return -1;
   for(; ris == 0 && i < strlen(s1)-1; i++)
       if(s1[i] == s2[0]){
		 ris = 1;
		 for(int j=0; ris==0 && j < strlen(s2)-1; j++){
		     if(i+j >= strlen(s1) || s1[i+j] != s2[j]) ris = 1;
		 }   
	   }
   if(ris==1){
      for( int j = i + strlen(s2) - 2; j < strlen(s1); j++)
         printf("%c", s1[j]);
   }
}
