#include <iostream>
#include <cstring>

using namespace std;

struct persona
{      
	char* nome;      
	int id; 
};

struct elem
{
	persona inf;
	elem* pun;
};

typedef elem* lista;

/************UTILITY*FUNCTIONS************/
persona head(elem* e);
elem* tail(elem* e);

int compare(persona p1, persona p2);
lista ord_insert_elem(lista l, elem* e);

void print_list(lista l);
/*****************************************/

/*********LISTS*DIFFERENCE*FUNCTION********/
void diff(lista l1, lista l2)
{
	if(l2 == NULL)
	{
		while(l1 != NULL)
		{
			cout<<l1->inf.id<<" "<<l1->inf.nome<<endl;
			l1 = tail(l1);
		}
		return;
	}
	if(l1 != NULL && compare(l1->inf, l2->inf) == 0)
	{
		diff(tail(l1),tail(l2));
		return;
	}
	if(l1 != NULL && compare(l1->inf, l2->inf) < 0)
	{
		cout<<l1->inf.id<<" "<<l1->inf.nome<<endl;
		diff(tail(l1),l2);
		return;
	}
	diff(l1,tail(l2));
}
/*****************************************/

int main()
{
	/*		1st LIST	*/
	persona p1 = {"Filippo",1};
	persona p2 = {"Antonio",2};
	persona p3 = {"Antonio",2};	
	persona p4 = {"Luca",3};
	persona p5 = {"Luca",4};

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

	lista l1 = NULL;
	l1 = ord_insert_elem(l1,e1);
	l1 = ord_insert_elem(l1,e2);
	l1 = ord_insert_elem(l1,e3);
	l1 = ord_insert_elem(l1,e4);
	l1 = ord_insert_elem(l1,e5);

	/*		2nd LIST	*/
	persona p6 = {"Filippo",1};
	persona p7 = {"Antonio",2};
	persona p8 = {"Luca",3};
	persona p9 = {"Ugo",9};
	persona p10 = {"Simone",10};

	elem* e6 = new elem;
	elem* e7 = new elem;
	elem* e8 = new elem;
	elem* e9 = new elem;
	elem* e10 = new elem;

	e6->inf = p6;
	e7->inf = p7;
	e8->inf = p8;
	e9->inf = p9;
	e10->inf = p10;

	lista l2 = NULL;
	l2 = ord_insert_elem(l2,e6);
	l2 = ord_insert_elem(l2,e7);
	l2 = ord_insert_elem(l2,e8);
	l2 = ord_insert_elem(l2,e9);
	l2 = ord_insert_elem(l2,e10);

	cout<<"LIST ONE:\n";
	print_list(l1);

	cout<<"\nLIST TWO:\n";
	print_list(l2);

	cout<<"\n1st LIST -MINUS- 2nd LIST :\n";
	diff(l1,l2);

	cout<<"\n1st LIST -MINUS- NULL LIST:\n";
	diff(l1,NULL);

	cout<<"\nNULL LIST -MINUS- 2nd LIST:\n";
	diff(NULL,l2);
	return 0;
}

/************UTILITY*FUNCTIONS************/
persona head(elem* e)
{
	return e->inf;
}

elem* tail(elem* e)
{
	return e->pun;
}

int compare(persona p1, persona p2)
{
	if(strcmp(p1.nome,p2.nome) == 0 && p1.id == p2.id)
		return (p1.id - p2.id); 
	else if(strcmp(p1.nome,p2.nome) <= 0 && p1.id < p2.id)	
		return (p1.id - p2.id); 
	else			
		return (p1.id - p2.id)+1;
}

lista ord_insert_elem(lista l, elem* e)
{
	if(l == NULL || compare(e->inf,head(l)) < 0)
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

void  print_list(lista l){
	while(l != NULL){
		cout<<l->inf.id<<" "<<l->inf.nome<<endl;
		l = tail(l);
	}
}
/*****************************************/
