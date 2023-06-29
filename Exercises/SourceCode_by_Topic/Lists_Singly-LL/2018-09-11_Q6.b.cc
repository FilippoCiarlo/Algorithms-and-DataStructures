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

/*************SELECT*FUNCTION*************/
lista sposta(lista& l, int soglia)
{
	lista tmp = l;
	elem* last_tmp = l;

	lista l1 = NULL;
	lista last_l1 = NULL;

	while(tmp != NULL)
    {
		if(head(tmp) < soglia)
        {
			if(l1 != NULL)
            {
				last_l1->pun = tmp;
				last_l1 = tmp;
			}
            else
				l1 = last_l1  = tmp;

			if(tmp == l)
				l = tail(tmp);
			else
				last_tmp->pun = tail(tmp);
		}
        else
			last_tmp = tmp;

		tmp = tail(tmp);
	}

	if(last_l1 != NULL)
		last_l1->pun = NULL;

	return l1;
}
/*****************************************/

/*************SELECT*FUNCTION*************/
lista sposta2(lista& l, int soglia)
{
	lista tmp = l;
	elem* last_tmp = l;

	lista l1 = NULL;
	lista last_l1 = NULL;

	while(tmp != NULL)
    {
		if(head(tmp) < soglia)
        {
			if(l1 != NULL)
            {
				last_l1->pun = tmp;
				last_l1 = tmp;
			}
            else
				l1 = last_l1  = tmp;

			if(tmp == l)
				l = last_tmp = tail(tmp);
			else{
				last_tmp->pun = tail(tmp);
				last_tmp = tail(tmp);
			}
		}
        else
			last_tmp = tmp;

		tmp = tail(tmp);
	}

	if(last_l1 != NULL)
		last_l1->pun = NULL;

	return l1;
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
    lista l2 = sposta(l,3);
    print_list(l);
    print_list(l2);

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