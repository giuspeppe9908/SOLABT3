#ifndef _LISTMODULE_H_
#define _LISTMODULE_H_

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
/*Delete head*/
list list_delete_if(list head, int to_delete);
/*Delet in odd positions.*/
list list_delete_odd ( list head ) ;
/*Metodo per la lunghezza di una lista di interi.*/
int Length(list head);
/*metodo list_cut_below*/
list list_cut_below ( list head , int cut_value ) ;
/*metodo list_dup*/
list list_dup(list head);
#endif
