#include <iostream>

using namespace std;

/* */
struct node
{
	int inf;
	node* nextSibling;
	node* firstChild;
};

typedef node* tree;

/************UTILITY*FUNCTIONS************/
node* new_node(int val);
void insert_child(node*  n1, node* n2);
void insert_sibling(node* n1, node* n2);
void serialize(tree t);

int get_inf(node* n);
node* get_parent(node* n);
node* get_firstChild(node* n);
node* get_nextSibling(node* n);
/*****************************************/

/************FIND*PATH*FUNCTION***********/
bool path(node* n)
{
	bool ris = false;

	if(n == NULL)
		return false;
	else if(get_firstChild(n) == NULL && get_nextSibling(n) == NULL)
		return true;
	else if (get_firstChild(n) != NULL && get_inf(n) == get_inf(get_firstChild(n)))
		ris = path(get_firstChild(n));
	else if(get_nextSibling(n) != NULL && get_inf(n) == get_inf(get_nextSibling(n)))
		ris = path(get_nextSibling(n));
	
	node* tmp = get_nextSibling(n);
	while(tmp != NULL && !ris)
	{
		if(get_inf(n) == get_inf(tmp))
			ris = path(tmp);

		tmp = get_nextSibling(tmp);
	}
	return ris;
}
/*****************************************/

/************FIND*PATH*FUNCTION***********/
bool pathV2(node* n)
{
	if(n == NULL)
		return false;

	bool ris = false;
	node* fC = get_firstChild(n);
	node* nS = get_nextSibling(n);

	if(fC == NULL && nS == NULL)
		return true;
	else if (fC != NULL && get_inf(fC) == get_inf(n))
		ris = path(fC);
	else if(nS != NULL &&  get_inf(nS) == get_inf(n))
		ris = path(nS);

	nS = get_nextSibling(n);
	while(nS != NULL && !ris)
	{
		if(get_inf(nS) == get_inf(n))
			ris = path(nS);

		nS = get_nextSibling(nS);
	}
	return ris;
}
/*****************************************/

int main()
{
    /*  ROOT LEVEL */
    node* n0 = new_node(0);

    /*  1st LEVEL */
	node* n1 = new_node(8);
	node* n2 = new_node(8);	

    /*  2nd LEVEL */
	node* n3 = new_node(8);	
	node* n4 = new_node(1);
	node* n5 = new_node(8);
	node* n6 = new_node(8);

    /*  3rd LEVEL */
	node* n7 = new_node(2);
	node* n8 = new_node(3);
	node* n9 = new_node(8);

    insert_child(n0, n1);

	insert_sibling(n1, n2);
	insert_child(n1, n3);

	insert_sibling(n3, n4);
	insert_child(n3, n7);

	insert_child(n2, n5);
	
	insert_sibling(n5, n6);
	insert_child(n5, n8);

	insert_child(n6, n9);

	tree t =  n0;
	serialize(t);
	cout<<endl;
	
	bool result;
	result = path(t);
	cout<<"from "<<get_inf(t)<<" Function Output: "<<result<<endl;

	result = path(n1);
	cout<<"from "<<get_inf(n1)<<" Function Output: "<<result<<endl;

	result = pathV2(t);
	cout<<"from "<<get_inf(t)<<" Function Output: "<<result<<endl;

	result = pathV2(n1);
	cout<<"from "<<get_inf(n1)<<" Function Output: "<<result<<endl;

	return 0;	
}

/************UTILITY*FUNCTIONS************/
node* new_node(int inf){
	node* n = new node;
	n->inf = inf;
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
	tree tmp = get_firstChild(t);
	while(tmp != NULL)
    {
		serialize(tmp);
		tmp = get_nextSibling(tmp);
	}
	cout<<")";
}

int get_inf(node* n)
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
