/**
 * @file compito.cc
 * @author filippo
 * @brief gestione banca dati Punti di Interesse
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
#include <cstring>
#include "tipo.h"
#include "liste.h"
#include "grafo.h"

using namespace std;

void stampa_grafo(graph g); /* EXTRA */

/*****************PUNTO*1*****************/
/**
 * @brief acquisice i Punti di Interesse presenti nel file "PI.txt"
 * 
 * @param pi (ritorna) lista dei Punti di Interesse
 * @return int ritorna il numero Punti di Interesse caricati
 */
int carica(lista& pi)
{
    ifstream file("PI.txt",ios::in);
    int count = 0;

    lista tmp = NULL;

    while(file.good())
    {
        tipo_inf t;
        file>>t.id;

        file.ignore();
        file.getline(t.nome,21);

        file>>t.tipo;

        if(file.eof())
            continue;

        elem* toIns = new elem;
        toIns->inf = t;
        toIns->pun = toIns->prev = NULL;
        tmp = ord_insert_elem(tmp,toIns);

        count++;
    }
    pi = tmp;
    return count;
}

/**
 * @brief dato un identificativo restituisce il Punto di Interesse
 * 
 * @param pi lista dei Punti di Interesse
 * @param id identificativo del Punto di Interesse
 * @return tipo_inf ritorna il Punto di Interesse
 */
tipo_inf search_pi(lista pi, int id)
{
    tipo_inf t = {0," ",' '};
    while(pi != NULL)
    {
        if(id < head(pi).id)
            return t;
        else if(id == head(pi).id)
            return head(pi);
        
        pi = tail(pi);
    }
    return t;
}
/*****************************************/

/*****************PUNTO*2*****************/
/**
 * @brief dato il numero dei Punti di Interesse, genera  e restituisce il grafo presente nel file "G.txt"
 * 
 * @param n numero dei Punti di Interesse
 * @return graph ritorna il grafo dei Punti di interesse
 */
graph mappa(int n)
{
    graph g = new_graph(n);
    ifstream file("G.txt");

    int v1,v2;

    while(file >> v1 >> v2)
        add_edge(g,v1,v2,1.0);

    return g;
}

/**
 * @brief stampa i Punti di Interesse in funzione del grafo
 * 
 * @param g grafo dei Punti di Interesse
 * @param pi lista dei Punti di Interesse
 */
void stampa_mappa(graph g, lista pi)
{
    lista l = pi;
    while(l != NULL)
    {
        cout<<head(l).nome<<", connesso a:\n";

        adj_list tmp = get_adjlist(g, head(l).id); 
        while(tmp) //Adjacent Nodes
        {  
            tipo_inf t = search_pi(pi,get_adjnode(tmp));
            cout<<t.nome<<", ";
            tmp = get_nextadj(tmp); //Switch to the next adjacent nodes
        }
        cout<<endl<<endl;
        l = tail(l);
    }
}
/*****************************************/

/*****************PUNTO*3*****************/
/**
 * @brief stampa tutti i Punti di Interesse dello stetsso tipo raggiungibile da node
 * 
 * @param g grado dei Punti di Interesse
 * @param node ID del Punto di Interesse di partenza
 * @param pi lista dei Punti di Interesse
 */
void trip(graph g, int node, lista pi)
{
    if(node < 1 || node > g.dim)
    {
        cout<<"ID non valido\n";
        return;
    }

    tipo_inf t1 = search_pi(pi,node);

    cout<<"Dato l'ID "<<node<<":"<<t1.tipo<<" - "<<t1.nome<<endl;
    adj_list tmp = get_adjlist(g, node); 
    while(tmp) //Adjacent Nodes
    {  
        tipo_inf t2 = search_pi(pi,get_adjnode(tmp));

        if(t2.tipo == t1.tipo)
            cout<<t2.id<<": "<<t2.tipo<<" - "<<t2.nome<<endl;

        tmp = get_nextadj(tmp); //Switch to the next adjacent nodes
    }
}
/*****************************************/

/*****************PUNTO*4*****************/
/**
 * @brief restituisce la Lista dei Punti di Interesse di tipo tipo
 * 
 * @param pi lista dei Punti di  Interesse
 * @param tipo tipo dei Punti di Interesse da cercare
 * @return lista lista dei  Punti di Interesse trovati
 */
lista genera(lista pi, char tipo)
{
    lista l = NULL;
    while (pi != NULL)
    {
        if(head(pi).tipo == tipo)
        {
            elem* e = new elem;
            e->inf = head(pi);
            e->pun = e->prev = NULL;
            l = insert_elem(l,e);
        }

        pi = tail(pi);
    }
    return l;
}

/**
 * @brief stampa la lista dei Punti di Interesse
 * 
 * @param l lista dei Punti di Interesse
 */
void stampa_lista(lista l)
{
    while(l != NULL)
    {
        print(head(l));
        l = tail(l);
    }
}
/*****************************************/


int main()
{
    /*****************PUNTO*1*****************/
    cout<<"\nRICERCA PUNTI DI INTERESSE";
    lista pi = NULL;
    int num_of_pi = carica(pi);

    bool flag = true;
    while(flag)
    {
        int id;
        cout<<"\nID Punto di Interesse [-1 per terminare]: ";
        cin>>id;

        if(id == -1)
        {
            flag = false;
            cout<<"FINE\n\n";
        }
        else
        {
            tipo_inf t = search_pi(pi,id);
            if(t.id == 0)
                cout<<"Punto di Interesse non trovato\n";
            else
                print(t);
        }
    }
    /*****************************************/
    
    /*****************PUNTO*2*****************/
    cout<<"\nCONNESSIONI PUNTI DI INTERESSE\n";
    graph g = mappa(num_of_pi);
    stampa_mappa(g,pi);
    /*****************************************/

    /*****************PUNTO*3*****************/
    cout<<"\nRICERCA PUNTI DI INTERESSE SIMILI";
    flag = true;
    while(flag)
    {
        int id;
        cout<<"\nID Punto di Interesse [-1 per terminare]: ";
        cin>>id;

        if(id == -1)
        {
            flag = false;
            cout<<"FINE\n\n";
        }
        else
            trip(g,id,pi);
    }
    /*****************************************/

    /*****************PUNTO*4*****************/
    cout<<"\nRICERCA PUNTI DI INTERESSE PER TIPO";
    flag = true;
    lista l = NULL;
    while(flag)
    {
        char tipo;
        cout<<"\nTipo Punto di Interesse [1 per terminare]: ";
        cin>>tipo;

        if(tipo == '1')
        {
            flag = false;
            cout<<"FINE\n\n";
        }
        else
        {
            l = genera(pi,tipo);
            
            if(l == NULL)
                cout<<tipo<<": Tipo Inesistente\n";
            else
                stampa_lista(l);
        }
    }
    /*****************************************/

    return 0;
}

/******************EXTRA******************/
void stampa_grafo(graph g)
{
    for (int i = 1; i <= get_dim(g); i++)
    { 
        adj_list tmp = get_adjlist(g, i); 
        cout<<"("<<i<<")"; //Node 
        while(tmp) //Adjacent Nodes
        {  
            cout<<" --> "<<get_adjnode(tmp); 
            tmp = get_nextadj(tmp); //Switch to the next adjacent nodes
        }
        cout<<endl;
    } 
}
/*****************************************/