/**
 * @file bst.cc
 * @author filippo
 * @brief implementazione del modulo "bst"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include "tipo.h"
#include "bst.h"

using namespace std;

/**
 * @brief copia la variabile source in dest
 * 
 * @param dest (return) variabile di destinazione
 * @param source variabile sorgente
 * @return tipo_key 
 */
tipo_key copy_key(tipo_key& dest, tipo_key source)
{
	dest = source;
	return dest;
}

/**
 * @brief compara le due  chiavi
 * 
 * @param k1 prima chiave
 * @param k2 seconda chiave
 * @return int (k1<k2) => <0, (k1=k2) => =0, (k1>k2)  => >0
 */
int compare_key(tipo_key k1, tipo_key k2)
{
	return k1-k2;
}

/**
 * @brief ritorna la chiave del nodo passato in ingresso
 * 
 * @param n nodo
 * @return tipo_key 
 */
tipo_key get_key(bnode* n)
{
	return (n->key);
}

/**
 * @brief dato il valore della chiave crea un nuovo nodo e lo ritorna
 * 
 * @param k chiave
 * @return bnode* 
 */
bnode* bst_newNode(tipo_key k)
{
	bnode* n = new bnode;
	copy_key(n->key,k);
	n->right = n->left = n->parent = NULL;
	return n;
}

/**
 * @brief stampa il BST passato in ingresso
 * 
 * @param b Binary Search  Tree
 */
void print_bst(bst b)
{
	if(get_left(b)!=NULL)
		print_bst(get_left(b));
	
	cout<<get_key(b)<<" ";

	if(get_right(b) != NULL)
		print_bst(get_right(b));
}

/**
 * @brief ritorna il nodo sinistro del nodo passato in ingresso
 * 
 * @param n nodo
 * @return bnode* nodo sinistro
 */
bnode* get_left(bnode* n)
{
	return (n->left);
}

/**
 * @brief ritorna il nodo destro del nodo passato in ingresso
 * 
 * @param n nodo
 * @return bnode* nodo  destro
 */
bnode* get_right(bnode* n)
{
	return (n->right);
}

/**
 * @brief ritorna il nodo padre del nodo passato in ingresso
 * 
 * @param n nodo
 * @return bnode* nodo padre
 */
bnode* get_parent(bnode* n)
{
	return (n->parent);
}

/**
 * @brief cerca il nodo dichiave k all'interno dell BST
 * 
 * @param b Binary Search Treee
 * @param k chiave
 * @return bnode* 
 */
bnode* bst_search(bst b, tipo_key k)
{
	while(b != NULL)
	{
		if(compare_key(k,get_key(b)) == 0)
			return b;
		else if(compare_key(k,get_key(b)) < 0)
			b =  get_left(b);
		else
			b = get_right(b);
	}
	return NULL;
}

/**
 * @brief cerca il nodo dichiave k all'interno dell BST, in maniera ricorsiva
 * 
 * @param b Binary Search Tree
 * @param k chiave
 * @return bnode* 
 */
bnode* bst_search_ric(bst b, tipo_key k)
{
    if(b == NULL)
        return NULL;
    else
        if(b->key == k)
            return b;
        else if(b->key < k)
            return bst_search(b->left,k);
        else
            return bst_search(b->right,k);
}

/**
 * @brief sostituisce la chiave l con la chiave a all'interno del BST
 * 
 * @param b Binary Search Tree
 * @param l chiave da cercare e sostituire
 * @param a chiave sostituta
 */
void aggiorna_chiave(bst& b, tipo_key l, tipo_key a)
{
	if(b == NULL)
		return;

	int cmp = compare_key(l,b->key);

	if(cmp == 0)
		copy_key(b->key,a);
	else if(cmp < 0)
		aggiorna_chiave(b->left,l,a);
	else	
		aggiorna_chiave(b->right,l,a);
}

/**
 * @brief inserisce il nodo passato in ingresso al BST b
 * 
 * @param b Binary Search Tree
 * @param n nodos
 */
void bst_insert(bst& b, bnode* n)
{
	if(n == NULL)	// empty node
    	return;

	if(b == NULL)	
		b = n;
	else
    {	
		bst tmp = b;
		bst n_parent = NULL;
		
		while(tmp != NULL)
        {		
			n_parent = tmp;
			if(get_key(n) > get_key(tmp))		
				tmp = get_left(tmp);
			else		
				tmp = get_right(tmp);
		}

		n->parent = n_parent;
		if(get_key(n) > get_key(n_parent))			
			n_parent->left = n;
		else		
			n_parent->right = n;
	}
}

/**
 * @brief controlle se i due BST sono uguali
 * 
 * @param b1 Binary Search Tree 1
 * @param b2 Binary Search Tree 2
 * @return true sono uguali
 * @return false sono diversi
 */
bool same(bst b1, bst b2)
{
	if(b1 == NULL || b2 == NULL)
	{
		if(b1 == NULL && b2 == NULL)
			return true;
		else
			return false;
	}
  	else 
	{
		bool left = same(b1->left,b2->left); 
		bool right = same(b1->right, b2->right); 
		return (compare_key(b1->key,b2->key) == 0) && (left && right);
	}
}

/**
 * @brief cerca il nodo con chiave x e ne stampa il sottoalbero
 * 
 * @param b Binary  Search Tree
 * @param x chiave
 */
void print_subtree(bst b, tipo_key x){
	if(b == NULL) // Empty BST
		return;

	while(b != NULL)
    {
		if(get_key(b) == x)
        {		
			print_bst(b);
			return;
		}
        else if(get_key(b) < x)		
			b = get_right(b);
		else					
			b = get_left(b);
	}
	
	cout<<"Subtree Not Found\n";
}

/**
 * @brief 
 * 
 * @param b 
 * @param val 
 */
void print_bstV2_companion(bst b, int val)
{
	if(get_left(b) != NULL)
		print_bstV2_companion(get_left(b),val);
	
    if(compare_key(get_key(b),val) < 0)
	    cout<<get_key(b)<<" ";

	if(get_right(b) != NULL)
		print_bstV2_companion(get_right(b),val);
}

/**
 * @brief 
 * 
 * @param b 
 * @param x 
 * @param y 
 */
void print_subtreeV2(bst b, int x, int y)
{
    bnode* n = bst_search(b,x);
    if(n != NULL)
        print_bstV2_companion(n,y);
}