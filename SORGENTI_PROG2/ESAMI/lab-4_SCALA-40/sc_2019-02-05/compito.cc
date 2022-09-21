/**
 * @file compito.cc
 * @author filippo
 * @brief gioco di carte tipo poker in cui il focus principale e' fare scala
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 * 6
 * 12Q 2P 10Q 3P 11Q 4P
 * 1F 6F 3F 5F 1C 4F
 * 
 * 9Q
 * 2C
 */
#include <iostream>
#include "tipo.h"
#include "liste.h"

using namespace std;

/*****************PUNTO*1*****************/
/**
 * @brief fa' pescare una carta e l'aggiunge alla lista delle carte
 * 
 * @param l lista delle carte
 */
void pesca(lista& l)
{
    carta t = {' ',0};
    bool flag = true;
    while(flag)
    {
        cout<<"Inserire un valore [1 - 13]: ";
        cin>>t.valore;
        if(t.valore < 1 || t.valore > 13)
            cout<<"Valore non consentito\n";
        else
            flag = false;
    }
    flag = true;
    while(flag)
    {
        cout<<"Inserire un seme [C,F,P,Q]: ";
        cin>>t.seme;
        if(t.seme  == 'C' || t.seme == 'F' || t.seme == 'P' || t.seme == 'Q')
            flag = false;
        else
            cout<<"Seme non consentito\n";
    }
    elem* toIns = new_elem(t);
    l = ord_insert_elem(l,toIns);
}

/**
 * @brief pesca n_carte e le aggiunge alla lista delle carte
 * 
 * @param n_carte numero di carte da pescare
 * @return lista lista delle carte
 */
lista pesca_carte(int n_carte)
{
    lista l = NULL;
    for(int i = 0; i < n_carte; i++)
        pesca(l);
    return l;
}

/**
 * @brief stampa la lista delle carte
 * 
 * @param l lista delle carte
 */
void stampa(lista l)
{
    while(l != NULL)
    {
        print(head(l));
        cout<<" ";
        l = tail(l);
    }
    cout<<endl;
}
/*****************************************/

/*****************PUNTO*2*****************/
/**
 * @brief cerca una scala in una lista di carte
 * 
 * @param carte lista di carte
 * @param lunghezza (ritorna) lunghezza della scala
 * @return elem* riorna il primo elemento della scala, NULL altrimenti
 */
elem* scala(lista carte, int& lunghezza)
{
    lunghezza = 0;
    elem* scala = NULL;

    while(carte != NULL)
    {
       if(lunghezza == 0)
            scala = carte;
        
        lunghezza++;

        if(lunghezza >= 3)
            if(scala->prev == NULL || head(scala->prev).seme != head(scala).seme)
                if(carte->pun == NULL || head(carte->pun).seme != head(carte).seme)
                    return scala;
        
        if(carte->pun != NULL && head(carte->pun).seme != head(carte).seme)
        {
            lunghezza = 0;
            scala = NULL;
        }

        carte = tail(carte);
    }
    return scala;
}

/**
 * @brief stampa la scala
 * 
 * @param l lista di carte della scala
 * @param lunghezza lunghezza della scala
 */
void stampa_scala(lista l, int lunghezza)
{
    for(int i = 0; i < lunghezza;  i++, l = tail(l))
    {
        print(head(l));
        cout<<" ";
    }
    cout<<endl;
}
/*****************************************/

/*****************PUNTO*3*****************/
/**
 * @brief cerca la prima scala, ne calcola il punteggio e la rimuove dalla lista delle carte
 * 
 * @param carte lista delle carte
 * @return int punteggio della scala
 */
int cala(lista& carte)
{
    int lunghezza = 0;
    lista tmp = scala(carte,lunghezza);
    int punteggio = 0;
    for(int i = 0; i < lunghezza && tmp != NULL; i++)
    {
        punteggio += head(tmp).valore;
        tmp = delete_elem(tmp,tmp);
    }
    return punteggio;
}
/*****************************************/

int main()
{
    /*****************PUNTO*1*****************/
    cout<<"\nPESCA DELLE CARTE\n";
    int n_carte;
    do{
        cout<<"Numero di carte per giocatore: ";
        cin>>n_carte;
    }while(n_carte < 0);

    cout<<"\nCarte Giocatore 1:\n";
    lista giocatore1 = pesca_carte(n_carte);

    cout<<"\nCarte Giocatore 2:\n";
    lista giocatore2 = pesca_carte(n_carte);

    cout<<endl; //  per migliorare la formattazione dell'output

    cout<<"\nMazzo Giocatore 1: ";
    stampa(giocatore1);

    cout<<"Mazzo Giocatore 2: ";
    stampa(giocatore2);
    /*****************************************/

    /*****************PUNTO*2*****************/
    cout<<"\nSCALE PRESENTI NELLE DUE MANO\n";
    int lunghezza_s1;
    lista scala1 = scala(giocatore1,lunghezza_s1);
    cout<<"Scala Giocatore 1: ";
    stampa_scala(scala1,lunghezza_s1);

    int lunghezza_s2;
    lista scala2 = scala(giocatore2,lunghezza_s2);
    cout<<"Scala Giocatore 2: ";
    stampa_scala(scala2, lunghezza_s2);
    /*****************************************/

    /*****************PUNTO*3*****************/
    cout<<"\nINIZIO DEL GIOCO\n";
    int punti_G1 = 0;
    int punti_G2 = 0;
    int tmp = 0;

    while(giocatore1 != NULL && giocatore2 != NULL)
    {
        cout<<"Pesca il Giocatore 1\n";
        pesca(giocatore1);
        tmp = cala(giocatore1);
        punti_G1 += tmp;
        tmp = 0;
        cout<<"Carte in mano: ";
        stampa(giocatore1);
        cout<<"Punteggio 1: "<<punti_G1<<endl;

        cout<<"Pesca il Giocatore 2\n";
        pesca(giocatore2);
        tmp = cala(giocatore2);
        punti_G2 = tmp;
        tmp = 0;
        cout<<"Carte in mano: ";
        stampa(giocatore2);
        cout<<"Punteggio: "<<punti_G2<<endl;

        if(giocatore1 == NULL || giocatore2 == NULL)
        {
            cout<<"Fine del Gioco\n";
            if(punti_G1 > punti_G2)
                cout<<"vincitore: Giocatore 1 con "<<punti_G1<<" punti\n";
            else
                cout<<"vincitore: Giocatore 2 con "<<punti_G2<<" punti\n";
        }
    }
    /*****************************************/

    return 0;
}