#include <iostream>

using namespace std;

typedef char* user;

struct elem
{
	user inf;
	elem* pun;
};

typedef elem* lista;

typedef struct
{
    lista head;
	elem* tail;
} coda;

/************GRAPH***********/
struct nodo
{
	int id;
	user u;
	nodo* next;
};

typedef nodo* adj_list;

typedef struct
{
	adj_list* nodes;
	int dim;
}graph;
/****************************/

/************UTILITY*FUNCTIONS************/
int compare(char* s1, char* s2);
void copy(char*& dest, char* source);
void print(char* s);

coda enqueue(coda c, user inf);
user dequeue(coda& c);
void printQueue(coda c);
bool isEmpty(coda c);
coda merge(coda c1, coda c2);
/*****************************************/

/*bool path(nodo n, user u)*/
bool path(nodo n, user u, graph g)
{
	bool* raggiunto = new int[g.dim];
	for(int i=0; i<g.dim; i++)
		raggiunto[i] = false;

	coda c = newQueue();
	c = enqueue(c,);

	while(!isEmpty(c))
	{
		nodo n2 = dequeue(c);
		if(!raggiunto[n2.id])
		{
			if(strcmp(n2.u,u) == 0)
				return true;
			
			raggiunto[n2.id] = true;
			adj_list* app = g.nodes[n2.id];

			while(app != NULL)
			{
				c = enqueue(c,app);
				app = app->next;
			}
		}
	}
}

int main()
{
	/* 1st QUEUE */
	coda c1;
	c1.head = c1.tail = NULL;
	c1 = enqueue(c1,"1"); 
	c1 = enqueue(c1,"3"); 
	c1 = enqueue(c1,"5"); 
	c1 = enqueue(c1,"6"); 
	c1 = enqueue(c1,"8"); 
    
	cout<<"1st Queue: ";
    printQueue(c1);

	/* 2nd QUEUE */
	coda c2;
	c2.head = c2.tail = NULL;
	c2 = enqueue(c2,"0"); 	
	c2 = enqueue(c2,"2"); 
	c2 = enqueue(c2,"4"); 
	c2 = enqueue(c2,"7"); 
	c2 = enqueue(c2,"9"); 
	
	cout<<"2nd Queue: ";
    printQueue(c2);

	/* MERGED QUEUE */
	coda c3;
	c3.head = c3.tail = NULL;
	c3 = merge(c1,c2);

	cout<<"Merged Queue: ";
    printQueue(c3);

    return 0;
}

/************UTILITY*FUNCTIONS************/
int compare(user s1, user s2)
{
	return strcmp(s1, s2);
}

void copy(user& dest, user source)
{
	dest = new char[strlen(source)];
	strcpy(dest, source);
}

void print(user inf)
{
	cout<<inf<<" ";
}

coda newQueue()
{
	coda c = {NULL, NULL};
	return c;
}

coda enqueue(coda c, nodo inf)
{
	elem* p = new elem;
	copy(p->inf,inf); 
	p->pun = NULL; 
	
	if(c.tail != NULL) 
		c.tail->pun = p;
	
	c.tail = p;
 	
	if(c.head == NULL)
		c.head = c.tail; 
	return c;
}

nodo dequeue(coda& c)
{
	lista tmp = c.head;
	user val;

	copy(val, c.head->inf);
	c.head = c.head->pun;

	delete tmp;
	return val;
}

void printQueue(coda c)
{
    user val = NULL;
	while(c.head != NULL)
    {
        copy(val,c.head->inf);
		print(val);
        c.head = c.head->pun;
	}
    cout<<endl;
}

bool isEmpty(coda c)
{
	if(c.head == NULL)
		return true;
	return false;
}
/************************************/


