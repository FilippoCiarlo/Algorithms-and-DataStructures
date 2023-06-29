/**
 * @file lista.cc
 * @author filippo
 * @brief implementazione del modulo "lista"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "tipo.h"
#include "liste.h"

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
		cout<<head(l)<<" ";
		l = tail(l);
	}
	cout<<endl;
}

/**
 * @brief stampa la lista passata in ingresso in maniera ricorsiva
 * 
 * @param l lista
 */
void stampa_ric(lista l)
{
	if(l != NULL)
	{
        cout<<head(l)<<" ";
		stampa_ric(tail(l));
    }
}

/**
 * @brief stampa la lista passata in ingresso all'inverso ed in maniera ricorsiva
 * 
 * @param l lista
 */
void stampa_inv(lista l)
{
	if(l != NULL)
    {
		stampa_inv(tail(l));
	    cout<<head(l)<<" ";
    }
}

/**
 * @brief inserisce un nuovo elemento alla lista in ordine crescente
 * 
 * @param l lista
 * @param e elemento
 * @return lista ritorna la lista aggiornata
 */
lista ord_insert_elem(lista l, elem* e)
{
	if(l == NULL || compare(e->inf,head(l)) <= 0)
	{
		e->pun = l;
		return e;
	}

	lista tmp = l;
	while(tail(tmp) != NULL && compare(e->inf, head(tail(tmp))) > 0)
		tmp = tail(tmp);
	
	e->pun = tmp->pun;
	tmp->pun = e;
	return l;
}

/**
 * @brief sposta in una nuova lista tutti gli elementi al di sotto del valore soglia
 * 
 * @param l lista degli elementi
 * @param soglia 
 * @return lista ritorna una lista contente i valore che sono al di sotto del valore soglia
 */
lista sposta(lista& l, int soglia)
{
    lista tmp = l;
	elem* last_tmp = l;

	lista l1 = NULL;
	lista last_l1 = NULL;

	while(tmp != NULL)
    {
		if(head(tmp) < soglia)
        {
			if(l1 != NULL)
            {
				last_l1->pun = tmp;
				last_l1 = tmp;
			}
            else
				l1 = last_l1  = tmp;

			if(tmp == l)
				l = tail(tmp);
			else
				last_tmp->pun = tail(tmp);
		}
        else
			last_tmp = tmp;

		tmp = tail(tmp);
	}

	if(last_l1 != NULL)
		last_l1->pun = NULL;

	return l1;
}

/**
 * @brief dato un vettore di valori (interi), crea una lista e la ritorna
 * 
 * @param n dimensione del vettore
 * @param val vettore di valori
 * @return lista ritorna la lista creata
 */
lista create_list(int n, int val[])
{
	lista l = NULL;
	for(int i = 0; i < n; i++)
    {
		elem* e = new elem;
		e->inf = val[i];
		l = insert_elem(l,e);
	}
	return l;
}

/**
 * @brief data una lista di interi, elimina tutti i nodi in posizione pari
 * 
 * @param l lista di elementi
 */
void delete_even(lista& l)
{
	lista tmp = l;
	while(tmp != NULL)
    {
		if(tmp->pun != NULL) 
        {
        	elem* to_del = tmp->pun;
			tmp->pun = to_del->pun;
            delete to_del; 
        }
		tmp = tail(tmp); 
	}
}

/**
 * @brief somma l'elemento della lista in posizione idx a tutti gli elementi della lista
 * 
 * @param l lista di elementi
 * @param idx posizione dell'elemento da sommare all'interno della lista
 * @return lista ritorna la lista con tutti i valori aggiornati
 * 
 * richiede le seguenti implementazioni di TIPO prima dell'utilizzo:
 * copy()
 * summ()
 */
lista somma_elemento(lista l, int idx)
{
    lista tmp = l;
    tipo_inf val;
    copy(val,0);
    
    for(int i = 0; tmp != NULL && i <= idx; i++, tmp = tail(tmp))
        copy(val,tmp->inf);
    
    tmp = l;
    while(tmp != NULL)
    {
        summ(tmp->inf,val);
        tmp = tail(tmp);
    }
    
    return l;
}