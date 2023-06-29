/**
 * @file lista.cc
 * @author filippo
 * @brief implementazione del modulo "lista.h"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "tipo.h"
#include "lista.h"

using namespace std;

/**
 * @brief ritorna il campo informazione dell'elemento passato in ingresso
 * 
 * @param e elemento
 * @return tipo_inf 
 */
tipo_inf head(elem* e)
{
    return e->inf;
}

/**
 * @brief ritorna l'elemento successivo all'elemento passato in ingresso
 * 
 * @param e elemento
 * @return elem* 
 */
elem* tail(elem* e)
{
    return e->pun;
}

/**
 * @brief inserisce un nuovo elemento alla lista
 * 
 * @param l lista
 * @param e elemento
 * @return lista ritorna la lista aggiornata
 */
lista insert_elem(lista l, elem* e)
{
    e->pun = l;
	return e;
}

/**
 * @brief stampa la lista passata in ingresso
 * 
 * @param l lista
 */
void print_list(lista l)
{
    while(l != NULL)
    {
		head(l);
        cout<<" ";
		l = tail(l);
	}
	cout<<endl;
}

/**
 * @brief ritorna il numero di picchi presenti in una lista di interi
 * 
 * @param l lista di interi
 * @return int 
 */
int picchi(lista l)
{
    if(l == NULL)
        return 0;
    else if(l->prev == NULL && l->inf > l->pun->inf)    // picco all'estremo sisnistro  
        return 1 + picchi(l->pun);
    else if(l->pun == NULL && l->inf > l->prev->inf)    // picco all'estremo destro
        return 1;
    else if(l->prev->inf < l->inf && l->inf > l->pun->inf)  // picco all'interno della lista
        return 1 + picchi(l->pun);
    else
        return picchi(l->pun);
}

/**
 * @brief controlla se l'elemento passato in ingresso è il valore più alto all'interno della lista
 * 
 * @param e elemento
 * @return true 
 * @return false 
 */
bool max(elem* e)
{
	if(e == NULL)   // Empty List
		return false;

	elem* left = e->prev;
	elem* right = e->pun;
	
	while(left != NULL || right != NULL)
    {
		if(left != NULL)
        {
			if(left->inf > e->inf)
				return false;
			else
				left = left->prev;
		}

		if(right != NULL)
        {
			if(right->inf > e->inf)
				return false;
			else
				right = right->pun;
		}
	}
	return true;
}

/**
 * @brief controlla se la lista passata in ingresso è palindroma (Es. ABCCBA)
 * 
 * @param l lista 
 * @return true 
 * @return false 
 */
bool palindroma(lista l)
{
	if(l == NULL)   // Empty List
		return false;
	
	lista tmp = l;
	while(tmp->pun != NULL)
		tmp = tmp->pun;

	while(l != NULL)
	{
		if(tmp->inf != l->inf) // Non Palindroma
			return false;

		tmp = tmp->prev;
		l = l->pun;
	}
	return true;    // Palindroma
}