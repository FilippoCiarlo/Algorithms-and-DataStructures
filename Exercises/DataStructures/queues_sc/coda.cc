/* PRIMA DELL'UTILIZZO RIDEFINIRE IL TIPO */
/* INCLUDERE L'HEADER DEL NUOVO TIPO */

/**
 * @file coda.cc
 * @author filippo
 * @brief implementazione del modulo "coda"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstring>
#include "coda.h"

using namespace std;

/************UTILITY*FUNCTIONS************/
int compare(tipo_inf s1, tipo_inf s2)
{
	return strcmp(s1, s2);
}

void copy(tipo_inf& dest, tipo_inf source)
{
	dest = new char[strlen(source)];
	strcpy(dest, source);
}

void print(tipo_inf inf)
{
	cout<<inf<<" ";
}
/*****************************************/

/**
 * @brief restituisce la coda aggiornata con l'elemento passato in ingresso
 * 
 * @param c coda
 * @param inf elemento della cosa
 * @return coda coda aggiornata
 */
coda enqueue(coda c, tipo_inf inf)
{
	elem* p = new elem;
	copy(p->inf,inf); 
	p->pun = NULL; 
	
	if(c.tail != NULL) 
		c.tail->pun = p;
	
	c.tail = p;
 	
	if(c.head == NULL)
		c.head = c.tail; 
	return c;
}

/**
 * @brief ritorna ed elimina un elemento dalla coda
 * 
 * @param c coda
 * @return tipo_inf elemento della coda
 */
tipo_inf dequeue(coda& c)
{
	lista tmp = c.head;
	tipo_inf val;

	copy(val, c.head->inf);
	c.head = c.head->pun;

	delete tmp;
	return val;
}

/**
 * @brief controlla se la coda passata  in ingresso è vuota
 * 
 * @param c coda
 * @return true è vuota
 * @return false non è vuota
 */
bool isEmpty(coda c)
{
	if(c.head == NULL)
		return true;
	return false;
}

/**
 * @brief stampa la coda passata in gresso
 * 
 * @param c coda
 */
void printQueue(coda c)
{
    tipo_inf val = NULL;
	while(c.head != NULL)
    {
        copy(val,c.head->inf);
		print(val);
        c.head = c.head->pun;
	}
    cout<<endl;
}

/**
 * @brief unisc due code in una nuova coda e la ritorna
 * 
 * @param c1 prima coda
 * @param c2 seconda coda
 * @return coda riorna c1 UNION c2
 */
coda merge(coda c1, coda c2)
{
	coda c3;
	c3.head = c3.tail = NULL; 
	
	if(isEmpty(c1) || isEmpty(c2))
		return c3;

	tipo_inf curr_c1 = dequeue(c1); 
	tipo_inf curr_c2 = dequeue(c2); 
	
	bool stop_c1 = false; 
	bool stop_c2 = false; 	

	while(!stop_c1 && !stop_c2)
    { 
		if(strcmp(curr_c1,curr_c2) < 0)
        { 
			c3 = enqueue(c3,curr_c1); 
			if(!isEmpty(c1)) 
 				curr_c1 = dequeue(c1); 
			else
				stop_c1 = true; 
	    }
        else
        { 
			c3 = enqueue(c3,curr_c2); 
			if(!isEmpty(c2)) 
				curr_c2 = dequeue(c2); 
			else 
				stop_c2 = true; 
		}
	}
	
	if(!stop_c1)
    { 
		c3 = enqueue(c3,curr_c1); 
		while(!isEmpty(c1)) 
			c3 = enqueue(c3,dequeue(c1)); 
	}

	if(!stop_c2)
    { 
		c3 = enqueue(c3,curr_c2); 
		while(!isEmpty(c2)) 
			c3 = enqueue(c3,dequeue(c2)); 
	}

	return c3;
}
