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

/************SECONDARY*FUNCTION************/
lista create_list(int n, int val[])
{
	lista l = NULL;
	for(int i = 0; i < n; i++)
    {
		elem* e = new elem;
		e->v = val[i];
		l = insert_elem(l,e);
	}
	return l;
}
/*****************************************/

/***********DELETE*EVEN*FUNCTION**********/
void delete_even(lista& l)
{
	lista tmp = l;
	while(tmp != NULL)
    {
		elem* to_del = tmp->pun;

		if(tmp->pun != NULL) 
			tmp->pun = tmp->pun->pun;
		
		delete to_del; 
		tmp = tmp->pun; 
	}
}

void delete_evenV2(lista& l)
{
	lista tmp = l;
	while(tmp != NULL)
    {
		if(tmp->pun != NULL) 
        {
        	elem* to_del = tmp->pun;
			tmp->pun = to_del->pun;
            delete to_del; 
        }
		tmp = tail(tmp); 
	}
}

void delete_evenV3(lista& l)
{
	lista tmp = l;
	while(tmp != NULL)
    {
		if(tail(tmp) != NULL)
		{
			elem* to_del = tail(tmp);
			tmp->pun = tail(to_del);
        	delete to_del; 
		}
		tmp = tail(tmp);
	}
}
/*****************************************/

int main()
{
	int val[]={6, 5, 2, 3, 1};	// 1 3 2 5 6
	
    elem* e1_test = NULL;

    elem* e2_test = new elem;
    e2_test->v = 1998;
    e2_test->pun = NULL;

    /*  DELETE EVEN V1   */
    lista l1 = create_list(5,val);  
    delete_even(e1_test);     
    delete_even(e2_test);     
    delete_even(l1);
    print_list(l1);

    /*  DELETE EVEN V2   */
	lista l2 = create_list(5,val);    
    delete_evenV2(e1_test);
    delete_evenV2(e2_test);
    delete_evenV2(l2);
    print_list(l2);

    /*  DELETE EVEN V23  */
	lista l3 = create_list(5,val);    
    delete_evenV3(e1_test);
    delete_evenV3(e2_test);
    delete_evenV3(l3);
    print_list(l3);
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

lista insert_elem(lista l, elem* e)
{
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