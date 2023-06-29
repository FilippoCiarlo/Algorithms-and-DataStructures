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

/************FIND*PEAK*FUNCTION***********/
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
/*****************************************/

int main()
{
    elem* e1 = new elem;
    elem* e2 = new elem;
    elem* e3 = new elem;
    elem* e4 = new elem;
    elem* e5 = new elem;
    elem* e6 = new elem;
    elem* e7 = new elem;
    elem* e8 = new elem;
    elem* e9 = new elem;
    elem* e10 = new elem;

    e1->inf = 4;
    e2->inf = 3;
    e3->inf = 3;
    e4->inf = 3;
    e5->inf = 0;
    e6->inf = -1;
    e7->inf = 3;
    e8->inf = -3;
    e9->inf = 4;
    e10->inf = 2;

    lista l = NULL;
    l = insert_elem(l,e10);
    l = insert_elem(l,e9);
    l = insert_elem(l,e8);
    l = insert_elem(l,e7);
    l = insert_elem(l,e6);
    l = insert_elem(l,e5);
    l = insert_elem(l,e4);
    l = insert_elem(l,e3);
    l = insert_elem(l,e2);
    l = insert_elem(l,e1);

	print_list(l);
    cout<<"peaks: "<<picchi(l)<<endl;

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