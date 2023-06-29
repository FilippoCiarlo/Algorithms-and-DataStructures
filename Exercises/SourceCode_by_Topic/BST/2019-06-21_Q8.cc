#include <iostream>

using namespace std;

typedef int tipo_inf;

struct bnode
{
	tipo_inf inf;
	bnode* parent;	
	bnode* left;
	bnode* right;
};

typedef bnode* btree;

/************UTILITY*FUNCTIONS************/
tipo_inf copy_key(tipo_inf dest, tipo_inf source);
int compare_key(tipo_inf k1, tipo_inf k2);
tipo_inf get_key(bnode* n);

bnode* bst_newNode(tipo_inf k);
void bst_insert(btree& b, bnode* n);
void print_bst(btree b);

btree get_left(btree t);
btree get_right(btree t);
bnode* get_parent(bnode* n);
/*****************************************/

/***********SAME*TREES*FUNCTION***********/
bool same(btree b1, btree b2)
{
	if(b1 == NULL || b2 == NULL)
	{
		if(b1 == NULL && b2 == NULL)
			return true;
		else
			return false;
	}
  	else 
	{
		bool left = same(b1->left,b2->left); 
		bool right = same(b1->right, b2->right); 
		return (compare_key(b1->inf,b2->inf) == 0) && (left && right);
	}
}
/*****************************************/

/***********SECONDARY*FUNCTIONS***********/
void printResult(bool flag)
{
	if(flag)
		cout<<"they are equals\n";
	else
		cout<<"they are not equals\n";
}

void printBothTrees(btree b1, btree b2)
{
	print_bst(b1);
	cout<<endl;

	print_bst(b2);
	cout<<endl;
}
/*****************************************/

int main()
{
	/* FIRST TREE */
	bnode* b1_n1 = bst_newNode(1);  //
	bnode* b1_n2 = bst_newNode(2);  // left subtree
	bnode* b1_n3 = bst_newNode(3);  //
	bnode* b1_n4 = bst_newNode(4);  /* root-node */
	bnode* b1_n6 = bst_newNode(5);	//
	bnode* b1_n5 = bst_newNode(6);  // right subtree
	bnode* b1_n7 = bst_newNode(7);  //
	btree b1 = NULL;

	bst_insert(b1,b1_n1);	
	bst_insert(b1,b1_n2);
	bst_insert(b1,b1_n3);	
	bst_insert(b1,b1_n4);	
	bst_insert(b1,b1_n5);
	bst_insert(b1,b1_n6);	
	bst_insert(b1,b1_n7);

	/* SECOND TREE */
	bnode* b2_n1 = bst_newNode(1);  //
	bnode* b2_n2 = bst_newNode(2);	// left subtree
	bnode* b2_n3 = bst_newNode(3);  //
	bnode* b2_n4 = bst_newNode(4);	/* root-node */
	bnode* b2_n6 = bst_newNode(5);	//
	bnode* b2_n5 = bst_newNode(6);  // right subtree
	bnode* b2_n7 = bst_newNode(7);	// [8 instead of 7]
	btree b2 = NULL;

	bst_insert(b2,b2_n1);	
	bst_insert(b2,b2_n2);
	bst_insert(b2,b2_n3);	
	bst_insert(b2,b2_n4);	
	bst_insert(b2,b2_n5);
	bst_insert(b2,b2_n6);	
	bst_insert(b2,b2_n7);


	printBothTrees(b1,b2);
	printResult(same(b1,b2));
	
	b2_n7->inf = 8;	// [8 instead of 7]
	printBothTrees(b1,b2);
	printResult(same(b1,b2));

	return 0;
}

/************UTILITY*FUNCTIONS************/
tipo_inf copy_key(tipo_inf dest, tipo_inf source)
{
	dest = source;
	return dest;
}

int compare_key(tipo_inf k1, tipo_inf k2)
{
	return k1-k2;
}

tipo_inf get_key(bnode* n)
{
	return n->inf;
}

bnode* bst_newNode(tipo_inf k)
{
	bnode* n = new bnode;
	n->inf = copy_key(n->inf,k);
	n->right = n->left = n->parent = NULL;
	return n;
}

void bst_insert(btree& b, bnode* n)
{
	if(n == NULL)
    {
		cout<<"Empty Node\n";
		return;
	}

	btree tmp = NULL;
	btree n_parent = NULL;

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

void print_bst(btree b)
{
	if(get_left(b)!=NULL)
		print_bst(get_left(b));
	
	cout<<get_key(b)<<" ";

	if(get_right(b) != NULL)
		print_bst(get_right(b));
}

btree get_left(btree t)
{
	return t->left;
}

btree get_right(btree t)
{
	return t->right;
}

bnode* get_parent(bnode* n)
{
	return n->parent;
}
/*****************************************/

