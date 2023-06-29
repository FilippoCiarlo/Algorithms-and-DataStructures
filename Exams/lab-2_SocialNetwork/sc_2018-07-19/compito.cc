/**
 * @file compito.cc
 * @author filippo
 * @brief gestione di un Social Network tipo Twitter
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
#include "node.h"
#include "grafi.h"
#include "coda.h"

using namespace std;

/*****************PUNTO*1*****************/
/**
 * @brief stampa il grafo g
 * 
 * @param g grafo
 */
void stampa(graph g)
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

/*****************PUNTO*2*****************/
/**
 * @brief conta le righe del file
 * 
 * @param file stream
 * @return int numero di righe
 */
int count_lines(ifstream& file)
{
    int lines = 0;
    char row[81];

    while(file.good())
    {
        file.getline(row, 81);
        lines++;     
    } 
    return lines;
}

/**
 * @brief stampa i nodi del grafo
 * 
 * @param g grafo
 * @param nodes lista di nodi
 */
void stampaV2(graph g, node* nodes)
{
    adj_list tmp;
    for (int i = 1; i <= get_dim(g); i++)
    { 
        tmp = get_adjlist(g, i); 
        while(tmp) //Adjacent Nodes
        {  
            cout<<nodes[i-1].cont;

            if(nodes[i-1].tipo == 'U' && nodes[get_adjnode(tmp)-1].tipo == 'U')
                cout<<" FOLLOW ";
            else if(nodes[i-1].tipo == 'T' && nodes[get_adjnode(tmp)-1].tipo == 'U')
                cout<<" OWNER ";
            else if(nodes[i-1].tipo == 'U' && nodes[get_adjnode(tmp)-1].tipo == 'T')
                cout<<" LIKE ";
            else
                cout<<" --> ";

            cout<<nodes[get_adjnode(tmp)-1].cont<<endl; 
            
            tmp = get_nextadj(tmp); //Switch to the next adjacent nodes
        }
        cout<<endl;
    } 
}
/*****************************************/

/*****************PUNTO*3*****************/
/**
 * @brief conta il numero di like per ogni utente
 * 
 * @param g grafo
 * @param nodes lista dei nodi
 * @return int* lista dei likes per ogni utente
 */
int* totalLike(graph g, node* nodes)
{
    int* likes = new int[get_dim(g)];
    for (int i = 1; i <= get_dim(g); i++)
    { 
        if(nodes[i-1].tipo == 'U')
        {
            adj_list tmp = get_adjlist(g, i);
            while(tmp) //Adjacent Nodes
            {
                if(nodes[get_adjnode(tmp)-1].tipo == 'T')
                    likes[i-1]++;
                tmp = get_nextadj(tmp); //Switch to the next adjacent nodes
            } 
        }
        else
            likes[i-1] = 0;
    } 
    return likes;
}

/**
 * @brief stampa le Most Influential People
 * 
 * @param g grafo
 * @param nodes lista dei nodi
 * @param likes lista dei likes per ogni utente
 */
void mostInfluentialPeople(graph g, node* nodes, int* likes)
{
    int max = 0;
    for (int i = 1; i <= get_dim(g); i++)
        if(nodes[i-1].tipo == 'U')
            if(likes[i-1] > max)
                max = likes[i-1];

    for (int i = 1; i <= get_dim(g); i++)
        if(likes[i-1] == max)
            cout<<nodes[i-1].cont<<endl;
}
/*****************************************/

/*****************PUNTO*4*****************/
/**
 * @brief stampa l'elenco degli utenti seguiti direttamente o indiriettamente da user
 * 
 * @param g grafo
 * @param nodes lista dei nodi
 * @param user ID dell'utente
 */
void follow(graph g, node* nodes, int user)
{
    if(nodes[user-1].tipo == 'U')
    {
         cout<<nodes[user-1].cont<<" Follow:\n";
    }
    else
    {
        cout<<"Hai selezionato un Tweet\n";
        return;
    }

    coda c = newQueue();
    adj_list tmp = get_adjlist(g,user);

    while(tmp) //Adjacent Nodes
    {
        if(nodes[get_adjnode(tmp)-1].tipo == 'U'){
            cout<<nodes[get_adjnode(tmp)-1].cont<<endl;    //DEBUG
            c = enqueue(c,get_adjnode(tmp));
        }
        tmp = get_nextadj(tmp); //Switch to the next adjacent nodes
    }

    while(!isEmpty(c))
    {
        int idx = dequeue(c);
        adj_list tmp = get_adjlist(g,idx); 
        while(tmp) //Adjacent Nodes
        {  
            if(nodes[get_adjnode(tmp)-1].tipo == 'U')
                cout<<nodes[get_adjnode(tmp)-1].cont<<endl;
            tmp = get_nextadj(tmp); //Switch to the next adjacent nodes
        }
    }
}
/*****************************************/

int main()
{
    /*****************PUNTO*1*****************/
    cout<<"\nSTAMPA DEL GRAFO\n";
    ifstream file("graph");

    int dim,u,v;
    file >> dim;  //Read the dimension of the Graph
    graph g = new_graph(dim);

    while(file >> u >> v)
        add_arc(g, u, v, 1.0);    // Add to the Graph g a Directed Arc (u,v) with weigh w

    stampa(g);
    file.close();
    /*****************************************/

    /*****************PUNTO*2*****************/
    file.open("node");                      // Alternativamente
    const int DIM = count_lines(file)/2;    // DIM = get_dim(g)
    file.close();                           // anche se non ottimale

    cout<<"\nSTAMPA DEI NODI\n";
    file.open("node"); 
    node* nodes = new node[DIM];    // DIM = get_dim(g)

    for(int i = 0; file.good(); i++)
    {
        if(file.peek() == '\n')
            file.ignore();

        file.getline(nodes[i].cont, 81);
        file>>nodes[i].tipo;
    }

    file.close();    
    stampaV2(g,nodes);
    /*****************************************/

    /*****************PUNTO*3*****************/
    cout<<"\nMOST INFLUENTIAL PEOPLE\n";
    int* likes = totalLike(g,nodes);
    mostInfluentialPeople(g,nodes,likes);
    /*****************************************/

    /*****************PUNTO*4*****************/
    cout<<"\nFOLLOW";
    int user;
    do{
        cout<<"\nInserire un ID [1 - 8]: ";
        cin>>user;
        if(user < 1 || user > 8)
            cout<<"Valore al di fuori del range\n";
    }while(user < 1 || user > 8);

    follow(g,nodes,user);
    /*****************************************/

    return 0;
}
