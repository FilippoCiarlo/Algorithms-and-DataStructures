#include <iostream>

using namespace std;

struct elem
{ 
	int inf; 
	elem* pun ; 
	elem* prev; 
}; 

typedef elem* lista;

/************UTILITY*FUNCTIONS************/
int head(elem* e);
elem* tail(elem* e);

lista insert_elem(lista l, elem* e);
void print_list(lista l);
/*****************************************/

/***************MAX*FUNCTION**************/
int max(elem* e)
{
	if(e == NULL)   // Empty List
		return -1;

	int cont = 0;
	elem* left = e->prev;
	elem* right = e->pun;

	while(left != NULL || right != NULL)
    {
		if(left != NULL)
        {
			if(left->inf > e->inf)
				cont++;
			left = left->prev;
		}
   		
		if(right != NULL)
        {
     		if(right->inf > e->inf)
				cont++;	
			right = right->pun;		
		}
	} 
   	return cont;
}
/*****************************************/

int main()
{
    elem* e1 = new elem;
    elem* e2 = new elem;
    elem* e3 = new elem;
    elem* e4 = new elem;
    elem* e5 = new elem;

    e1->inf = 1;
    e2->inf = 3;
    e3->inf = 2;
    e4->inf = 5;
    e5->inf = 6;

    lista l = NULL;
    l = insert_elem(l,e5);
    l = insert_elem(l,e4);
    l = insert_elem(l,e3);
    l = insert_elem(l,e2);
    l = insert_elem(l,e1);

	print_list(l);
    cout<<(e1->inf)<<">: "<<max(e1)<<endl;
    cout<<(e2->inf)<<">: "<<max(e2)<<endl;
    cout<<(e3->inf)<<">: "<<max(e3)<<endl;
    cout<<(e4->inf)<<">: "<<max(e4)<<endl;
    cout<<(e5->inf)<<">: "<<max(e5)<<endl;

	return  0;
}

/************UTILITY*FUNCTIONS************/
int head(lista l)
{
    return l->inf;
}

lista tail(lista l)
{
    return l->pun;
}

lista insert_elem(lista l, elem* e)
{
	if(l != NULL)
		l->prev = e;
	e->pun = l;	
	e->prev = NULL;
	return e;
}

void print_list(lista l)
{
	while(l != NULL)
    {
		cout<<l->inf<<" ";
        l = tail(l);
	}
	cout<<endl;
}
/*****************************************/