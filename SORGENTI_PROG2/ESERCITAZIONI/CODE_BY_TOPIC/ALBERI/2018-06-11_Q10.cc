#include <iostream>

using namespace std;

typedef int tipo_inf;

struct node
{
	tipo_inf inf;
    node* firstChild;
	node* nextSibling;
};

typedef node* tree;

/************UTILITY*FUNCTIONS************/
void copy(tipo_inf& dest, tipo_inf source);
int compare(tipo_inf n1, tipo_inf n2);

node* new_node(tipo_inf variant_npos);
void insert_child(node*  n1, node* n2);
void insert_sibling(node* n1, node* n2);
void serialize(tree t);

tipo_inf get_inf(node* n);
node* get_parent(node* n);
node* get_firstChild(node* n);
node* get_nextSibling(node* n);
/*****************************************/

/**********FIND*PATH*FROM*VALUE**********
bool path(node* n, tipo_inf v)
{
	bool ris = false;
	if(n == NULL)
		return false;
	else if(compare(get_inf(n),v) == 0)
    	return true;
	else if(get_firstChild(n) != NULL)
		ris = path(get_firstChild(n),v);
	else if(get_nextSibling(n) != NULL)
		ris = path(get_nextSibling(n),v);
	
    node* tmp = get_nextSibling(n);
   	while(tmp != NULL && !ris)
   	{
        ris = path(tmp,v);
		tmp = get_nextSibling(tmp);
    }
    return ris;
}
*****************************************/

/**********FIND*PATH*FROM*VALUE**********/
bool pathV2(node* n, tipo_inf v)
{
	if(n == NULL)
		return false;
	else if(compare(get_inf(n),v) == 0)
    	return true;

	bool ris = false;
	node* fC = get_firstChild(n);
	node* nS = get_nextSibling(n);
	
	if(fC != NULL)
		ris = pathV2(fC,v);
	else if(nS != NULL)
		ris = pathV2(nS,v);
	
    nS = get_nextSibling(n);
   	while(nS != NULL && !ris)
   	{
        ris = pathV2(nS,v);
		nS = get_nextSibling(nS);
    }
    return ris;
}
/*****************************************/

int conta(tree t, tipo_inf i)
{
	int cont = 0;
	while(t != NULL)
	{
        if(compare(t->inf,i) < 0)
            cont++;
        if(get_nextSibling(t) != NULL)
			for(tree tmp=get_nextSibling(t); tmp != NULL; tmp=get_nextSibling(tmp))
				if(compare(tmp->inf,i) < 0)
                	cont++;
        t = get_firstChild(t);
	}
	return cont;
}

/************SECONDARY*FUNCTION***********/
void findPath(node* n, tipo_inf v)
{
	if(pathV2(n,v))
		cout<<"Exist a path from "<<get_inf(n)<<" to "<<v<<endl;
	else
		cout<<"Doesn't exist a path from "<<get_inf(n)<<" to "<<v<<endl;
}
/*****************************************/

int main()
{
    /*  ROOT LEVEL */
    node* n0 = new_node(1);

    /*  1st LEVEL */
	node* n1 = new_node(2);
	node* n2 = new_node(3);
	node* n3 = new_node(4);

    /*  2nd LEVEL */
	node* n4 = new_node(5);	
	node* n5 = new_node(6);
	node* n6 = new_node(7);
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
	
	findPath(t,17);		// from 1 to 17
	findPath(n1,8);		// from 2 to 8
	findPath(n15,17);	// from 16 to 17
	findPath(n3,14);	// from 4 to 14

	cout<<"conta: "<<conta(t,8)<<endl;

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
