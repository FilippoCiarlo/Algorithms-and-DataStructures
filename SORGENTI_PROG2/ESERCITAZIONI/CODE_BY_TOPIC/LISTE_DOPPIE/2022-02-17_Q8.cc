#include <iostream>

using namespace std;

struct elem
{
	int inf;
	elem* prev;
	elem* pun;
};

typedef elem* lista;

/************UTILITY*FUNCTIONS************/
int head(elem* e);
elem* tail(elem* e);

lista insert_elem(lista l, elem* e);
void print_list(lista l);
/*****************************************/

/*********PALINDROME*TEST*FUNCTION********/
bool palindroma(lista l)
{
	if(l == NULL)   // Empty List
		return false;
	
	lista tmp = l;
	while(tmp->pun != NULL)
		tmp = tmp->pun;

	//while(tmp != NULL && l != NULL)
	while(l != NULL)
	{
		if(tmp->inf != l->inf) // Non Palindroma
			return false;

		tmp = tmp->prev;
		l = l->pun;
	}
	return true;    // Palindroma
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
    e2->inf = 4;
    e3->inf = 2;
    e4->inf = 4;
    e5->inf = 1;

    lista l = NULL;
    l = insert_elem(l,e5);
    l = insert_elem(l,e4);
    l = insert_elem(l,e3);
    l = insert_elem(l,e2);
    l = insert_elem(l,e1);

	print_list(l);
	if(palindroma(l))
        cout<<"Palindroma\n";
    else
        cout<<"Non Palindroma\n";

    e4->inf = 3;
	print_list(l);
	if(palindroma(l))
        cout<<"Palindroma\n";
    else
        cout<<"Non Palindroma\n";

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
	//cout<<endl;
}
/*****************************************/
