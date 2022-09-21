/**
 * @file grafo.cc
 * @author filippo
 * @brief implementazione modulo "grafo"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "grafo.h"

using namespace std;

/**
 * @brief Creates a graph using an Adjacency List of "n" vertices
 * 
 * @param n numero dei vertici
 * @return graph ritorna il grafo "vuoto" creato
 */
graph new_graph(int n)
{
	graph g;
	g.dim = n;
	g.nodes = new adj_list[n];
	for (int i = 0; i < n; i++)
		g.nodes[i] = NULL;
	return g;
}

/**
 * @brief Adds the Directed Arc (u, v) to the Adjacency List of Node u, with weight w
 * 
 * @param g grafo
 * @param u vertice sorgente (U)->(v)
 * @param v verdice destinazione (u)->(V)
 * @param w peso
 */
void add_arc(graph& g, int u, int v, float w)
{
	adj_node* t = new adj_node;
	t->node = v;
	t->weight = w;
	t->next = g.nodes[u-1];
	g.nodes[u-1] = t;
}

/**
 * @brief Adds the Non-Directed Arc (u, v) to the Adjacency Lists u and v, with weight w
 * 
 * @param g grafo
 * @param u primo vertice (U)<->(v)
 * @param v secondo vertice (u)<->(V)
 * @param w peso
 */
void add_edge(graph& g, int u, int v, float w)
{
	add_arc(g,u,v,w);
	add_arc(g,v,u,w);
}

/**
 * @brief stampa il grafo passato in ingresso
 * 
 * @param g grafo
 */
void print_graph(graph g)
{
	adj_node* tmp;
	for(int i = 1; i <= get_dim(g); i++)
	{
		cout<<i<<": ";
		tmp = g.nodes[i-1];
		while(tmp != NULL)
		{
			cout<<tmp->node<<" ";
			tmp = tmp->next;
		}
		cout<<endl;
	}
}

/**
 * @brief ritorna la diemnsione del grafo
 * 
 * @param g grafo
 * @return int dimensione del grafo (numero dei nodi)
 */
int get_dim(graph g)
{
	return g.dim;
}

/**
 * @brief dato un grafo riorna la lista di adiacenza del nodo  specificato
 * 
 * @param g grafo
 * @param u indice del nodo
 * @return adj_list lista di adiacenza
 */
adj_list get_adjlist(graph g, int u)
{
	return g.nodes[u-1];
}

/**
 * @brief ritorna il indice del nodo
 * 
 * @param n nodo
 * @return int indice del nodo
 */
int get_adjnode(adj_node* n)
{
	return (n->node+1);
}

/**
 * @brief data una lista di adiacenza ritorna il nodo adiacente
 * 
 * @param l lista di adiacenza
 * @return adj_list nodo adiacente
 */
adj_node* get_nextadj(adj_list l)
{
	return l->next;
}

/**
 * @brief ritorna il peso dell'arco
 * 
 * @param l lista di adiacenza
 * @return float peso
 */
float get_adjweight(adj_list l)
{
	return l->weight;
}

/**
 * @brief stampa il grafo passato in ingresso
 * 
 * @param g grafo
 */
void stampa(graph g)
{
    adj_list tmp;
    for (int i = 1; i <= get_dim(g); i++)
    { 
        tmp = get_adjlist(g, i); 
        cout<<"("<<i<<")"; //Node 
        while(tmp) //Adjacent Nodes
        {  
            cout<<" --> "<<get_adjnode(tmp); 
            tmp = get_nextadj(tmp); //Switch to the next adjacent nodes
        }
        cout<<endl;
    } 
}

/**
 * @brief calcola quanti nodi ci sono nella lista di adiacenza di ogni nodo e ne ritorna la media
 * 
 * @param g grafo
 * @return float media dei nodi adiacenti per ogni nodo
 */
float mean(graph g)
{
    int num_nodes = 0;

    for(int i = 1; i <= get_dim(g); i++)
        for(adj_list tmp = get_adjlist(g,i); tmp != NULL; tmp = get_nextadj(tmp))
            num_nodes++;

    return (float) num_nodes/get_dim(g);
}

/**
 * @brief controlla se ogni nodo ha lo stesso numero di nodi adiacenti
 * 
 * @param g grafo
 * @return true tutti i nodi hanno lo stesso numero di nodi adiacenti
 * @return false uno o più nodi non hanno lo stesso numero di nodi adiacenti
 */
bool same_degree(graph g)
{
    int* degree = new int[get_dim(g)];
    for(int i = 0; i<get_dim(g); i++)
        degree[i] = 0;
    
    for(int i = 1; i<=get_dim(g); i++)
    {
        adj_list l = get_adjlist(g,i);
        while (l != NULL)
        {
            degree[i-1]++;
            l = get_nextadj(l);
        }
    }

    int deg = degree[0];
    for(int i = 1; i<get_dim(g); i++)
        if(degree[i] != deg)
            return false;

    return true;
}
