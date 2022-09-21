
/*
 * ! Attention
 * Compile the program with the option: -Wno-write-strings
 * g++ -Wno-write-strings 2018-09-11_Q7.b\&c.cc  
 */
#include <iostream>
#include <cstring>

using namespace std;

struct libro{      
	char* autore;     
	char* titolo; 
};

/************TREE************/
struct bnode{
	libro key;
	bnode* left;
	bnode* right;
	bnode* parent;
};

typedef bnode* bst;
/****************************/

/************UTILITY*FUNCTIONS************/
int compare_key(libro l1, libro l2);
libro copy_key(libro dest, libro source);
libro get_key(bnode* n);

libro newLibro(char* aut, char* lib);
bnode* bst_newNode(libro l);
void bst_insert(bst& b, bnode* n);
void update_father(bnode* p, bnode* q);
void bst_delete(bst& b, bnode* n);
void print_bst(bst b);

bnode* get_left(bnode* n);
bnode* get_right(bnode* n);
bnode* get_parent(bnode* n);
/*****************************************/

void aggiorna_libro(bst& b, libro l, char* a)
{
	if(b == NULL)
		return;

	int cmp = compare_key(l,b->key);

	if(cmp == 0)
		b->key.autore = a;
	else if(cmp < 0)
		aggiorna_libro(b->left,l,a);
	else	
		aggiorna_libro(b->right,l,a);
}

int main(){
	libro l1 = newLibro("Filippo","a");
	libro l2 = newLibro("Giacomo","b");
	libro l3 = newLibro("Armando","c");
	libro l4 = newLibro("Marco","d");
	libro l5 = newLibro("Giovanni","e");
	libro l6 = newLibro("Federico","f");
	libro l7 = newLibro("Claudio","g");

	bnode* n1 = bst_newNode(l1);
	bnode* n2 = bst_newNode(l2);	
	bnode* n3 = bst_newNode(l3);
	bnode* n4 = bst_newNode(l4);	
	bnode* n6 = bst_newNode(l5);	
	bnode* n5 = bst_newNode(l6);
	bnode* n7 = bst_newNode(l7);
	bst head = NULL;

	bst_insert(head,n5);
	
	bst_insert(head,n1);

	bst_insert(head,n4);
	
	bst_insert(head,n3);
	bst_insert(head,n6);	
	bst_insert(head,n2);

	bst_insert(head,n7);

	print_bst(head);
	cout<<endl;
	
	return 0;
}

/***********************************************/
int compare_key(libro l1, libro l2)
{    
	if((strcmp(l1.autore,l2.autore) == 0) && 
        (strcmp(l1.titolo,l2.titolo) == 0 || strcmp(l1.titolo,l2.titolo)))
			return strcmp(l1.titolo,l2.titolo);
	if(strcmp(l1.autore,l2.autore) < 0)
		return strcmp(l1.autore,l2.autore);
	return strcmp(l1.autore,l2.autore)+1;
}

libro copy_key(libro dest, libro source)
{
	dest = source;
	return dest;
}

libro get_key(bnode* n)
{
	return n->key;
}

libro newLibro(char* aut, char* lib)
{
	libro l;
	l.autore = aut;
	l.titolo = lib;
	return l;
}

bnode* bst_newNode(libro l)
{
	bnode* n = new bnode;
	copy_key(n->key, l);
	n->right = n->left = n->parent = NULL;
	return n;
}

void bst_insert(bst& b, bnode* n)
{
	if(n == NULL)	// empty node
    	return;

	if(b == NULL)	
		b = n;
	else
    {	
		bst tmp = b;
		bst n_parent = NULL;
		
		while(tmp != NULL)
        {		
			n_parent = tmp;
			if(compare_key(get_key(n),get_key(tmp)) > 0)		
				tmp = get_left(tmp);
			else		
				tmp = get_right(tmp);
		}

		n->parent = n_parent;
		if(compare_key(get_key(n),get_key(tmp)) > 0)			
			n_parent->left = n;
		else		
			n_parent->right = n;
	}
}

void update_father(bnode* p, bnode* q)
{
	if (p == get_left(get_parent(p))) 
		(p->parent)->left = q;
	else
		(p->parent)->right = q;
}

void bst_delete(bst& b, bnode* n)
{
	bnode* new_child; 
	if(get_left(n) == NULL){
		if (get_right(n) == NULL)
			new_child = NULL; 
		else
			cout<<"Nodo con solo figlio destro\n"; 
			new_child = get_right(n);
	}
	else if (get_right(n) == NULL)
	{ 
		cout<<"Nodo con solo figlio sinistro\n";
		new_child = get_left(n);
	}
	else
	{ 
		cout << "Nodo con entrambi i figli\n";
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
	if(get_left(b)!= NULL)
		print_bst(get_left(b));

	// inserire comando stampa

	if(get_right(b) != NULL)
		print_bst(get_right(b));
}

bnode* get_left(bnode* n)
{
	return n->left;
}

bnode* get_right(bnode* n)
{
	return n->right;
}

bnode* get_parent(bnode* n)
{
	return n->parent;
}
/***********************************************/