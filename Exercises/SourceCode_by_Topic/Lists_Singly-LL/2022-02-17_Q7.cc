#include <iostream>

using namespace std;

typedef int tipo_inf;

struct elem
{
    tipo_inf inf;
    elem* pun;
};

typedef elem* lista;

/************UTILITY*FUNCTIONS************/
void copy(tipo_inf& dest, tipo_inf source);
void summ(tipo_inf& val1, tipo_inf val2);

tipo_inf head(elem* e);
elem* tail(elem* e);
lista insert_elem(lista l, elem* e);
void print_list(lista l);
/*****************************************/

/************SECONDARY*FUNCTION************/
lista create_list(int n, int val[]);
/*****************************************/

/**************SUMM*FUNCTION**************/
lista somma_elemento(lista l, int idx)
{
    lista tmp = l;
    tipo_inf val;
    copy(val,0);
    
    for(int i = 0; tmp != NULL && i <= idx; i++, tmp = tail(tmp))
        copy(val,tmp->inf);
    
    tmp = l;
    while(tmp != NULL)
    {
        summ(tmp->inf,val);
        tmp = tail(tmp);
    }
    
    return l;
}
/*****************************************/

int main()
{
    int val[]={3, 4, 2, 5};	// 5 2 4 3
   
    lista l = create_list(4,val);  
    print_list(l);

    l = somma_elemento(l,2);
    print_list(l);

    return 0;
}

/************UTILITY*FUNCTIONS************/
void copy(tipo_inf& dest, tipo_inf source)
{
    dest = source;
}

void summ(tipo_inf& val1, tipo_inf val2)
{
    val1 += val2;
}

tipo_inf head(elem* e)
{
    return e->inf;
}

elem* tail(elem* e)
{
    return e->pun;
}

lista insert_elem(lista l, elem* e)
{
    e->pun =  l;
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

/************SECONDARY*FUNCTION************/
lista create_list(int n, int val[])
{
	lista l = NULL;
	for(int i = 0; i < n; i++)
    {
		elem* e = new elem;
		copy(e->inf,val[i]);
		l = insert_elem(l,e);
	}
	return l;
}
/*****************************************/