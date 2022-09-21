/* PRIMA DELL'UTILIZZO RIDEFINIRE IL TIPO */
/* INCLUDERE L'HEADER DEL NUOVO TIPO */
typedef int tipo_inf;

/**
 * @file tree.h
 * @author filippo
 * @brief header file "tree"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/************TREE************/
struct node
{
	tipo_inf inf;
    node* firstChild;
	node* nextSibling;
};

typedef node* tree;
/****************************/

node* new_node(int val);
void insert_child(node*  n1, node* n2);
void insert_sibling(node* n1, node* n2);
void serialize(tree t);

int get_inf(node* n);
node* get_parent(node* n);
node* get_firstChild(node* n);
node* get_nextSibling(node* n);

bool path(node* n, tipo_inf v);
bool path(node* n);				
