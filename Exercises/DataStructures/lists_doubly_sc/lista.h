/* PRIMA DELL'UTILIZZO RIDEFINIRE IL TIPO */
/* INCLUDERE L'HEADER DEL NUOVO TIPO */
typedef int tipo_inf;

/**
 * @file lista.h
 * @author filippo
 * @brief header file "lista"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/************LISTA***********/
struct elem
{ 
	int inf; 
	elem* pun ; 
	elem* prev; 
}; 

typedef elem* lista;
/****************************/

tipo_inf head(elem* e);
elem* tail(elem* e);

lista insert_elem(lista l, elem* e);
void print_list(lista l);

int picchi(lista l);
bool max(elem* e);
bool palindroma(lista l);