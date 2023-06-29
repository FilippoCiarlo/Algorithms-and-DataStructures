/*
 * ! Attention
 * Compile the program with the option: -Wno-write-strings
 * g++ -Wno-write-strings 2019-06-21_Q6.cc 
 */
#include <iostream>
#include <cstring>

using namespace std;

typedef char* tipo_inf;

struct elem
{
	tipo_inf inf;
	elem* pun ;
};

typedef elem* lista;

typedef struct
{
    lista head; 
    elem* tail;
} coda;

/************UTILITY*FUNCTIONS************/
int compare(char* s1, char* s2);
void copy(char*& dest, char* source);
void print(char* s);

coda enqueue(coda c, tipo_inf inf);
/*****************************************/

/*************DEQUEUE*FUNCTION************/
tipo_inf dequeue(coda& c)
{
	lista tmp = c.head;
	tipo_inf val;

	copy(val, c.head->inf);
	c.head = c.head->pun;

	delete tmp;
	return val;
}
/*****************************************/

int main()
{
	coda c;
	c.head = c.tail = NULL;

	c = enqueue(c,"Filippo"); 
	c = enqueue(c,"Ciarlo"); 
	c = enqueue(c,"Faicchio"); 
	c = enqueue(c,"Benevento"); 
	
	while(c.head != NULL){
		tipo_inf s = dequeue(c);
		print(s);
	}
}

/************************************/
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
/************************************/



