#include <iostream>

using namespace std;

struct elem
{
	int v;
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
lista select(lista& l, int v)
{
	lista tmp = l;
	elem* last_tmp = l;
	
	lista l1 = NULL;
	elem* last_l1 = NULL;
	
	while(tmp != NULL)
    {	
		if(head(tmp) <= v)
        {
			if(l1 != NULL)
            { 				            // if l1-list it's empty
				last_l1->pun = tmp;		// last l1-node points to tmp
				last_l1 = tmp;			// updates  last l1-node	
			}
            else			
				l1 = last_l1 = tmp;		// intializes head & last l1_node			
		
			if(tmp == l)				// if tmp is the head of l-list	
				l = tail(tmp);		 	// updates these variables	
			else	
				last_tmp->pun = tail(tmp);	// disconnects tmp		
		}
        else
			last_tmp = tmp;				// updates last tmp-node
	
		tmp = tail(tmp);	
	}
	
	if(l1 != NULL)
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

    e1->v = 1;
    e2->v = 3;
    e3->v = 2;
    e4->v = 5;
    e5->v = 6;

    lista l = NULL;
    l = insert_elem(l,e5);
    l = insert_elem(l,e4);
    l = insert_elem(l,e3);
    l = insert_elem(l,e2);
    l = insert_elem(l,e1);

    print_list(l);

    lista l2 = select(l,3);
    print_list(l);
    print_list(l2);

	return  0;
}	

/************UTILITY*FUNCTIONS************/
int head(lista l)
{
    return l->v;
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


