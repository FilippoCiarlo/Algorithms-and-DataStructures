/**
 * @file grafo.h
 * @author filippo
 * @brief header file "grafo"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

/************GRAPH***********/
struct adj_node 
{ 
	int node; 		// vertex
	float weight; 	// edge’s weight
    adj_node* next;	// next adjacency node
}; 

typedef adj_node* adj_list; 

typedef struct 
{ 
	adj_list* nodes;	// graph / list of vertices / list of adjacency lists
	int dim; 		    // number of vertices
} graph; 
/****************************/

graph new_graph(int n);
void add_arc(graph& g, int u, int v, float w);
void add_edge(graph& g, int u, int v, float w);
void print_graph(graph g);

int get_dim(graph g);
adj_list get_adjlist(graph g, int u);
int get_adjnode(adj_node* n);
float get_adjweight(adj_list l);
adj_node* get_nextadj(adj_list l);

void stampa(graph g);

float mean(graph g);     
bool same_degree(graph g); 
