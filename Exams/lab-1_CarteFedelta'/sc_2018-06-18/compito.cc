/**
 * @file compito.cc
 * @author filippo
 * @brief implementa la gestione carte di un supermercato
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <cstring>
#include <string>
#include "carta.h"
#include "bst.h"

#include "liste.h"  /* PUNTO 5 */

using namespace std;

/****************PUNTO*2.b****************/
/** PUNTO 2.b
 * @brief somma i punti delle carte che vannno da inf a sup
 * 
 * @param b carte
 * @param inf prima carta
 * @param sup n-esima carta
 * @return int somma totale dei punti
 */
int totalePunti(bst b, int inf, int sup)
{
    if(b == NULL)
        return 0;
    else if(inf <= b->key && b->key <= sup)
        return b->inf.punti + totalePunti(b->left,inf,sup) + totalePunti(b->right,inf,sup);
    else
        return totalePunti(b->left,inf,sup) + totalePunti(b->right,inf,sup);
}
/*****************************************/

/****************PUNTO*3&4****************/
/** Punto 3 & 4
 * @brief aggiorna il punteggio di una carta
 * 
 * @param b carte
 * @param codice ID della carta
 * @param acquisto punteggio da sommare
 * @return elem* carta aggiornata
 */
elem* aggiorna(bst b, int codice, int acquisto)
{
    elem* e = NULL;
    bnode* tmp = bst_search(b,codice);
    if(tmp != NULL)
    {
        tmp->inf.punti += acquisto;

        e = new elem;
        e->inf = codice;
        e->pun = NULL;
    }else
        cout<<"CARTA INESISTENTE\n";
    
    return e;
}
/*****************************************/

/*****************PUNTO*4*****************/
/** Punto 4
 * @brief controlla se una carta è stata aggiornata
 * 
 * @param carte lista delle carte aggiornate
 * @param codice ID della carta da controllare
 * @return true 
 * @return false 
 */
bool isUpdated(lista carte, int codice)
{
    if(search(carte,codice) != NULL)
        return true;
    else
        return false;
}

/** Punto 4
 * @brief stampa la lista delle carte non aggiornate
 * 
 * @param b tutte le carte
 * @param l carte aggiornate
 */
void print_not_upp(bst b, lista l)
{
    if(b->left != NULL)
        print_not_upp(b->left,l);
    
    /**STAMPA*DELLE*INFORMAZIONI**/
    if(!isUpdated(l,b->key))
    {
	    print_key(get_key(b));
	    cout<<" ";
	    print_inf(get_value(b));
	    cout<<endl;
    }
	/*****************************/

	if(b->right != NULL)
		print_not_upp(b->right,l);
}
/*****************************************/

int main()
{
    /*****************PUNTO*1*****************/
    cout<<"\nINSERIMENTO CARTE\n";
    int num_utenti;
    cout<<"Numero di carte da inserire: ";
    cin>>num_utenti;

    bst b = NULL;
    for(int i = 0; i < num_utenti; i++)
    {
        int codice;
        cout<<"\nCodice carta: ";
        cin>>codice;

        tipo_inf utente;
        cout<<"Intestatario carta [NOME COGNOME]: ";
        cin.ignore();                   //PROVA
        cin.getline(utente.nome, 40);   //PROVA
        //leggi_riga(cin,utente.nome);

        cout<<"Punti carta: ";
        cin>>utente.punti;

       bst_insert(b,bst_newNode(codice,utente));
    }
    /*****************************************/

    /*****************PUNTO*2*****************/
    cout<<"\nCARTE\n";
    bst_print(b);
    /*****************************************/

    /*****************PUNTO*3*****************/
    cout<<"\nINSERIMENTO ACQUISTI";
    lista carte_agg = NULL; // Carte aggiornate
    bool flag = true;
    while(flag)
    {
        int codice;
        cout<<"\nCodice carta [-1 per terminare]: ";
        cin>>codice;
        if(codice == -1)
        {
            cout<<"FINE\n";
            flag = false;
        }
        else
        {
            int acquisto;
            cout<<"Punti acquisto [-1 per terminare]: ";
            cin>>acquisto;
            if(acquisto == -1)
            {
                cout<<"FINE\n";
                flag = false;
            }
            else
            {
                elem* e = aggiorna(b,codice,acquisto);
                if(e != NULL)
                    carte_agg = insert_elem(carte_agg,e);
            }
        }
    }
    
    cout<<"\nCARTE\n";
    bst_print(b);
    /*****************************************/

    /****************PUNTO*2.b****************/
    cout<<"\nSOMMA PUNTI CARTE\n";
    int inf,sup;
    cout<<"Inserisci il numero della carta di partenza (limite inferiore): ";
    cin>>inf;
    cout<<"Inserisci il numero della carta di arrivo (limite superiore): ";
    cin>>sup;
    cout<<"La somma dei punti dalla carta n°"<<inf<<" alla n°"<<sup<<" è "<<totalePunti(b,inf,sup)<<endl;
    /*****************************************/

    /*****************PUNTO*4*****************/
    cout<<"\nCARTE CHE NON HANNO EFFETTUATO ACQUISTI\n";
    print_not_upp(b,carte_agg);
    /*****************************************/

    return 0;
}
