/**
 * @file compito.cc
 * @author filippo
 * @brief gestione di un'Inverted Index
 * @version 0.1
 * @date 2022-09-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <fstream>
#include "parola.h"
#include "liste.h"

using namespace std;

/*****************PUNTO*1*****************/
/**
 * @brief carica un Inverted Index da file
 * 
 * @return parola* riorna l'Inverted Index caricato
 */
parola* load()
{
	ifstream file("inverted");
	int n_words = 0;	// dim_ii
    file >> n_words;

    parola* inv_idx = new parola[n_words]; // 3 parole
	//char word[80];
	//int n_doc = 0;

	for(int i = 0; i < n_words; i++) 
    {
        //file >> word;
        //file >> n_doc;

		//strcpy(inv_idx[i].p, word);
		//inv_idx[i].n_doc = n_doc;
		if(file.peek() == '\n')
			file.ignore();

		file.getline(inv_idx[i].p,80);
		file>>inv_idx[i].n_doc;
		
		inv_idx[i].l = NULL;
		for(int j = 0; j < inv_idx[i].n_doc; j++) // crea e alloca la posting list
        {
			int doc = 0;
			file >> doc;
			elem* toIns = new_elem(doc);
			inv_idx[i].l = insert_elem(inv_idx[i].l, toIns);
		}
	}
	file.close();
	return inv_idx;
}

/**
 * @brief stampa un Inverted Index
 * 
 * @param inv_idx Inverted Index
 * @param dim_ii numero di parole dell'Inverted Index
 */
void stampa(parola* inv_idx, int dim_ii)
{
	for(int i = 0; i < dim_ii; i++) 
	{
		cout<<inv_idx[i].p<<endl;
		cout<<inv_idx[i].n_doc<<" Documenti\n";
		lista l = inv_idx[i].l;
		while(l != NULL) 
		{
			cout<<head(l)<<" ";
			l = tail(l);
		}
        cout<<endl<<endl;
	}
}
/*****************************************/

/*****************PUNTO*2*****************/
/**
 * @brief 
 * 
 * @param inv_idx Inverted Index
 * @param fileName nome del file contentente un Inverted Index
 * @param dim_ii numero di parole dell'Inverted Index
 */
void update(parola*& inv_idx, char* fileName, int& dim_ii)
{
	ifstream file(fileName);
	int id = 0;
	file >> id;	// carica l'ID del documento

	while (file.good())
	{
		char word[80];
		file >> word;	// legge una parola dal documento

		int i = 0;
		bool trovato = false;
		while(i < dim_ii && !trovato) // controlla se la paraola è già presente nell'inv_idx
		{
			if(strcmp(word,inv_idx[i].p) == 0) // se la parola è già presente nell'inv_idx
			{
				inv_idx[i].l = insert_elem(inv_idx[i].l, new_elem(id));	// aggiunge l'ID del documento che la contiene alla posting list
				inv_idx[i].n_doc++;
				trovato = true;
			}
			i++;
		}

		if(!trovato) // se la parola non è  presente nell'inv_idx
		{
			dim_ii++;	// aggiorna la dimensione dell'inv_idx
			parola* tmp = new parola[dim_ii];	// crea un inv_idx di appoggio
			for(int i = 0; i < dim_ii-1; i++) 	// copia il contenuto del "vecchio" inv_idx
				tmp[i] = inv_idx[i];

			// aggiunge la nuova parola all'inv_idx
			strcpy(tmp[dim_ii-1].p, word);	
			tmp[dim_ii-1].n_doc = 1;
			tmp[dim_ii-1].l = NULL;
			tmp[dim_ii-1].l = insert_elem(tmp[dim_ii-1].l,new_elem(id));

			delete inv_idx;	// libera la memoria
			inv_idx = tmp;	
		}
	}
	file.close();
}
/*****************************************/

/*****************PUNTO*3*****************/
/**
 * @brief stampa l'elenco dei documento che contengono entrmabe le parole
 * 
 * @param inv_idx Inverted Index
 * @param word1 prima parola
 * @param word2 seconda parola
 * @param dim_ii numero di parole dell'Inverted Index
 */
void AND(parola* inv_idx, char* word1, char* word2,int dim_ii)
{
	lista pl_1 = NULL;
	lista pl_2 = NULL;

	for(int i = 0; i < dim_ii; i++) 
	{
		if(strcmp(inv_idx[i].p, word1) == 0) // se la parola word1 è presente nell'inv_idx
			pl_1 = inv_idx[i].l;	// ne copia la sua posting list

		if(strcmp(inv_idx[i].p, word2) == 0) // se la parola word2 è presente nell'inv_idx
			pl_2 = inv_idx[i].l; // ne copia la sua posting list
	}

	while(pl_2 != NULL) // scorre la posting list pl_2
	{
		if(search(pl_1, head(pl_2)) != NULL) // se il documento è presente in entrambe le posting list
			cout<<head(pl_2)<<" ";	// stampa l'ID del documento
		pl_2 = tail(pl_2);
	}
	cout<<endl;
}
/*****************************************/

int main()
{
    /*****************PUNTO*1*****************/
	cout<<"\nINVERTED INDEX\n";
    parola* inv_idx = load();
    ifstream file("inverted");

    int dim_ii = 0;
    file >> dim_ii;

    file.close();
    stampa(inv_idx,dim_ii);
    /*****************************************/

    /*****************PUNTO*1*****************/
	cout<<"\nESTENSIONE INVERTED INDEX\n";
	char fileName[256];
	cout<<"Inserisci il nome del file: ";
	cin >> fileName;
	update(inv_idx,fileName,dim_ii);
	cout<<"\nPOST UPDATE:\n";
  	stampa(inv_idx,dim_ii);
    /*****************************************/

    /*****************PUNTO*3*****************/
	cout<<"\nRICERCA IN AND\n";
	char word1[80];
  	char word2[80];
	
  	cout<<"Inserisci la prima parola: " ;
  	cin>>word1;
  	cout<<"Inserisci la secondo parola: ";
  	cin>>word2;

  	AND(inv_idx,word1,word2,dim_ii);
    /*****************************************/

	return 0;
}