#include <iostream>

using namespace std;

typedef int tipo_key;

struct bnode
{
	tipo_key key;
	bnode* left;
	bnode* right;
	bnode* parent;
};

typedef bnode* bst;

/************UTILITY*FUNCTIONS************/
tipo_key copy_key(tipo_key& dest, tipo_key source);
int compare_key(tipo_key dest, tipo_key source);
tipo_key get_key(bnode* n);

bnode* bst_newNode(tipo_key k);
void bst_insert(bst& b, bnode* n);
void print_bst(bst b);

bnode* get_left(bnode* n);
bnode* get_right(bnode* n);
bnode* get_parent(bnode* n);
/*****************************************/

/************SUBTREE*FUNCTION************/
void print_bstV3(bst b)
{	
	if(get_right(b) != NULL)	    /* scroll the right subtree */
		print_bstV3(get_right(b));

	cout<<get_key(b)<<" ";

	if(get_left(b) != NULL)		    /* scroll the left subtree */
		print_bstV3(get_left(b));
}

void print_subtree(bst b, int x){
	if(b == NULL) // Empty BST
		return;

	while(b != NULL)
    {
		if(get_key(b) == x)
        {		
			print_bstV3(b);
			return;
		}
        else if(get_key(b) < x)		
			b = get_right(b);
		else					
			b = get_left(b);
	}
	
	cout<<"Subtree Not Found\n";
}
/****************************************/

int main()
{
	bnode* n1 = bst_newNode(1);	//
	bnode* n2 = bst_newNode(2);	// left subtree
	bnode* n3 = bst_newNode(3);	//
	bnode* n4 = bst_newNode(4);	/* root-node */
	bnode* n5 = bst_newNode(5);	//
	bnode* n6 = bst_newNode(6);	// right subtree
	bnode* n7 = bst_newNode(7);	//

	n1->parent = n2;	// (1)->(2)
	n3->parent = n2;	// (3)->(2)

    n2->parent = n4;    // (2)->(4)
    n6->parent = n4;    // (6)->(4)

	n5->parent = n6;	// (5)->(6)
	n7->parent = n6;	// (7)->(6)

	n2->left = n1;		// (1)<-L-(2)
	n2->right = n3;		// (2)-R->(3)

	n4->left = n2;		// (2)<-L-(4)
	n4->right = n6;		// (4)-R->(6)

	n6->left = n5;		// (5)<-L-(6)
	n6->right = n7;		// (6)-R->(7)

	bst head = n4;
	print_bst(head);
	cout<<endl;
	
	int n;
	cout<<"n: ";
	cin>>n;
	print_subtree(head,n);
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

bnode* bst_newNode(int k)
{
	bnode* n = new bnode;
	n->key = k;
	n->right = n->left = n->parent = NULL;
	return n;
}

void bst_insert(bst& b, bnode* n)
{
	if(n == NULL)
    {
		cout<<"Empty Node\n";
		return;
	}
	bst tmp = NULL;
	bst n_parent = NULL;
	if(b == NULL)	
		b = n;
	else
    {	
		tmp = b;
		while(tmp != NULL)
        {		
			n_parent = tmp;
			if(get_key(n) < get_key(tmp))		
				tmp = get_left(tmp);
			else		
				tmp = get_right(tmp);
		}

		n->parent = n_parent;
		if(get_key(n) < get_key(n_parent))			
			n_parent->left = n;
		else		
			n_parent->right = n;
	}
}

void print_bst(bst b)
{
	if(get_left(b) != NULL)
		print_bst(get_left(b));
	
	cout<<get_key(b)<<" ";

	if(get_right(b) != NULL)
		print_bst(get_right(b));
}

bst get_left(bnode* n)
{
	return (n->left);
}

bst get_right(bnode* n)
{
	return (n->right);
}

bnode* get_parent(bnode* n)
{
	return (n->parent);
}
/*****************************************/



