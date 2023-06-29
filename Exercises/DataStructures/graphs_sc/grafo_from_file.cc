#include <iostream>
#include <fstream>
#include "grafo.h"

using namespace std;

const char FILENAME[] = "graph";    // name of the file

/***************PRINT*GRAPH***************/
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
            tmp = get_nextadj(tmp); // Switch to the next adjacent nodes
        }
        cout<<endl;
    } 
}
/*****************************************/

/***************BUILD*GRAPH***************/
void add(graph& g, int u, int v, float w, bool d)
{
    if(d)
        add_arc(g, u, v, w);    // Add to the Graph g a Directed Arc (u,v) with weigh w
    else
        add_edge(g, u, v, w);   // Add to the Graph g a Non-Directed Arc (u,v) with weigh w
}

graph g_build(ifstream &file, bool dir_graph, bool wei_graph)
{
    int n,v1,v2;
    file >> n;  // Read the dimension of the Graph graph g = new_graph(n);s
    
    graph  g = new_graph(n);
    if(wei_graph)   // If it’s a Wighted Graph float w;
    {  
        float w;
        while(file >> v1 >> v2 >> w)
            add(g,v1,v2,w,dir_graph);
    }
    else
    {
        while(file >> v1 >> v2)
            add(g,v1,v2,1.0,dir_graph);
    }

    return g;
}
/*****************************************/

int main()
{
    /* The ifstream object (file) it’s used to open a file for reading purpose only */
    ifstream file;
    file.open(FILENAME);

    bool dir_graph = true;  // Directed Graph
    bool wei_graph = false; // Weighted Graph
    graph g = g_build(file,dir_graph,wei_graph);    // creates and returns a graph based on file input

    stampa(g);

    return 0;
}