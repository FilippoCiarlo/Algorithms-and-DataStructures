/* PRIMA DELL'UTILIZZO RIDEFINIRE IL TIPO */
/* TIPO CHIAVE */
/* TIPO CAMPO INFORMAZIONE SE PRESENTE */
/* INCLUDERE L'HEADER DEL NUOVO TIPO */
typedef int tipo_key;

/**
 * @file bst.h
 * @author filippo
 * @brief header file "bst"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/*************BST************/
struct bnode
{
	tipo_key key;
	bnode* left;
	bnode* right;
	bnode* parent;
};

typedef bnode* bst;
/****************************/

tipo_key copy_key(tipo_key& dest, tipo_key source);
int compare_key(tipo_key dest, tipo_key source);
tipo_key get_key(bnode* n);

bnode* bst_newNode(tipo_key k);
void print_bst(bst b);

bnode* get_left(bnode* n);
bnode* get_right(bnode* n);
bnode* get_parent(bnode* n);

bnode* bst_search(bst* b, tipo_key k);
bnode* bst_search_ric(bst b, tipo_key k); //ricorsiva

void aggiorna_chiave(bst& b, tipo_key l, tipo_key a);
void bst_insert(bst& b, bnode* n);
bool same(bst b1, bst b2);
void print_subtree(bst b, int x);


