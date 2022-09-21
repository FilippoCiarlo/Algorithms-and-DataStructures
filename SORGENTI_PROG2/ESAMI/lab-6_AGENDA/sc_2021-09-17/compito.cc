/**
 * @file compito.cc
 * @author filippo
 * @brief implementazione di un'agenda per gli appuntamenti
 * @version 0.1
 * @date 2022-09-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
#include "tipo.h"
#include "liste.h"

using namespace std;

/*****************PUNTO*1*****************/
/**
 * @brief aggiunge un appunntamento all'agenda
 * 
 * @param agenda (riorna) lista degli appuntamenti
 * @param a appuntamento
 */
void agenda(lista& agenda, tipo_inf a)
{
	if(search(agenda, a) != NULL)
	{
		cout<<"Impossibile inserire: ";
		print(a);
	}
	else
		agenda = insert_elem(agenda, new_elem(a));
}

/**
 * @brief stampa il contenuto dell'agenda
 * 
 * @param agenda lista degli appuntamenti
 */
void stampa(lista agenda) 
{
	while (agenda != NULL) 
	{
		print(head(agenda));
		agenda = tail(agenda);
	}
}
/*****************************************/

/*****************PUNTO*2*****************/
/**
 * @brief stampa il numero di appuntamenti presenti prima e dono un dato appuntamento
 * 
 * @param l lista degli appuntamenti
 * @param i appuntamento
 */
void quanti(lista l, tipo_inf i){
	int prima = 0;
	int dopo = 0;

	while(l != NULL)
	{
		if(strcmp(head(l).data, i.data) == 0)
		{
			if(strcmp(head(l).ora_i,i.ora_f) > 0)
				dopo++;
			else if(strcmp(head(l).ora_i,i.ora_f) < 0)
				prima++;
		}
		l = tail(l);
	}

	cout<<prima<<" appuntamenti prima"<<endl;
	cout<<dopo<<" appuntamenti dopo"<<endl;
}
/*****************************************/

int main()
{
	/*****************PUNTO*1*****************/
	cout<<"\nAGENDA\n";
	ifstream file("agenda.txt");

	lista l = NULL;
	tipo_inf t;

	while (file >> t.data >> t.ora_i >> t.ora_f)
	{
		file.ignore();
		file.getline(t.descr, 51);
		agenda(l,t);
	}

	stampa(l);
	/*****************************************/

	/*****************PUNTO*2*****************/
	cout<<"\nINSERIRIMENTO DI UN APPUNTAMENTO";
	cout<<"\nInserire: Data[ggmmaa] - Ora Inizio[hhmm] - Ora Fine[hhmm]: ";
	cin>>t.data >> t.ora_i >> t.ora_f;

	cout<<"Inserire una breve descrizione: ";
	cin>>t.descr;
	
	quanti(l, t);
	/*****************************************/

    return 0;
}