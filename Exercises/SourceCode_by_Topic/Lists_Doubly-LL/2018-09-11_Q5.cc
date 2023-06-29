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

/************BOOL*MAX*FUNCTION************/
bool max(elem* e)
{
	if(e == NULL)   // Empty List
		return false;

	elem* left = e->prev;
	elem* right = e->pun;

	while(left != NULL || right != NULL)
    {
		if(left != NULL)
        {
			if(left->inf > e->inf)
				return false;
			else
				left = left->prev;
		}

		if(right != NULL)
        {
			if(right->inf > e->inf)
				return false;
			else
				right = right->pun;
		}
	}
	return true;
}

bool maxV2(elem* e)
{
	if(e == NULL)   // Empty List
		return false;

	elem* left = e->prev;
	elem* right = e->pun;
	
	while(left != NULL)
	{
		if(head(left) > head(e))
			return false;
		left = left->prev;
	}
	
	while (right != NULL)
	{
		if(head(right) > head(e))
			return false;
		right = right->pun;
	}
	
	return true;
}
/*****************************************/

void printResult(bool flag)
{
    if(flag)
		cout<<" is the max\n";
	else
		cout<<" is not the max\n";
}

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

    cout<<head(e1);
    printResult(max(e1));
	cout<<head(e1);
    printResult(maxV2(e1));

	cout<<endl;

	cout<<head(e2);
    printResult(max(e2));
	cout<<head(e2);
    printResult(maxV2(e2));

	cout<<endl;

    cout<<head(e3);
    printResult(max(e3));
	cout<<head(e3);
    printResult(maxV2(e3));

	cout<<endl;

    cout<<head(e4);
    printResult(max(e4));
	cout<<head(e4);
    printResult(maxV2(e4));

	cout<<endl;

    cout<<head(e5);
    printResult(max(e5));
	cout<<head(e5);
    printResult(maxV2(e5));

	return 0;
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

