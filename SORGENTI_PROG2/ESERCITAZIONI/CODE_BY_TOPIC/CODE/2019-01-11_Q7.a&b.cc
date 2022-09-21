#include <iostream>

using namespace std;

typedef char* user;

/************QUEUE***********/
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
/****************************/

/************UTILITY*FUNCTIONS************/
int compare(char* s1, char* s2);
void copy(char*& dest, char* source);
void print(char* s);

coda enqueue(coda c, user inf);
user dequeue(coda& c);
/*****************************************/

/***********SECONDARY*FUNCTIONS***********/
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
/*****************************************/

/**************MERGE*FUNCTION*************/
coda merge(coda c1, coda c2)
{
	coda c3;
	c3.head = c3.tail = NULL; 
	
	if(isEmpty(c1) || isEmpty(c2))
		return c3;

	user curr_c1 = dequeue(c1); 
	user curr_c2 = dequeue(c2); 
	
	bool stop_c1 = false; 
	bool stop_c2 = false; 	

	while(!stop_c1 && !stop_c2)
    { 
		if(strcmp(curr_c1,curr_c2) < 0)
        { 
			c3 = enqueue(c3,curr_c1); 
			if(!isEmpty(c1)) 
 				curr_c1 = dequeue(c1); 
			else
				stop_c1 = true; 
	    }
        else
        { 
			c3 = enqueue(c3,curr_c2); 
			if(!isEmpty(c2)) 
				curr_c2 = dequeue(c2); 
			else 
				stop_c2 = true; 
		}
	}
	
	if(!stop_c1)
    { 
		c3 = enqueue(c3,curr_c1); 
		while(!isEmpty(c1)) 
			c3 = enqueue(c3,dequeue(c1)); 
	}

	if(!stop_c2)
    { 
		c3 = enqueue(c3,curr_c2); 
		while(!isEmpty(c2)) 
			c3 = enqueue(c3,dequeue(c2)); 
	}

	return c3;
}
/*****************************************/

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

coda enqueue(coda c, user inf)
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

user dequeue(coda& c)
{
	lista tmp = c.head;
	user val;

	copy(val, c.head->inf);
	c.head = c.head->pun;

	delete tmp;
	return val;
}
/************************************/


