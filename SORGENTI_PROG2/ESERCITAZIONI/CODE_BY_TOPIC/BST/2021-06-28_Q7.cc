/*
 * ! Attention
 * Compile the program with the option: -Wno-write-strings
 * g++ -Wno-write-strings 2021-06-28_Q7.cc 
 */
#include <iostream>
#include <cstring>

using namespace std;

struct bnode
{
	char* key;
	bnode* left;
	bnode* right;
	bnode* parent;
};

typedef bnode* bst;

/************UTILITY*FUNCTIONS************/
int compare_key(char* dest, char* source);
char* get_key(bnode* n);

bnode* bst_newNode(char* k);
void print_bst(bst b);

bnode* get_left(bnode* n);
bnode* get_right(bnode* n);
bnode* get_parent(bnode* n);
/*****************************************/

/*************SEARCH*FUNCTION*************/
// THIS IS THE BEST OF THE THREE
bnode* bst_search(bst b, char* k)
{
	while(b != NULL)
	{
		if(compare_key(k,get_key(b)) == 0)
			return b;
		else if(compare_key(k,get_key(b)) < 0)
			b =  get_left(b);
		else
			b = get_right(b);
	}
	return NULL;
}

bnode* bst_searchV2(bst b, char* k)
{
	bnode* n = NULL;
	while(b != NULL && n == NULL)
	{
		int cmp = compare_key(k,b->key);
		if(cmp == 0)
			n = b;
		else if(cmp <= 0)
			b = b->left;
		else
			b = b->right;
	}
	return n;
}
/*
bnode* bst_search(bst b, char* k)
{
	bnode* ris = NULL;
	if(compare_key(k,get_key(b)) == 0)
		ris = b;
	if(ris == NULL && compare_key(k,get_key(b)) < 0)
		ris = bst_search(get_left(b),k);
	if(ris == NULL && compare_key(k,get_key(b)) > 0)
		ris = bst_search(get_right(b),k);
	return ris;
}
*/
/*
bnode* bst_search(bst b, char* k)
{
	bnode* ris = NULL;
	if(ris == NULL && compare_key(k, get_key(b)) == 0)
		ris = b;
	else if (ris == NULL && compare_key(k, get_key(b)) < 0)
		ris = bst_search(get_left(b),k);
	else
		ris = bst_search(get_right(b),k);
	return ris;
}
*/
/*****************************************/

int main()
{
	bnode* n1 = bst_newNode("a");	//
	bnode* n2 = bst_newNode("b");	// left subtree
	bnode* n3 = bst_newNode("c");	//
	bnode* n4 = bst_newNode("d");	/* root-node */
	bnode* n5 = bst_newNode("e");	//
	bnode* n6 = bst_newNode("f");	// right subtree
	bnode* n7 = bst_newNode("g");	//

	n1->parent = n2;	// (a)->(b)
	n3->parent = n2;	// (c)->(b)

    n2->parent = n4;    // (b)->(d)
    n6->parent = n4;    // (f)->(d)

	n5->parent = n6;	// (e)->(f)
	n7->parent = n6;	// (g)->(f)

	n2->left = n1;		// (a)<-L-(b)
	n2->right = n3;		// (b)-R->(c)

	n4->left = n2;		// (b)<-L-(d)
	n4->right = n6;		// (d)-R->(f)

	n6->left = n5;		// (e)<-L-(f)
	n6->right = n7;		// (f)-R->(g)

	bst head = n4;
	print_bst(head);
	cout<<endl;
	
	bnode* str_key = NULL;
	str_key = bst_search(head,"f");
	cout<<"result: "<<get_key(str_key)<<endl;
	
	str_key = bst_searchV2(head,"f");
	cout<<"result: "<<get_key(str_key)<<endl;
	return 0;
}

/************UTILITY*FUNCTIONS************/
char* copy_key(char*& dest, char* source)
{
	dest = source;
	return dest;
}

// <0	k1 < k2
// 0	k1 == k2
// >0	k1 > k2
int compare_key(char* k1, char* k2)
{
	return strcmp(k1,k2);
}

bnode* bst_newNode(char* k)
{
	bnode* n = new bnode;
	copy_key(n->key,k);
	n->right = n->left = n->parent = NULL;
	return n;
}

void print_bst(bst b)
{
	if(get_left(b)!=NULL)
		print_bst(get_left(b));
	
	cout<<get_key(b)<<" ";

	if(get_right(b) != NULL)
		print_bst(get_right(b));
}

char* get_key(bnode* n)
{
	return (n->key);
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