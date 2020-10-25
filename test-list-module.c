#include <stdio.h>
#include "list-module.h"
int main()
{       typedef node* list;
	printf("Operazioni su liste concatenate...\n");
	list head = NULL;
	/* insert some numbers in the list... */
	head = list_insert_head(head, 31);//ultimo elemento
	head = list_insert_head(head, 21);
	head = list_insert_head(head, 10);//primo elemento
	head = list_insert_ordered(head, 50);//elemento da inserire in più
	/* ... print them... */
	printf("Stampa Lista head : \n");
	list_print(head);
	printf("Cancello i valori nelle posizioni dispari della prima lista (chiamata HEAD)...\n");
	head = list_delete_odd(head);
	printf("Stampo la lista dopo il metodo list_delete_odd...\n");
	list_print(head);
	/* ... and clean everything up  */
	list l = NULL;
	l = list_insert_head(l, 20);
	l = list_insert_head(l, 11);
	l = list_insert_head(l, 12);
	printf("Stampa Lista l : \n");
	list_print(l);
	printf("Concatenazione (l, head) : \n");
	list_print(list_cat(l, head));
	//Creo una nuova lista...
	list nuova = NULL;
	nuova = list_insert_head(nuova, 43);
        nuova = list_insert_head(nuova, 78);
	nuova = list_insert_head(nuova, 22);
        nuova = list_insert_head(nuova, 11);
        nuova = list_insert_head(nuova, 99);
        nuova = list_insert_tail(nuova, 33);
	/*metodi effettuati sulla 3^ lista...*/
	printf("Esecuzione metodo insert_tail su 3^ lista...\n Mostro la terza lista : \n");
	list_print(nuova);
	printf("Tolgo dalla lista (nuova) il valore in testa.\n");
	nuova = list_delete_if(nuova, 22);
	printf("Stampo la lista dopo il metodo list_delete_if...\n");
	list_print(nuova);
	int valore = 33;
	printf("Rimuovo dalla terza lista (chiamata NUOVA) ogni elemento < di %d.\n", valore);
	nuova = list_cut_below(nuova, valore);
	printf("Stampo la lista dopo il metodo list_cut_below...\n");
	list_print(nuova);
	printf("Duplico ogni elemento della 3^ lista...\n");
	nuova = list_dup(nuova);
	printf("Stampo la lista duplicata...\n");
	list_print(nuova);
	printf("\nProgramma scritto da Lobascio Giuseppe Pio®.\n");
	return 0;
}

