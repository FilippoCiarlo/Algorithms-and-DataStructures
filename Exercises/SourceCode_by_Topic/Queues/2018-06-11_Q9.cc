/*
 * ! Attention
 * Compile the program with the option: -Wno-write-strings
 * g++ -Wno-write-strings 2018-06-11_Q9.cc 
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

tipo_inf dequeue(coda& c);
/*****************************************/

/*************ENQUEUE*FUNCTION************/
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
/*****************************************/

int main()
{
	coda c;
	c.head = c.tail = NULL;

	c = enqueue(c,"Filippo"); 
	c = enqueue(c,"Ciarlo"); 
	c = enqueue(c,"Faicchio"); 
	c = enqueue(c,"Benevento"); 
	
	tipo_inf val = NULL;
	cout<<"1st Print: ";
	while(c.head != NULL)
    {
		val = dequeue(c);
		print(val);
	}

	val = NULL;
	cout<<"\n2nd Print: ";	// to check if the queue is really empty
	while(c.head != NULL)
    {
		val = dequeue(c);
		print(val);
	}
}

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