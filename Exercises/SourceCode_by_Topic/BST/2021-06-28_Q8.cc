#include <iostream>
#include <cstring>

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
bnode* bst_search(bst b, tipo_key k);
void print_bst(bst b);

bnode* get_left(bnode* n);
bnode* get_right(bnode* n);
bnode* get_parent(bnode* n);
/*****************************************/

/*************+PRINT*SUBTREE*+************/
void print_bst_V2(bst b, int val)
{
	if(get_left(b) != NULL)
		print_bst_V2(get_left(b),val);
	
    if(compare_key(get_key(b),val) < 0)
	    cout<<get_key(b)<<" ";

	if(get_right(b) != NULL)
		print_bst_V2(get_right(b),val);
}

void print_subtree(bst b, int x, int y)
{
    bnode* n = bst_search(b,x);
    if(n != NULL)
        print_bst_V2(n,y);
}
/*****************************************/

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
	
	print_subtree(head,4,4);
	
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


bnode* bst_search(bst b, tipo_key k)
{
	while(b != NULL)
	{
		if(compare_key(k,get_key(b)) == 0)
			return b;
		else if(compare_key(k,get_key(b)) > 0)
			b =  get_left(b);
		else
			b = get_right(b);
	}
	return NULL;
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