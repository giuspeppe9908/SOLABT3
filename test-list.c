#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int value;
	struct node * next;   /* pointer to the same structure */
} node;
typedef node* list;
/*
 * Assume that the list is in increasing order and insert the element
 * preserving the increasing order
 */
list list_insert_ordered(list p, int val);
/*Concatenate two lists*/
list list_cat(list before, list after);
/*Insert elements at the head of the list*/
list list_insert_head(list p, int val);
/*Insert elements at the tail of the list*/
list list_insert_tail(list p, int val);
/*Print the list content*/
void list_print(list p);
/*Free the list*/
void list_free(list p);
int main()
{   
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
    nuova = list_insert_head(nuova, 100);
    nuova = list_insert_head(nuova, 90);
    nuova = list_insert_head(nuova, 70);
    nuova = list_insert_head(nuova, 60);
    nuova = list_insert_tail(nuova, 188);
    printf("Stampo di una nuova lista dopo metodo insert_tail : \n");
    list_print(nuova);
    printf("\nProgramma scritto da Lobascio Giuseppe Pio®.");
	return 0;
}
list list_insert_head(list p, int val)
{
	list new_el;
	/* Allocate the new node */
	new_el = malloc(sizeof(*new_el));
	/* Setting the data */
	new_el->value = val;
	/* head insertion: old head becomes .next field of new head */
	new_el->next = p;
	/* new head is the pointer to the new node */
	return new_el;
}
void list_print(list p)
{
	/* Looping all nodes until p == NULL */
	if (p == NULL) {
		printf("Empty list\n");
		return;
	}
	printf("[%i]", p->value);
	for(; p->next!=NULL; p = p->next) {
		printf(" -> [%i]", p->next->value);
	}
	printf("\n");
}
void list_free(list p)
{
	/* If p ==  NULL, nothing to deallocate */
	if (p == NULL) {
		return;
	}
	/* First deallocate (recursively) the next nodes... */
	list_free(p->next);
	/* ... then deallocate the node itself */
	free(p);
}
list list_insert_ordered(list p, int val){
     list new_Node = malloc(sizeof(*new_Node));
      if(new_Node != NULL){
	   new_Node->value = val;
	   new_Node->next = NULL;
	 
		/*Creo altri 2 nodi*/
		 list prec = NULL;
		 list curr = p;
		 
		   //ripeto entrando nel ciclo per trovare la posizione corretta del valore
		   while(curr != NULL && val > curr->value){
			prec = curr; //vado avanti...
		    curr = curr->next;//punto al successivo
		   }
		   //inserisco nuovo nodo all'inizio della lista
		   if(prec == NULL){
			new_Node->next = p;
			p = new_Node;
		   }
		   else{ //inserisco il nuovo nodo tra prec e curr.
			  prec->next  = new_Node;
			  new_Node->next = curr;
		   }
	 }
	 else printf("Memoria non disponibile.\n");
	 return p;//altrimenti p;
}

list list_cat(list before, list after){
	    /*Entrambe le liste diverse da NULL*/
	if(before != NULL && after != NULL) 
	{
		list tmp = before;
		int finito = 0;
	/*Scorro la prima lista e quando finisce faccio puntare il campo next alla lista after*/
		for(; finito == 0 ; tmp = tmp->next)
		{
			if(tmp->next == NULL)
			{
			 tmp->next = after;
			 finito = 1;
			}
		}
		return before;
		/*Se la lista before è null ritorno direttamente la lista after*/
	} else if(before == NULL && after != NULL) {
		return after;
		/*Se la lista before è diversa da NULL e la lista after è diversa da NULL ritorno la lista before*/
	} else if(before != NULL && after == NULL) {
		return before;
	} else {
		return NULL;
	}
}
list list_insert_tail(list p, int val){
        /*Creation of the new Node to add*/
	list new_el;
	new_el = malloc(sizeof(new_el));
	new_el->value = val;
	/* If the list is empty I add the element directly */
	if(p == NULL)
	{
		p = new_el;
		return p;
	}
	/*tmp is used to go through the list */
	list tmp = p;
	/*The boolean condition that I use to exit the loop */
	int finito = 0;
	for(; finito == 0; tmp = tmp->next)
	{
		if(tmp->next == NULL)
		{
			tmp->next = new_el;
			finito = 1;
		}
	}
	/*Return the modified list */
	return p;
}
