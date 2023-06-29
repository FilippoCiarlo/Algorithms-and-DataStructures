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

bnode* bst_newNode(int k);
void print_bst(bst b);

bnode* get_left(bnode* n);
bnode* get_right(bnode* n);
bnode* get_parent(bnode* n);
/*****************************************/

/*************INSERT*FUNCTION*************/
void bst_insert(bst& b, bnode* n)
{
	if(n == NULL)	// Empty BST
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
/*****************************************/

int main(){
	bnode* n1 = bst_newNode(1);	//
	bnode* n2 = bst_newNode(2);	// left subtree
	bnode* n3 = bst_newNode(3);	//
	bnode* n4 = bst_newNode(4);	/* root-node */
	bnode* n5 = bst_newNode(5);	//
	bnode* n6 = bst_newNode(6);	// right subtree
	bnode* n7 = bst_newNode(7);	//

	bst head = NULL;

	bst_insert(head,n5);
	print_bst(head);
	cout<<endl;
	
	bst_insert(head,n1);
	print_bst(head);
	cout<<endl;
	
	bst_insert(head,n4);
	print_bst(head);
	cout<<endl;
	
	bst_insert(head,n3);
	print_bst(head);
	cout<<endl;
	
	bst_insert(head,n6);
	print_bst(head);
	cout<<endl;
	
	bst_insert(head,n2);
	print_bst(head);	
	cout<<endl;

	bst_insert(head,n7);
	print_bst(head);
	cout<<endl;

	/*	Empty Node	*/
	bnode* empty = NULL;		
	bst_insert(head,empty);
	print_bst(head);
	cout<<endl;
	
	/*	Double Head	*/
	bnode* bn1 = bst_newNode(1);
	bst_insert(head,bn1);		
	print_bst(head);
	cout<<endl;
	
	/*	Double Leaf	*/
	bnode* bn7 = bst_newNode(7);
	bst_insert(head,bn7);		
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

bnode* bst_newNode(int k)
{
	bnode* n = new bnode;
	n->key = k;
	n->right = n->left = n->parent = NULL;
	return n;
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