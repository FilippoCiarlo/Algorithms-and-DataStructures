#include <iostream>

using namespace std;

struct elem
{
	int inf;
	elem* pun;
};

typedef elem* lista;

/************UTILITY*FUNCTIONS************/
int head(elem* e);
elem* tail(elem* e);

lista insert_elem(lista l, elem* e);
void print_list(lista l);
/*****************************************/

/**********INVERSE*PRINT*FUNCTION*********/
void stampa_inv(lista l)
{
	if(l != NULL)
    {
		stampa_inv(tail(l));
	    cout<<head(l)<<" ";
    }
}
/*****************************************/

int main()
{
    elem* e1 = new elem;
    elem* e2 = new elem;
    elem* e3 = new elem;
    elem* e4 = new elem;
    elem* e5 = new elem;

    e1->inf = 4;
    e2->inf = 3;
    e3->inf = 2;
    e4->inf = 1;
    e5->inf = 0;

    lista l = NULL;
    l = insert_elem(l,e5);
    l = insert_elem(l,e4);
    l = insert_elem(l,e3);
    l = insert_elem(l,e2);
    l = insert_elem(l,e1);

    cout<<"Normal order: ";
    print_list(l);

    cout<<"Inverse order: ";
    stampa_inv(l);

    /* NULL TEST */
    l = NULL;
    stampa_inv(l); 

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

lista insert_elem(lista l, elem* e){
	e->pun = l;
	return e;
}

void print_list(lista l)
{
	while(l != NULL)
    {
		cout<<head(l)<<" ";
		l = tail(l);
	}
	cout<<endl;
}
/*****************************************/