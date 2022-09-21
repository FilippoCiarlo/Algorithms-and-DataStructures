#include <iostream>

using namespace std;

struct elem
{
	int v;
	elem* pun;
};

typedef elem* lista;

/************UTILITY*FUNCTIONS************/
int head(lista l);
elem* tail(lista l);

lista insert_elem(lista l, elem* e);
void print_list(lista l);
/*****************************************/

/************SECONDARY*FUNCTION************/
lista create_list(int n, int val[]);

void print_result(lista l);
/*****************************************/

/**************SPLIT*FUNCTION*************/
lista split(lista& l)
{
	lista tmp = l;
	elem* last_tmp = l;	
	lista l1 = NULL;
	elem* last_l1 = NULL;
	
	while(tmp != NULL){	
		if(head(tmp) % 2 == 0){	
			if(l1 != NULL){ 			// if l1-list it's empty	
				last_l1->pun = tmp;		// last l1-node points to tmp
				last_l1 = tmp;			// updates  last l1-node
			}else					
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
	int val1[]={3, 4, 5, 2};
	int val2[]={3, 4, 2, 5};
	int val3[]={4, 3, 5, 2};
	int val4[]={3, 3, 5, 5};
   	int val5[]={4, 4, 2, 2};

    lista l1 = create_list(4,val1);  
    lista l2 = create_list(4,val2);  
    lista l3 = create_list(4,val3);  
    lista l4 = create_list(4,val4);  
    lista l5 = create_list(4,val5);  

    lista l_NULL = NULL;

	print_result(l_NULL);
	print_result(l1);
	print_result(l2);
	print_result(l3);
	print_result(l4);
	print_result(l5);

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

/************SECONDARY*FUNCTION************/
lista create_list(int n, int val[])
{
	lista l = NULL;
	for(int i = 0; i < n; i++)
    {
		elem* e = new elem;
		e->v = val[i],
		l = insert_elem(l,e);
	}
	return l;
}

void print_result(lista l)
{
	cout<<"list B: ";
	print_list(l);
	
	lista result = split(l);
	cout<<"list A: ";
	print_list(l);
	
	cout<<"result: ";
    print_list(result);
	cout<<endl;
}
/*****************************************/