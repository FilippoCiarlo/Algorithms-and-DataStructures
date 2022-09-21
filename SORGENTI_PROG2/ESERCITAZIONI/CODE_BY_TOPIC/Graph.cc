#include <iostream>

using namespace std;

/************GRAPH***********/
struct adj_node 
{ 
	int node; 		// vertex
	float weight; 	// edge’s weight
    adj_node* next;	// next adjacency node
}; 

typedef adj_node* adj_list; 

typedef struct 
{ 
	adj_list* nodes;	// graph / list of vertices / list of adjacency lists
	int dim; 		    // number of vertices
} graph; 
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

/************UTILITY*FUNCTIONS************/
graph new_graph(int n);
void add_arc(graph& g, int u, int v, float w);
void add_edge(graph& g, int u, int v, float w);
void print_graph(graph g);

int get_dim(graph g);
adj_list get_adjlist(graph g, int u);
int get_adjnode(adj_node* n);
float get_adjweight(adj_list l);
adj_list get_nextadj(adj_list l);
/*****************************************/

/*****************QUEUE*UF****************/
elem* new_elem(node* n);

coda new_queue();
coda enqueue(coda c, node* inf);
node* dequeue(coda& c);
node* first(coda c);
bool isEmpty(coda c);
/*****************************************/

bool connected(graph g, int v){	//Si presuppone di usare solo Grafi Non-Orientati
	bool* reached = new bool[get_dim(g)];  //Array Booleano di controllo
	int x;
	
    for(int i = 0; i < get_dim(g); i++)  //Inizializza tutto l’Array di booleani a false
		reached[i] = false;

	coda c = new_queue();   // Crea una nuova Coda
	reached[v-1] = true;    // Imposta che il Vertice v è stato visitato
	c = enqueue(c,v);   // Aggiunge il Vertice v alla Coda q

	while(!isEmpty(c))  // Finchè la Coda q non è vuota
    { 
		int w = dequeue(c);
		// Scorre la lista di adicenza del Vertice w del Grafo g
		for(adj_node* n = get_adjlist(g, w); n != NULL; n = get_nextadj(n))
        {
			x = get_adjnode(n);
			if(!reached[x-1])   //Controlla se l’elemento (i-1) è stato raggiunto
            {      
				reached[x-1] = true;    // Dato che è stato raggiunto ora
				c = enqueue(c, x);      // Mette in coda l’elemento corrente
			}
		}
	}
	for(int i = 0; i < get_dim(g); i++)
		if(!reached[i])     // Se uno degli elementi non è stato raggiunto
			return false;   // Il Grafo non è connesso
	return true;    // Altrimenti il Grafo è connesso
}

int main()
{
	bnode* n1 = bst_newNode(7);	//
	bnode* n2 = bst_newNode(6);	// left subtree
	bnode* n3 = bst_newNode(5);	//
	bnode* n4 = bst_newNode(4);	/* root-node */
	bnode* n5 = bst_newNode(3);	//
	bnode* n6 = bst_newNode(2);	// right subtree
	bnode* n7 = bst_newNode(1);	//

	n1->parent = n2;	// (7)->(6)
	n3->parent = n2;	// (5)->(6)

    n2->parent = n4;    // (6)->(4)
    n6->parent = n4;    // (2)->(4)

	n5->parent = n6;	// (3)->(2)
	n7->parent = n6;	// (1)->(2)

	n2->left = n1;		// (7)<-L-(6)
	n2->right = n3;		// (6)-R->(5)

	n4->left = n2;		// (2)<-L-(4)
	n4->right = n6;		// (4)-R->(6)

	n6->left = n5;		// (3)<-L-(2)
	n6->right = n7;		// (2)-R->(1)

	bst head = n4;
	print_bst(head);
	cout<<endl;

    bnode* n = NULL;
	n = bst_search(head,2);
    cout<<"result: "<<get_key(n)<<endl;

    bst_delete(head,n);
    print_bst(head);
	cout<<endl;

	return 0;
}

/************UTILITY*FUNCTIONS************/
tipo_key copy_key(tipo_key& dest, tipo_key source)
{
	dest = source;
	return dest;
}

int compare_key(tipo_key k1, tipo_key k2)
{
	return k1-k2;
}

tipo_key get_key(bnode* n)
{
	return (n->key);
}

bnode* bst_newNode(tipo_key k)
{
	bnode* n = new bnode;
	copy_key(n->key,k);
	n->right = n->left = n->parent = NULL;
	return n;
}

void update_father(bnode* n1, bnode* n2)
{
	if (n1 == get_left(get_parent(n1)))
		(n1->parent)->left = n2;
	else
		(n1->parent)->right = n2;
}

void bst_delete(bst& b, bnode* n)
{
	bnode* new_child; 
	if(get_left(n) == NULL)
    {
		if (get_right(n) == NULL) 
			new_child = NULL;
		else // node with only right-child
			new_child = get_right(n);
	}
    else if (get_right(n) == NULL)  // node with only left-child
    { 
		new_child = get_left(n);
	}
    else    // node with two childs
    { 
		bnode* app = get_left(n);
		while (get_right(app) != NULL)
			app = get_right(app);

		if(get_left(app) == NULL)
			update_father(app, NULL);
        else
        {  
			(app->parent)->right = get_left(app);
			(app->left)->parent = get_parent(app);
		}
        
		app->left = get_left(n);
		app->right = get_right(n);

		if(get_left(app) != NULL)
			(app->right)->parent = app;
		if(get_left(app) != NULL)
			(app->left)->parent = app;

		new_child = app;
	}

	if(new_child != NULL)
		new_child->parent = get_parent(n);
	if(n == b) 
		b = new_child;
	else
		update_father(n, new_child);

	delete n;
}

void print_bst(bst b)
{
	if(get_left(b)!=NULL)
		print_bst(get_left(b));
	
	cout<<get_key(b)<<" ";

	if(get_right(b) != NULL)
		print_bst(get_right(b));
}

bnode* get_left(bnode* n)
{
	return (n->left);
}

bnode* get_right(bnode* n)
{
	return (n->right);
}

bnode* get_parent(bnode* n)
{
	return (n->parent);
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
