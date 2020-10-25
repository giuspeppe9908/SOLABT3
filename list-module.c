#include <stdio.h>
#include <stdlib.h>
#include "list-module.h"//inclusione libreria list-module.h

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
	/* If the list is empty add the element directly */
	if(p == NULL)
	{
		p = new_el;
		return p;
	}
	/*tmp is used to go through the list */
	list tmp = p;
	/*The boolean condition to exit the loop */
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
list list_delete_if(list head, int to_delete){
     /*la quale cancella e dealloca il primo nodo della lista il cui valore del campo value `e uguale al parametro to delete. 
     La funzione restituisce la lista cos`ı modificata.*/
     /* See if we are at end of list. */
       if (head == NULL)
          return NULL;
       if(head->value == to_delete){
          list new;
          /* Save the next pointer in the node. */
          new = head->next;
          /* Deallocate the node. */
          free(head);
          return new;
       }
       /*Check the rest of the list, fixing the next pointer in case the next node is the one removed.*/
       head->next = list_delete_if(head->next, to_delete);
       /*return main list*/
     return head;
}
int Length(list head) 
{ 
    int count = 0;  // Initialize count 
    list current = head;  // Initialize current 
    while (current != NULL) 
    { 
        count++; 
        current = current->next; 
    } 
    return count; 
} 
list list_delete_odd(list head){
     if(head != NULL){
         //creo un nuovo nodo
         list temp = head;
         //punto al successivo di head.
         head = head->next;
         //free temp;
         free(temp);
         if(head !=NULL){
            list evenNode = head;//nodo pari
            list oddNode = head->next;
            while(evenNode!=NULL && oddNode!=NULL){
                evenNode->next = oddNode->next;
                free(oddNode);
                evenNode = evenNode->next;
                if(evenNode != NULL)
                oddNode = evenNode->next;
            }
         }
     }
     return head;
}
list list_cut_below(list head, int cut_value){
     /*Rimuova dalla lista OGNI elemento che abbia valore inferiore al valore cut_value passato come parametro.*/
     if(head == NULL)
        return NULL;
        
        list temp = head;
        list prec;
        //se il valore più piccolo di cut_value è in testa lo cancello
        while(temp!=NULL && temp->value < cut_value){
            head = temp->next;
            free(temp);
            temp = head;
        }
        while(temp != NULL){
            while (temp != NULL && temp->value >= cut_value) { 
                 prec = temp; 
                 temp = temp->next; 
            } 
            if(temp == NULL) return head;
            prec->next = temp->next;
            free(temp);
            temp = prec->next;
        }
     return head;
}
list list_dup(list head){
   /*Ritorna una copia dalla lista (copia di ogni elemento).*/
   list node, curr;
   for(curr = head; curr != NULL; curr = curr->next){
       node = malloc(sizeof(*node));
       if(node == NULL){
         printf("Impossibile copiare!");
         return NULL;
       }
       else{
             node->value = curr->value;
             node->next = curr->next;
             curr->next = node;
             curr = node;
       }
   }
   
   return head;
}
