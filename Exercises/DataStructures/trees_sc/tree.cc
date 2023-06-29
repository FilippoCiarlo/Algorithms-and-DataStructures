/**
 * @file tree.cc
 * @author filippo
 * @brief implementazione del modulo "tree"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "tree.h"

using namespace std;

/**
 * @brief crea, inizializza e restituisce un nuovo nodo
 * 
 * @param inf valore da inserire nel campo informazione del nodo
 * @return node* nodo creato
 */
node* new_node(tipo_inf inf){
	node* n = new node;
	copy(n->inf,inf);
	n->nextSibling = n->firstChild = NULL;
	return n;
}

/**
 * @brief inserisce un figlio: (t)-fC->(n0) => (t)-fC->(n1) && (n1)->(n0) 
 * 
 * @param padre 
 * @param nuovo_figlio 
 */
void insert_child(node* padre, node* nuovo_figlio){
	nuovo_figlio->nextSibling = padre->firstChild;
	padre->firstChild = nuovo_figlio;
}

/**
 * @brief inserisce un fratello: (n1)->(n3) => (n1)->(n2)->(n3)
 * 
 * @param n1 fratello già presente
 * @param n2 fratello da inserire
 */
void insert_sibling(node* n1, node* n2){
	n2->nextSibling = n1->nextSibling;
	n1->nextSibling = n2;
}

/**
 * @brief stampa l'albero passato in ingresso
 * 
 * @param t albero
 */
void serialize(tree t)
{
	cout<<"("<<get_inf(t);
	tree t1 = get_firstChild(t);
	while(t1 != NULL)
    {
		serialize(t1);
		t1 = get_nextSibling(t1);
	}
	cout<<")";
}

/**
 * @brief ritorna il campo informazione del nodo dell'albero
 * 
 * @param n nodo dell'albero
 * @return tipo_inf 
 */
tipo_inf get_inf(node* n)
{
	return n->inf;
}

/**
 * @brief ritorna il nodo del fratello del nodo passato in ingressp
 * 
 * @param n nodo
 * @return node* 
 */
node* get_nextSibling(node* n)
{
	return n->nextSibling;
}

/**
 * @brief ritorna il nodo del figlio del nodo passato in  ingresso
 * 
 * @param n nodo
 * @return node* 
 */
node* get_firstChild(node* n)
{	
	return n->firstChild;
}


/**
 * @brief controlla se esiste un cammino dalnodo n ad una foglia che contenga solo nodi con lo stesso valore di n
 * 
 * @param n node
 * @return true 
 * @return false 
 */
bool path(node* n)
{
	if(n == NULL)
		return false;

	bool ris = false;
	node* fC = get_firstChild(n);
	node* nS = get_nextSibling(n);

	if(fC == NULL && nS == NULL)
		return true;
	else if (fC != NULL && get_inf(fC) == get_inf(n))
		ris = path(fC);
	else if(nS != NULL &&  get_inf(nS) == get_inf(n))
		ris = path(nS);

	nS = get_nextSibling(n);
	while(nS != NULL && !ris)
	{
		if(get_inf(nS) == get_inf(n))
			ris = path(nS);

		nS = get_nextSibling(nS);
	}
	return ris;
}

/**
 * @brief controlla se esiste  un cammino dal nodo n ad un nodo con valore v
 * 
 * @param n nodo
 * @param v valore
 * @return true 
 * @return false 
 */
bool path(node* n, tipo_inf v)
{
	if(n == NULL)
		return false;
	else if(compare(get_inf(n),v) == 0)
    	return true;

	bool ris = false;
	node* fC = get_firstChild(n);
	node* nS = get_nextSibling(n);
	
	if(fC != NULL)
		ris = path(fC,v);
	else if(nS != NULL)
		ris = path(nS,v);
	
    nS = get_nextSibling(n);
   	while(nS != NULL && !ris)
   	{
        ris = path(nS,v);
		nS = get_nextSibling(nS);
    }
    return ris;
}