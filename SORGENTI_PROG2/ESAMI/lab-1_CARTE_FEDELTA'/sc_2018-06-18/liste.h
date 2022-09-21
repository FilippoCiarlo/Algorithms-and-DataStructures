struct elem
{
       int inf;
       elem* pun ;
       elem* prev;
} ;

typedef elem* lista ;
	
lista tail(lista);
lista prev(lista);
lista insert_elem(lista, elem*);
lista delete_elem(lista, elem*);
lista ord_insert_elem(lista, elem*);

int head(lista);
elem* ord_search(lista, int);
elem* new_elem(int);
elem* search(lista, int);
int compare(int i1, int i2);