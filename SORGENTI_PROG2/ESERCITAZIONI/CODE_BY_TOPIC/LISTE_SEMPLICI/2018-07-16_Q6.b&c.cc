/*
 * ! Attention
 * Compile the program with the option: -Wno-write-strings
 * g++ -Wno-write-strings 2018-07-16_Q6.b\&c.cc   
 */
#include <iostream>
#include <cstring>

using namespace std;

struct persona
{      
	char* nome;      
	int id; 
};

/************LIST************/
struct elem
{
    persona inf;
    elem* pun;
};

typedef elem* lista;
/****************************/

/************UTILITY*FUNCTIONS************/
persona head(elem* e);
elem* tail(elem* e);

lista insert_elem(lista l, elem* e);
void print_list(lista l);
int compare(persona p1, persona p2);
/*****************************************/

/********ORDERED*INSERTION*FUNCTION*******/
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
/*****************************************/

int main()
{
	persona p1 = {"F",1};
	persona p2 = {"A",1};
	persona p3 = {"G",2};
	persona p4 = {"F",1};
	persona p5 = {"F",3};

	elem* e1 = new elem;
	elem* e2 = new elem;
	elem* e3 = new elem;
	elem* e4 = new elem;
	elem* e5 = new elem;

	e1->inf = p1;
	e2->inf = p2;
	e3->inf = p3;
	e4->inf = p4;
	e5->inf = p5;

	lista l = NULL;
	l = ord_insert_elem(l,e1);
	l = ord_insert_elem(l,e2);
	l = ord_insert_elem(l,e3);
	l = ord_insert_elem(l,e4);
	l = ord_insert_elem(l,e5);
		
	print_list(l);

	return 0;
}

/************UTILITY*FUNCTIONS************/
persona head(lista l)
{
    return l->inf;
}

lista tail(lista l)
{
    return l->pun;
}

lista insert_elem(lista l, elem* e){
	e->pun = l;
	return e;
}

void print_list(lista l)
{
	while(l != NULL)
    {
		cout<<l->inf.id<<" "<<l->inf.nome<<endl;
		l = tail(l);
	}
	cout<<endl;
}

int compare(persona p1, persona p2)
{
	if(strcmp(p1.nome,p2.nome) == 0 && p1.id == p2.id)
		return p1.id-p2.id; 
    else if(strcmp(p1.nome,p2.nome) <= 0 && p1.id < p2.id)
		return (p1.id - p2.id); 
    else		
		return (p1.id - p2.id)+1;
}
/*****************************************/