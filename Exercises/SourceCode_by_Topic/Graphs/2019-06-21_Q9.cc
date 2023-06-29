#include <iostream>

using namespace std;

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


/************UTILITY*FUNCTIONS************/
graph new_graph(int n);
void add_arc(graph& g, int u, int v, float w);
void add_edge(graph& g, int u, int v, float w);
void print_graph(graph g);

int get_dim(graph g);
adj_list get_adjlist(graph g, int u);
int get_adjnode(adj_node* n);
float get_adjweight(adj_list l);
adj_list get_nextadj(adj_list l);
/*****************************************/

/***********MEAN*DEGREE*FUNCTION**********/
float mean(graph g)
{
    int num_nodes = 0;

    for(int i = 1; i <= get_dim(g); i++)
        for(adj_list tmp = get_adjlist(g,i); tmp != NULL; tmp = get_nextadj(tmp))
            num_nodes++;

    return (float) num_nodes/get_dim(g);
}
/*****************************************/

int main()
{
	graph g = new_graph(5);
	
	add_arc(g,1,2,0);   // (1)->(2)
	add_arc(g,1,5,0);   // (1)->(5)

	add_arc(g,2,1,0);   // (2)->(1)
    add_arc(g,2,3,0);   // (2)->(3)
	add_arc(g,2,4,0);   // (2)->(4)
	add_arc(g,2,5,0);   // (2)->(5)

	add_arc(g,3,2,0);   // (3)->(2)
	add_arc(g,3,4,0);   // (3)->(4)
	
	add_arc(g,4,2,0);   // (4)->(2)
	add_arc(g,4,3,0);   // (4)->(4)
	add_arc(g,4,5,0);   // (4)->(5)

	add_arc(g,5,1,0);   // (5)->(1)
	add_arc(g,5,2,0);   // (5)->(2)
	add_arc(g,5,4,0);   // (5)->(4)

	print_graph(g);
    cout<<"Mean degree: "<<mean(g)<<endl;   //(2+4+2+3+3)/5 =  2.8

    return  0;
}

/************UTILITY*FUNCTIONS************/
// Creates a graph using an Adjacency List of "n" vertices
graph new_graph(int n)
{
	graph g;
	g.dim = n;
	g.nodes = new adj_list[n];
	for (int i = 0; i < n; i++)
		g.nodes[i] = NULL;
	return g;
}

// Adds the Directed Arc (u, v) to the Adjacency List of Node u
// The Directed Arc has weight w
void add_arc(graph& g, int u, int v, float w)
{
	adj_node* t = new adj_node;
	t->node = v;
	t->weight = w;
	t->next = g.nodes[u-1];
	g.nodes[u-1] = t;
}

// Adds the Non-Directed Arc (u, v) to the Adjacency Lists u and v
// The Non-Directed Arc has weight w
void add_edge(graph& g, int u, int v, float w)
{
	add_arc(g,u,v,w);
	add_arc(g,v,u,w);
}

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

int get_dim(graph g)
{
	return g.dim;
}

adj_list get_adjlist(graph g, int u)
{
	return g.nodes[u-1];
}

int get_adjnode(adj_node* n)
{
	return (n->node+1);
}

adj_list get_nextadj(adj_list l)
{
	return l->next;
}

float get_adjweight(adj_list l)
{
	return l->weight;
}
/*****************************************/