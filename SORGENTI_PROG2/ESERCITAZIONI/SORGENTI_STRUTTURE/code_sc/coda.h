/* PRIMA DELL'UTILIZZO RIDEFINIRE IL TIPO */
/* INCLUDERE L'HEADER DEL NUOVO TIPO */
typedef char* tipo_inf;

/**
 * @file coda.h
 * @author filippo
 * @brief header file "coda"
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
/************CODA************/
struct elem
{
	tipo_inf inf;
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
/*****************************************/

coda enqueue(coda c, tipo_inf inf);
tipo_inf dequeue(coda& c);
bool isEmpty(coda c);

void printQueue(coda c);
coda merge(coda c1, coda c2);
