#include <iostream>

using namespace std;

typedef int tipo_inf;

/************TREE************/
struct node
{
	tipo_inf inf;
    node* firstChild;
	node* nextSibling;
};

typedef node* tree;
/****************************/

/************QUEUE***********/
struct elem{
	node* inf;
	elem* pun;
};

typedef elem* lista;

typedef struct{
	lista head;
	lista tail;
} coda;
/****************************/

/*****************TREE*UF*****************/
void copy(tipo_inf& dest, tipo_inf source);
int compare(tipo_inf n1, tipo_inf n2);

node* new_node(tipo_inf variant_npos);
void insert_child(node*  n1, node* n2);
void insert_sibling(node* n1, node* n2);
void serialize(tree t);

tipo_inf get_inf(node* n);
node* get_firstChild(node* n);
node* get_nextSibling(node* n);
/*****************************************/

/*****************QUEUE*UF****************/
elem* new_elem(node* n);

coda new_queue();
coda enqueue(coda c, node* inf);
node* dequeue(coda& c);
node* first(coda c);
bool isEmpty(coda c);
/*****************************************/

/*************HEIGHT*FUNCTION*************/
int altezza_DFS(tree t)
{
	if(get_firstChild(t) == NULL)
		return 0;

	int max = 0;
	tree tmp = get_firstChild(t);

	while(tmp != NULL)
    {  
		int max_loc = altezza_DFS(tmp);  
		if(max_loc > max)
		    max = max_loc;
		tmp = get_nextSibling(tmp);  
	}
	return max+1;
}
/*****************************************/

/************DIMENSION*FUNCTION***********/
int dimensione_BFS(tree t)
{
	int count = 0;
	coda c = new_queue();
	c = enqueue(c, t);

	while(!isEmpty(c))
    {
        count++;
		node* n = dequeue(c);
		tree tmp = get_firstChild(n);
		while(tmp != NULL)
        {
			c = enqueue(c,tmp);
			tmp = get_nextSibling(tmp);
		}
	}
	return count;
}

int dimensione_DFS(tree t)
{
	int dim = 0;
	tree tmp = get_firstChild(t);

	while(tmp != NULL)
    {
		int dim_loc = dimensione_DFS(tmp);
		tmp = get_nextSibling(tmp);
        dim += dim_loc;
	}
	return dim+1;
}
/*****************************************/

int main()
{
    /*  ROOT LEVEL */
    node* n0 = new_node(0);

    /*  1st LEVEL */
	node* n1 = new_node(8);	// era 2
	node* n2 = new_node(8);	// era 3
	node* n3 = new_node(4);

    /*  2nd LEVEL */
	node* n4 = new_node(8);	// era 5
	node* n5 = new_node(6);
	node* n6 = new_node(8);	// era 7
	node* n7 = new_node(8);	
	node* n8 = new_node(9);
	node* n9 = new_node(10);

    /*  3rd LEVEL */
	node* n10 = new_node(11);
	node* n11 = new_node(12);
	node* n12 = new_node(13);
	node* n13 = new_node(14);
	node* n14 = new_node(15);
	node* n15 = new_node(16);
	node* n16 = new_node(17);
	
    insert_child(n0, n1);
	insert_sibling(n1, n2);
	insert_sibling(n2, n3);
	
	insert_child(n1, n4);
	insert_sibling(n4, n5);
	
	insert_child(n2, n6);
	insert_sibling(n6, n7);
	
	insert_child(n3, n8);
	insert_sibling(n8, n9);

	insert_child(n4, n10);
	insert_sibling(n10, n11);
	
	insert_child(n5, n12);
	insert_sibling(n12, n13);
	
	insert_child(n8, n14);
	
	insert_child(n9, n15);
	insert_sibling(n15, n16);
	
    tree t = n0;
	serialize(t);
	cout<<endl;
	
    cout<<"The height of the tree is "<<altezza_DFS(t)<<endl;
    cout<<"The dimension of the tree is "<<dimensione_BFS(t)<<endl;
    cout<<"The dimension of the tree is "<<dimensione_DFS(t)<<endl;

	return 0;	
}

/************UTILITY*FUNCTIONS************/
void copy(tipo_inf& dest, tipo_inf source)
{
	dest = source;
}

int compare(tipo_inf n1, tipo_inf n2)
{
    return n1-n2;
}

node* new_node(tipo_inf inf){
	node* n = new node;
	copy(n->inf,inf);
	n->nextSibling = n->firstChild = NULL;
	return n;
}

// (t)-fC->(n0) => (t)-fC->(n1) && (n1)->(n0) 
void insert_child(node* n1, node* n2){
	n2->nextSibling = n1->firstChild;
	n1->firstChild = n2;
}

// (n1)->(n3) => (n1)->(n2)->(n3)
void insert_sibling(node* n1, node* n2){
	n2->nextSibling = n1->nextSibling;
	n1->nextSibling = n2;
}

void serialize(tree t)
{
	cout<<"("<<get_inf(t);
	tree t1 = get_firstChild(t);
	while(t1 != NULL)
    {
		serialize(t1);
		t1 = get_nextSibling(t1);
	}
	cout<<")";
}

tipo_inf get_inf(node* n)
{
	return n->inf;
}

node* get_nextSibling(node* n)
{
	return n->nextSibling;
}

node* get_firstChild(node* n)
{	
	return n->firstChild;
}
/*****************************************/

/*****************QUEUE*UF****************/
elem* new_elem(node* n)
{
    elem* e = new elem;  
	e->inf = n;
	e->pun = NULL;
	return e;

}

coda new_queue()
{
	coda c = {NULL, NULL};
	return c;
}

coda enqueue(coda c, node* inf)
{
	elem* p = new elem;
	p->inf = inf; 
	p->pun = NULL; 
	
	if(c.tail != NULL) 
		c.tail->pun = p;
	
	c.tail = p;
 	
	if(c.head == NULL)
		c.head = c.tail; 
	return c;
}

node* dequeue(coda& c)
{
	lista tmp = c.head;
	node* inf;

	inf = c.head->inf;
	c.head = c.head->pun;

	delete tmp;
	return inf;
}

node* first(coda c)
{
	return (c.head)->inf;
}

// true = if the queue is empty 
// flase = if the queue contains something
bool isEmpty(coda c)
{
	if(c.head == NULL)
		return true;
	return false;
}
/*****************************************/
