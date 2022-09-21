/* PRIMA DELL'UTILIZZO RIDEFINIRE IL TIPO */
/* INCLUDERE L'HEADER DEL NUOVO TIPO */
typedef int tipo_inf;

/**
 * @file lista.h
 * @author filippo
 * @brief header file "lista"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/************LISTA***********/
struct elem
{
    tipo_inf inf;
    elem* pun;
};

typedef elem* lista;
/****************************/

tipo_inf head(elem* e);
elem* tail(elem* e);

lista insert_elem(lista l, elem* e);
void print_list(lista l);
void stampa_ric(lista l);
void stampa_inv(lista l);

lista ord_insert_elem(lista l, elem* e);
lista sposta(lista& l, int soglia);
lista create_list(int n, int val[]);
void delete_even(lista& l);
lista somma_elemento(lista l, int idx);


